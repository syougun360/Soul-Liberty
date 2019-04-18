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

namespace s3d
{
	class ISiv3DAddon
	{
	public:

		virtual ~ISiv3DAddon() = default;

		virtual String getName() const = 0;

		virtual bool init() = 0;

		virtual bool update() = 0;
	};

	namespace Addon
	{
		bool Register(std::shared_ptr<ISiv3DAddon>& Addon);

		bool IsRegistered(const String& name);

		ISiv3DAddon* GetIAddon(const String& name);

		template<typename AddonType>
		AddonType* GetAddon()
		{
			return dynamic_cast<AddonType*>(GetIAddon(AddonType::name()));
		}

		template<typename AddonType>
		bool Register()
		{
			if (Addon::IsRegistered(AddonType::name()))
			{
				return false;
			}

			if (auto p = std::dynamic_pointer_cast<ISiv3DAddon>(std::make_shared<AddonType>()))
			{
				if (!p->init())
				{
					return false;
				}

				return Addon::Register(p);
			}
			else
			{
				return false;
			}
		}
	}
}
