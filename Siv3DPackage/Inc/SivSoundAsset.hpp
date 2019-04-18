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
# include "SivSound.hpp"

namespace s3d
{
	class SoundAsset : public Sound
	{
	public:

		SoundAsset(const AssetName& name);

		static bool Register(const AssetName& name, const FilePath& path, const LoopProperty& loopProperty, const std::vector<AssetTag>& tags = {}, int flag = AssetFlag::Default);

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
