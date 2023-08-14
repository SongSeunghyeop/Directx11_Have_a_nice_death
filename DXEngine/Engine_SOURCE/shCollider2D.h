#pragma once
#include "shComponent.h"
#include "shTransform.h"


namespace sh
{
	class Collider2D : public Component
	{
	public:
		Collider2D();
		~Collider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void OnCollisionEnter(Collider2D* other);
		void OnCollisionStay(Collider2D* other);
		void OnCollisionExit(Collider2D* other);

		void SetType(eColliderType type) { mType = type; }
		Vector2 GetSize() { return mSize; }
		Vector3 GetScale() { return mScale; }
		void SetSize(Vector2 size) { mSize = size; }
		void SetCenter(Vector2 size) { mCenter = size; }
		Vector2 GetCenter() { return mCenter; }
		UINT GetColliderID() { return mColliderID; }
		
		Vector3 GetPosition()
		{
			return mPosition;
		}

		void SetPosition(Vector3 pos)
		{
			mPosition = pos;
		}

		std::wstring GetColliderName()
		{
			return ColliderName;
		}

		void SetColliderName(std::wstring Name)
		{
			ColliderName = Name;
		}
	private:
		static UINT mColliderNumber;
		UINT mColliderID;
		eColliderType mType;
		Transform* mTransform;

		Vector3 mPosition;
		Vector2 mSize;
		Vector3 mScale;
		Vector2 mCenter;

		std::wstring ColliderName;
	};
}
