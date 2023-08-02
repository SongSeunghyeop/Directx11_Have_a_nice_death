#include "shAnimator.h"
#include "shResources.h"

namespace sh
{
	Animator::Animator()
		: Component(eComponentType::Animator)
	{
	}
	Animator::~Animator()
	{
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}
		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
		for (auto& iter : informations)
		{
			delete iter;
			iter = nullptr;
		}
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation == nullptr)
			return;

		if (mActiveAnimation->IsComplete() && mbLoop)
		{
			Events* events
				= FindEvents(mActiveAnimation->GetKey());
			if (events)
				events->completeEvent();

			mActiveAnimation->Reset();
		}

		mActiveAnimation->LateUpdate();
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render()
	{

	}

	void Animator::Create(const std::wstring& name
		, std::shared_ptr<graphics::Texture> atlas
		, Vector2 leftTop
		, Vector2 size
		, UINT columnLength
		, float duration
		, Vector2 offset
		, int direction)
	{
		Animation* animation = FindAnimation(name);
		if (nullptr != animation)
			return;

		animation = new Animation();
		animation->SetKey(name);

		animation->Create(name
			, atlas
			, leftTop
			, size
			, columnLength
			, offset
			, duration
			, direction);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = FindEvents(name);
		if (events != nullptr)
			return;

		events = new Events();
		mEvents.insert(std::make_pair(name, events));
	}

	//애니메이션 배열 안에 있는 정보들과 , 최종 maxSize를 토대로 아틀라스를 생성한다
	Animation* Animator::CreateAnimations()
	{
		for (int i = 0; i < informations.size(); i++)
		{
			std::filesystem::path fs(informations[i]->path);
			std::vector<std::shared_ptr<Texture>> textures = {};

			std::wstring keyR = fs.parent_path().filename();
			keyR += fs.filename();
			keyR += +L"R";

			std::wstring keyL = fs.parent_path().filename();
			keyL += fs.filename();
			keyL += +L"L";

			mImageAtlas = std::make_shared<graphics::Texture>();
			mImageAtlas->CreateTex(informations[i]->path, informations[i]->texSizes.size(), maxSize.x, maxSize.y, informations[i]->texSizes);

			//오른쪽 방향 아틀라스
			Create(keyR, mImageAtlas, Vector2(0.0), Vector2(maxSize.x, maxSize.y), informations[i]->texSizes.size(), informations[i]->duration, Vector2::Zero, 0);
			//왼쪽 방향 아틀라스
			Create(keyL, mImageAtlas, Vector2(0.0), Vector2(maxSize.x, maxSize.y), informations[i]->texSizes.size(), informations[i]->duration, Vector2::Zero, 1);
		}
			return nullptr;
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter
			= mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		std::map<std::wstring, Events*>::iterator iter
			= mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* prevAnimation = mActiveAnimation;

		Events* events;
		if (prevAnimation != nullptr)
		{
			events = FindEvents(prevAnimation->GetKey());
			if (events)
				events->endEvent();
		}

		Animation* animation = FindAnimation(name);
		if (animation)
		{
			mActiveAnimation = animation;
		}

		events = FindEvents(mActiveAnimation->GetKey());
		if (events)
			events->startEvent();

		mbLoop = loop;
		mActiveAnimation->Reset();
	}
	void Animator::Binds()
	{
		if (mActiveAnimation == nullptr)
			return;

		mActiveAnimation->Binds();
	}
	std::function<void()>& Animator::StartEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->startEvent.mEvent;
	}

	std::function<void()>& Animator::CompleteEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->completeEvent.mEvent;
	}

	std::function<void()>& Animator::EndEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->endEvent.mEvent;
	}
	//maxSize 값을 정하고, 애니메이션의 정보를 배열에 넣는다
	void Animator::SetAnimations(const std::wstring path, float duration)
	{
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<std::shared_ptr<Texture>> textures = {};
		std::vector<math::Vector2> texSizes;

		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path().wstring(); // Use the full path from the iterator

			std::shared_ptr<Texture> tex = Resources::Load<Texture>(fileName, fullName);

			if (maxSize.x < tex->GetWidth())
			{
				maxSize.x = tex->GetWidth();
			}
			if (maxSize.y < tex->GetHeight())
			{
				maxSize.y = tex->GetHeight();
			}

			textures.push_back(tex);
			Vector2 size = Vector2(tex->GetWidth(), tex->GetHeight());
			texSizes.push_back(size);
			fileCount++;
		}

			AnimationINFO* info = new AnimationINFO();
			info->path = path;
			info->duration = duration;
			info->texSizes = texSizes;

			informations.push_back(info);
	}
}
