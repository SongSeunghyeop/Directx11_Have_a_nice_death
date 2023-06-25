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
			//리소스맵에서 데이터를 탐색한다 데이터가 있다면 해당데이터를 반환하고
			//데이터가 없다면 end를 반환해준다.
			std::map<std::wstring, std::shared_ptr<Resource>>::iterator iter = mResources.find(key);

			//찾고자 하는 데이터가 존재한다면
			//해당타입으로 형변환하여 반환
			if (iter != mResources.end())
			{
				return std::dynamic_pointer_cast<T>(iter->second);
			}

			//데이터 없다면 널을 반환
			return nullptr;
		}

		template <typename T>
		static std::shared_ptr<T> Load(const std::wstring& key, const std::wstring& path)
		{
			// 키값으로 탐색
			std::shared_ptr<T> resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}

			// 해당 리소스가 없다면
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

