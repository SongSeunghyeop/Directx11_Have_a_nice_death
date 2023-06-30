#pragma once


namespace sh::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Camera,
		Player,
		Monster,
		UI,
		Structure, //����, �ǹ�
		BackGround,
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
}