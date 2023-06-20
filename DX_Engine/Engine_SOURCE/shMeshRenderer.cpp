#include "shMeshRenderer.h"
#include "shGameObject.h"
#include "shTransform.h"
#include "shRenderer.h"

namespace sh
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
	{
	}
	MeshRenderer::~MeshRenderer()
	{
}
	void MeshRenderer::Initialize()
	{
	}
	void MeshRenderer::Update()
	{
	}
	void MeshRenderer::LateUpdate()
	{
	}
	void MeshRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		//상수 버퍼는 모든 정점들의 정보를 한번에 바꿔야 할때 유용하다
		//정점들의 위치가 바뀌는 경우는 두가지가 있다.
		//모든 정점의 위치가 동일한 방향으로 바뀌는 경우 (== 캐릭터 이동)
		//이때는 상수버퍼를 활용하는게 좋다'
		//그러나 정점 각각의 위치 이동을 따로 적용해야 하는 경우(ex 캐릭터 모양, 크기 변환(애니메이션 등))
		//이럴때는 정점 버퍼에서 위치 정보를 바꿔주는게 맞다.

		//상수버퍼나 정점 버퍼, 쉐이더를 매번 바인딩 해주는 이유는 
		//위와 같이 캐릭터의 위치가 변하거나 캐릭터의 애니메이션으로 인해 크기나 모양
		//게임 도중 실시간으로 바뀔 수 있기 때문이다.

		tr->BindConstantBuffer();
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();

		GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
