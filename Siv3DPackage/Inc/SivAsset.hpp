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
# include <vector>
# include "SivForward.hpp"
# include "SivString.hpp"

namespace s3d
{
	typedef String AssetName;

	typedef String AssetTag;

	enum AssetFlag
	{
		UseGlobalAutoReloadSetting = 0x0,
		LoadImmediately	= 0x1,
		AutoReload		= 0x2,
		WarnDuplication	= 0x4,

		Default = UseGlobalAutoReloadSetting | WarnDuplication,
	};

	namespace Asset
	{
		void EnableAutoReload(bool enabled);

		void ReleaseAll();

		void UnregisterAll();
	}
}

# include "SivSoundAsset.hpp"
# include "SivTextureAsset.hpp"
# include "SivFontAsset.hpp"
# include "SivRendererAsset.hpp"
# include "SivGUIAsset.hpp"
