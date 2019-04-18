//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

namespace s3d
{
	namespace Regex
	{
		String
			ReplaceFirst(
			const String& input,
			const String& regex,
			const String& replacement
			)
		{
			return std::regex_replace(
				input.str(),
				std::wregex(regex.str()),
				replacement.str(),
				std::regex_constants::format_first_only
				);
		}

		String
			ReplaceAll(
			const String& input,
			const String& regex,
			const String& replacement
			)
		{
			return std::regex_replace(
				input.str(),
				std::wregex(regex.str()),
				replacement.str()
				);
		}
	}
}
