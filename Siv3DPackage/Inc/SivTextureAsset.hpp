//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# pragma once
# include "SivAsset.hpp"
# include "SivTexture.hpp"

namespace s3d
{
	class TextureAsset : public Texture
	{
	public:

		TextureAsset(const AssetName& name);

		static bool Register(const AssetName& name, const FilePath& path, const std::vector<AssetTag>& tags = {}, int flag = AssetFlag::Default);

		static bool Register(const AssetName& name, const FilePath& path, bool mipped, const std::vector<AssetTag>& tags = {}, int flag = AssetFlag::Default);

		static bool IsRegistered(const AssetName& name);

		static bool Preload(const AssetName& name);

		static bool PreloadByTag(const std::vector<AssetTag>& tags);

		static bool PreloadAll();

		static void Release(const AssetName& name);

		static void ReleaseByTag(const std::vector<AssetTag>& tags);

		static void ReleaseAll();

		static void Unregister(const AssetName& name);

		static void UnregisterByTag(const std::vector<AssetTag>& tags);

		static void UnregisterAll();
	};
}
