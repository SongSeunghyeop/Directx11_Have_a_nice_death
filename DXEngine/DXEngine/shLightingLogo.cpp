#include "shLightingLogo.h"
#include "shTransform.h"
#include "shLight.h"
namespace sh
{
	LightingLogo::LightingLogo()
	{

	}
	LightingLogo::~LightingLogo()
	{

	}
	void LightingLogo::Initialize()
	{
		Light* lightComp = this->AddComponent<Light>();
		lightComp->SetType(eLightType::Point);
		lightComp->SetColor(Vector4(169, 245, 225,  1.0f));
		lightComp->SetRadius(4.0f);

		GameObject::Initialize();
	}
	void LightingLogo::Update()
	{
		GameObject::Update();
	}
	void LightingLogo::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void LightingLogo::Render()
	{
		GameObject::Render();
	}
}