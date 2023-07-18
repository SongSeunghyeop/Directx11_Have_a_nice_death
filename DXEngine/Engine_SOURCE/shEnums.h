#pragma once


namespace sh::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Particle,
		MeshRenderer,
		Script,
		MAINCamera,
		UICamera
	};

	enum class eLayerType
	{
		BackGround,
		Structure_B,
		Ground,
		Monster,
		Player,
		Structure_F,
		UI,
		Camera,
		None,
		End,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};
}