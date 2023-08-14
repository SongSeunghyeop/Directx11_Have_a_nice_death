#pragma once
#include "shEntity.h"
#include "shComponent.h"
#include "shScript.h"

namespace sh
{
	class GameObject : public Entity
	{
	public:
		enum class eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		template <typename T>
		T* GetComponent()
		{
			T* component;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component != nullptr)
					return component;
			}

			for (Script* script : mScripts)
			{
				component = dynamic_cast<T*>(script);
				if (component != nullptr)
					return component;
			}

			return nullptr;
		}

		template <typename T>
		const std::vector<T*> GetComponents()
		{
			std::vector<T*> comps;

			T* component;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component != nullptr)
					comps.push_back(component);
			}

			for (Script* script : mScripts)
			{
				component = dynamic_cast<T*>(script);
				if (component != nullptr)
					comps.push_back(component);
			}

			return comps;
		}

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			
			Component* buff
				= dynamic_cast<Component*>(comp);
			Script* script
				= dynamic_cast<Script*>(buff);

			if (buff == nullptr)
				return nullptr;

			if (script == nullptr)
				mComponents.push_back(buff);
			else
				mScripts.push_back(script);
			
			comp->SetOwner(this);
			comp->Initialize();
			return comp;
		}

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }

		void setLayerType(enums::eLayerType type)
		{
			layerType = type;
		}
		enums::eLayerType getLayerType()
		{
			return layerType;
		}
		Vector2 GetDrainage()
		{
			return Drainage;
		}
		void SetDrainage(Vector2 v)
		{
			Drainage = v;
		}

		void SetMaterialName(std::wstring m)
		{
			MaterialName = m;
		}

		std::wstring GetMaterialName()
		{
			return MaterialName;
		}

		virtual void OnCollisionEnter(Collider2D* other);
		virtual void OnCollisionStay(Collider2D* other);
		virtual void OnCollisionExit(Collider2D* other);
	private:
		eState mState;
		std::vector<Component*> mComponents;
		std::vector<Script*> mScripts;
		enums::eLayerType layerType;
		Vector2 Drainage;
		std::wstring MaterialName;
	};
}
