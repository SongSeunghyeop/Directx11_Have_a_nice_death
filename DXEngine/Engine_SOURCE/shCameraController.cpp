#include "shCameraController.h"
#include "shTransform.h"
#include "shGameObject.h"
#include "shApplication.h"
#include "shRenderer.h"
#include "shScene.h"
#include "shSceneManager.h"
#include "shMeshRenderer.h"

extern sh::Application application;

namespace sh
{
	bool CompareZSort(GameObject* a, GameObject* b)
	{
		if (a->GetComponent<Transform>()->GetPosition().z
			<= b->GetComponent<Transform>()->GetPosition().z)
			return false;

		return true;
	}
	Matrix CameraController::View = Matrix::Identity;
	Matrix CameraController::Projection = Matrix::Identity;

	CameraController::CameraController()
		: Component(cameraType)
		, mType(eProjectionType::OrthoGraphic)
		, mAspectRatio(1.0f)
		, mNear(1.0f)
		, mFar(1000.0f)
		, mSize(1.0f)
		, mLayerMask{}
		, mOpaqueGameObjects{}
		, mCutOutGameObjects{}
		, mTransparentGameObjects{}
		, mView(Matrix::Identity)
		, mProjection(Matrix::Identity)
	{
		DisableLayerMasks();
	}

	CameraController::~CameraController()
	{
	}

	void CameraController::Initialize()
	{

	}

	void CameraController::Update()
	{

	}

	void CameraController::LateUpdate()
	{
		//카메라는 반대로 움직이므로
		CreateViewMatrix();
		CreateProjectionMatrix(mType);
		RegisterCameraInRenderer();
	}

	void CameraController::Render()
	{
		View = mView;
		Projection = mProjection;

		AlphaSortGameObjects();
		ZSortTransparencyGameObjects();
		
		RenderOpaque();
		DisableDepthStencilState();

		RenderCutOut();
		RenderTransparent();
		EnableDepthStencilState();
	}

	bool CameraController::CreateViewMatrix()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		// View Translate Matrix
		// 카메라는 모든 오브젝트와 반대로 움직임
		mView = Matrix::Identity;
		mView *= Matrix::CreateTranslation(-pos);

		// View Rotation Matrix
		Vector3 up = tr->Up();
		Vector3 right = tr->Right();
		Vector3 foward = tr->Foward();

		Matrix viewRotate;
		viewRotate._11 = right.x;	viewRotate._12 = up.x;	viewRotate._13 = foward.x;
		viewRotate._21 = right.y;	viewRotate._22 = up.y;	viewRotate._23 = foward.y;
		viewRotate._31 = right.z;	viewRotate._32 = up.z;	viewRotate._33 = foward.z;
		mView *= viewRotate;

		return true;
	}

	bool CameraController::CreateProjectionMatrix(eProjectionType type)
	{
		//투영 행열을 세팅한다
		RECT rect = {};
		GetClientRect(application.GetHwnd(), &rect);
		float width = rect.right - rect.left;
		float height = rect.bottom - rect.top;
		mAspectRatio = width / height;;

		if (type == eProjectionType::OrthoGraphic)
		{
			//원근법 적용
			float OrthorGraphicRatio = mSize / 1000.0f;
			width *= OrthorGraphicRatio;
			height *= OrthorGraphicRatio;

			mProjection = Matrix::CreateOrthographicLH(width, height, mNear, mFar);
		}
		else
		{
			mProjection = Matrix::CreatePerspectiveFieldOfViewLH(XM_2PI / 6.0f, mAspectRatio, mNear, mFar);
		}


		return true;
	}

	void CameraController::RegisterCameraInRenderer()
	{
		renderer::cameras.push_back(this);
	}

	void CameraController::TurnLayerMask(eLayerType type, bool enable)
	{
		mLayerMask.set((UINT)type, enable);
	}


	void CameraController::AlphaSortGameObjects()
	{
		mOpaqueGameObjects.clear();
		mCutOutGameObjects.clear();
		mTransparentGameObjects.clear();

		//alpha sorting
		Scene* scene = SceneManager::GetActiveScene();
		for (size_t i = 0; i < (UINT)eLayerType::End; i++)
		{
			if (mLayerMask[i] == true)
			{
				Layer& layer = scene->GetLayer((eLayerType)i);
				const std::vector<GameObject*> gameObjs
					= layer.GetGameObjects();
				// layer에 있는 게임오브젝트를 들고온다.

				DivideAlphaBlendGameObjects(gameObjs);
			}
		}
	}

	void CameraController::ZSortTransparencyGameObjects()
	{
		std::sort(mCutOutGameObjects.begin()
			, mCutOutGameObjects.end()
			, CompareZSort);
		std::sort(mTransparentGameObjects.begin()
			, mTransparentGameObjects.end()
			, CompareZSort);
	}

	void CameraController::DivideAlphaBlendGameObjects(const std::vector<GameObject*> gameObjs)
	{
		for (GameObject* obj : gameObjs)
		{
			//렌더러 컴포넌트가 없다면?
			MeshRenderer* mr
				= obj->GetComponent<MeshRenderer>();
			if (mr == nullptr)
				continue;

			std::shared_ptr<Material> mt = mr->GetMaterial();
			eRenderingMode mode = mt->GetRenderingMode();
			switch (mode)
			{
			case sh::graphics::eRenderingMode::Opaque:
				mOpaqueGameObjects.push_back(obj);
				break;
			case sh::graphics::eRenderingMode::CutOut:
				mCutOutGameObjects.push_back(obj);
				break;
			case sh::graphics::eRenderingMode::Transparent:
				mTransparentGameObjects.push_back(obj);
				break;
			default:
				break;
			}
		}
	}

	void CameraController::RenderOpaque()
	{
		for (GameObject* gameObj : mOpaqueGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}

	void CameraController::RenderCutOut()
	{
		for (GameObject* gameObj : mCutOutGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}

	void CameraController::RenderTransparent()
	{
		for (GameObject* gameObj : mTransparentGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}

	void CameraController::EnableDepthStencilState()
	{
		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> dsState
			= renderer::depthStencilStates[(UINT)eDSType::Less];
		GetDevice()->BindDepthStencilState(dsState.Get());
	}

	void CameraController::DisableDepthStencilState()
	{
		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> dsState
			= renderer::depthStencilStates[(UINT)eDSType::None];
		GetDevice()->BindDepthStencilState(dsState.Get());
	}
}