#pragma once
#include "shCollisionManager.h"

namespace sh
{
	class Player;

	class FootHold : public GameObject
	{
	public:
		FootHold();
		~FootHold();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnCollisionEnter(Collider2D* other) ;
		virtual void OnCollisionStay(Collider2D* other);
		virtual void OnCollisionExit(Collider2D* other);

		void SetPlayer(Player  *p)
		{
			player = p;
		}
	private:
		Player* player;
	};
}