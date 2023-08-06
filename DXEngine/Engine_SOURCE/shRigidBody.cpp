#include "shRigidbody.h"
#include "shTime.h"
#include "shGameObject.h"
#include "shTransform.h"

namespace sh
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mForce(Vector3(0.0f,0.0f,0.0f))
		, mAccelation(Vector3::Zero)
		, mVelocity(Vector3::Zero)
	{
		mLimitedVelocity.x = 200.0f;
		mLimitedVelocity.y = 120.0f;
		mbGround = false;
		mGravity = Vector3(0.0f, -90.0f, 0.0f);
	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Initialize()
	{

	}

	void Rigidbody::Update()
	{
		// F = M * A
		// A = M / F

		if (mForce.y > 0)
		{
			int a = 0;
		}

		mAccelation = mForce / mMass;

		// 속도에 가속도를 더해준다.
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// 땅위에 있을때
			Vector3 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);
			mVelocity -= gravity * dot;
			mVelocity.x = 0;
		}
		else
		{
			mVelocity += mGravity * Time::DeltaTime();
		}

		// 중력가속도 최대 속도 제한
		Vector3 gravity = mGravity;
		gravity.Normalize();
		float dot = mVelocity.Dot(gravity);
		gravity = gravity * dot;

		Vector3 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y <  gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
		//

		// 속도에 맞게끔 물체를 이동시킨다.
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		pos.x += mVelocity.x * 0.01f;
		pos.y += mVelocity.y * 0.01f;;
		tr->SetPosition(pos);
		
		mForce.x = 0.0f;
		mForce.y = 0.0f;
		mForce.z = 0.0f;
	}

	void Rigidbody::LateUpdate()
	{

	}
	void Rigidbody::Render()
	{
	}

	void Rigidbody::AddForce(Vector3 force)
	{
		mForce += force;
	}
}
