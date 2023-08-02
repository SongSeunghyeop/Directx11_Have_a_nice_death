#pragma once
#include "shComponent.h"
#include "shAnimation.h"

namespace sh
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		struct AnimationINFO
		{
			std::wstring path;
			std::vector<math::Vector2> texSizes;
			
			float duration;
		};

		Animator();
		~Animator();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void Create(const std::wstring& name
			, std::shared_ptr<graphics::Texture> atlas
			, Vector2 leftTop
			, Vector2 size
			, UINT columnLength
			, float duration = 0.1f
			, Vector2 offset = Vector2::Zero
			, int direction = 0);

		Animation* CreateAnimations();
		Animation* FindAnimation(const std::wstring& name);
		Events* FindEvents(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop);
		void Binds();
		Animation* GetActiveAnimation()
		{
			return mActiveAnimation;
		}

		std::function<void()>& StartEvent(const std::wstring key);
		std::function<void()>& CompleteEvent(const std::wstring key);
		std::function<void()>& EndEvent(const std::wstring key);

		//애니메이션을 배열에 추가하고, maxSize값을 미리 구해놓는다

		void SetAnimations(const std::wstring path, float duration = 0.06f);
	private:
		std::map<std::wstring, Animation*> mAnimations;
		std::map<std::wstring, Events*> mEvents;
		Animation* mActiveAnimation;
		std::shared_ptr<graphics::Texture> mImageAtlas;

		bool mbLoop;
		Vector2 maxSize = Vector2(0,0);

		//std::vector<std::wstring> pathes;
		std::vector<AnimationINFO *> informations;

		int Direction; // 0 = Right // 1 = Left
	};
}
