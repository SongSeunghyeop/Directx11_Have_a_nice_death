#pragma once


namespace sh::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Rigidbody,
		MeshRenderer,
		Animator,
		Script,
		Light,
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
		Ground_Fill,
		Light,
		Structure_F,
		NPC,
		UI,
		Camera,
		End = 16,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		ComputeShader,
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

	enum class eLightType
	{
		Directional,
		Point,
		Spot,
		End,
	};
}