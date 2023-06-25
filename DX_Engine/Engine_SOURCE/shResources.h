#pragma once
#include "shResource.h"
#include "shTexture.h"
#include "shShader.h"

namespace sh
{
	class Resources
	{
	public:
		template <typename T>
		static std::shared_ptr<T> Find(const std::wstring& key)
		{
			//���ҽ��ʿ��� �����͸� Ž���Ѵ� �����Ͱ� �ִٸ� �ش絥���͸� ��ȯ�ϰ�
			//�����Ͱ� ���ٸ� end�� ��ȯ���ش�.
			std::map<std::wstring, std::shared_ptr<Resource>>::iterator iter = mResources.find(key);

			//ã���� �ϴ� �����Ͱ� �����Ѵٸ�
			//�ش�Ÿ������ ����ȯ�Ͽ� ��ȯ
			if (iter != mResources.end())
			{
				return std::dynamic_pointer_cast<T>(iter->second);
			}

			//������ ���ٸ� ���� ��ȯ
			return nullptr;
		}

		template <typename T>
		static std::shared_ptr<T> Load(const std::wstring& key, const std::wstring& path)
		{
			// Ű������ Ž��
			std::shared_ptr<T> resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}

			// �ش� ���ҽ��� ���ٸ�
			resource = std::make_shared<T>();
			if (FAILED(resource->Load(path)))
			{
				assert(false);
				return nullptr;
			}

			resource->SetKey(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return std::dynamic_pointer_cast<T>(resource);
		}

		template <typename T>
		static void Insert(const std::wstring& key, std::shared_ptr<T> resource)
		{
			mResources.insert(std::make_pair(key, resource));
		}

		static void MakeMaterial(std::shared_ptr<Texture> texture, std::shared_ptr<Shader> shader, std::wstring Material_name)
		{
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(shader);
			spriteMateiral->SetTexture(texture);
			Resources::Insert(Material_name, spriteMateiral);
		}

	private:
		static std::map<std::wstring, std::shared_ptr<Resource>> mResources;
	};
}

