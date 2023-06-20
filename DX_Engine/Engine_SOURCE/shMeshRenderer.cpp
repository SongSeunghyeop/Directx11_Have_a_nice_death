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

		//��� ���۴� ��� �������� ������ �ѹ��� �ٲ�� �Ҷ� �����ϴ�
		//�������� ��ġ�� �ٲ�� ���� �ΰ����� �ִ�.
		//��� ������ ��ġ�� ������ �������� �ٲ�� ��� (== ĳ���� �̵�)
		//�̶��� ������۸� Ȱ���ϴ°� ����'
		//�׷��� ���� ������ ��ġ �̵��� ���� �����ؾ� �ϴ� ���(ex ĳ���� ���, ũ�� ��ȯ(�ִϸ��̼� ��))
		//�̷����� ���� ���ۿ��� ��ġ ������ �ٲ��ִ°� �´�.

		//������۳� ���� ����, ���̴��� �Ź� ���ε� ���ִ� ������ 
		//���� ���� ĳ������ ��ġ�� ���ϰų� ĳ������ �ִϸ��̼����� ���� ũ�⳪ ���
		//���� ���� �ǽð����� �ٲ� �� �ֱ� �����̴�.

		tr->BindConstantBuffer();
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();

		GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
