#include "shEntity.h"


namespace sh
{
	Entity::Entity()
		: mName(L"")
		, mColliderID((UINT64)this)
	{

	}

	Entity::~Entity()
	{
	}

}
