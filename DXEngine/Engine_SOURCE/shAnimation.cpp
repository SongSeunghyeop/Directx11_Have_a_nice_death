#include "shAnimation.h"
#include "shTime.h"
#include "shAnimator.h"
#include "shRenderer.h"
#include "shConstantBuffer.h"

namespace sh
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAtlas(nullptr)
		, mAnimator(nullptr)
		, mSprites{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{

	}

	Animation::~Animation()
	{
	}

	void Animation::Update()
	{
	}
	void Animation::LateUpdate()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mSprites[mIndex].duration <= mTime)
		{
			mIndex++;
			mTime = 0.0f;

			if (mSprites.size() <= mIndex)
			{
				mIndex = mSprites.size() - 1;
				mbComplete = true;
			}
		}
	}
	void Animation::Render()
	{

	}
	void Animation::Create(std::wstring name, std::shared_ptr<Texture> atlas, Vector2 leftTop, Vector2 size, UINT columnLength, Vector2 offset, float duration, int direction)
	{
		SetKey(name);
		mAtlas = atlas;

		float width = (float)atlas->GetWidth();
		float height = (float)atlas->GetHeight();

		if (direction == 0) // ¿À¸¥ÂÊ
		{
			for (size_t i = 0; i < columnLength; i++)
			{
				Sprite sprite = {};
				sprite.leftTop.x = leftTop.x + (i * size.x);
				sprite.leftTop.y = leftTop.y;
				sprite.size = size;
				sprite.offset = offset;
				sprite.atlasSize = Vector2(width, height);
				sprite.duration = duration;

				mSprites.push_back(sprite);
			}
		}
		if (direction == 1) // ¿ÞÂÊ 
		{
			for (size_t i = 0; i < columnLength; i++)
			{
				Sprite sprite = {};
				sprite.leftTop.x = leftTop.x + (i * size.x);
				sprite.leftTop.y = leftTop.y;
				sprite.size = size;
				sprite.offset = offset;
				sprite.atlasSize = Vector2(width, height);
				sprite.duration = duration;

				mSprites.insert(mSprites.begin(), sprite);
			}
		}
	}


	void Animation::Binds()
	{
		// texture bind
		mAtlas->BindShaderResource(graphics::eShaderStage::PS, 12);

		// AnimationCB
		renderer::AnimatorCB data = {};

		data.spriteLeftTop = mSprites[mIndex].leftTop;
		data.spriteSize = mSprites[mIndex].size;
		data.spriteOffset = mSprites[mIndex].offset;
		data.atlasSize = mSprites[mIndex].atlasSize;
		data.animationType = 1;

		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Animator];
		cb->SetData(&data);

		cb->Bind(eShaderStage::VS);
		cb->Bind(eShaderStage::PS);
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mbComplete = false;
		mIndex = 0;
	}
}