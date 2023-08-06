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
		mLimitedVelocity.y = 150.0f;
		mbGround = false;
		mGravity = Vector3(0.0f, -52.0f, 0.0f);
		mFriction = 50.0f;
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
		mAccelation = mForce / mMass;

		// �ӵ��� ���ӵ��� �����ش�.
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// ������ ������
			Vector3 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * Time::DeltaTime();
		}

		// �߷°��ӵ� �ִ� �ӵ� ����
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

		// ������ ���� ( ����� ���� ����, �ӵ��� 0�� �ƴ�)
		if (!(mVelocity == Vector3::Zero))
		{
			//�ӵ��� �ݴ�������� �������� ����ȴ�.
			Vector3 friction = -mVelocity;
			friction.Normalize();
			
			friction*= mFriction* mMass* Time::DeltaTime();

			//���������� ���� �ӵ� ���Ҵ� ���� �ӵ����� ū ���

			if (mVelocity.Length() < friction.Length())
			{
				mVelocity = Vector3::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}
		//

		// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
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
