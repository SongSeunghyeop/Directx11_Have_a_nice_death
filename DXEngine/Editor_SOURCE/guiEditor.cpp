#include "guiEditor.h"
#include "..\\Engine_SOURCE\\shMesh.h"
#include "..\\Engine_SOURCE\\shMesh.h"
#include "..\\Engine_SOURCE\\shResources.h"
#include "..\\Engine_SOURCE\\shTransform.h"
#include "..\\Engine_SOURCE\\shMeshRenderer.h"
#include "..\\Engine_SOURCE\\shMaterial.h"
#include "..\\Engine_SOURCE\\shRenderer.h"

namespace gui
{
	using namespace sh::enums;
	std::vector<guiWidget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<sh::Mesh> mesh
			= sh::Resources::Find<sh::Mesh>(L"DebugRect");
		std::shared_ptr<sh::Material> material
			= sh::Resources::Find<sh::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<sh::Transform>();
		sh::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<sh::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);
	}
	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Editor::Update()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}
	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}
	void Editor::Render()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const sh::graphics::DebugMesh& mesh
			: renderer::debugMeshs)
		{
			DebugRender(mesh);
		}
		renderer::debugMeshs.clear();
	}
	void Editor::Release()
	{
		for (auto widget : mWidgets)
		{
			delete widget;
			widget = nullptr;
		}

		for (auto editorObj : mEditorObjects)
		{
			delete editorObj;
			editorObj = nullptr;
		}

		for (auto debugObj : mDebugObjects)
		{
			delete debugObj;
			debugObj = nullptr;
		}

	}

	void Editor::DebugRender(const sh::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// 위치 크기 회전 정보를 받아와서
		// 해당 게임오브젝트위에 그려주면된다.
		sh::Transform* tr = debugObj->GetComponent<sh::Transform>();

		Vector3 pos = mesh.position;
		pos.z -= 0.01f;

		tr->SetPosition(pos);
		tr->SetScale(mesh.scale);
		tr->SetRotation(mesh.rotation);

		tr->LateUpdate();

		sh::CameraController* mainCamara = renderer::mainCamera;
		sh::CameraController::SetGpuViewMatrix(mainCamara->GetViewMatrix());
		sh::CameraController::SetGpuProjectionMatrix(mainCamara->GetProjectionMatrix());

		debugObj->Render();
	}
}
