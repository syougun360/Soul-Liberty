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
# include <regex>
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief ê≥ãKï\åª
	*/
	namespace Regex
	{
		/**
		*
		*	@param input
		*	@param regex
		*	@param replacement
		*	@return
		*/
		inline
		String
			ReplaceFirst(
			const String& input,
			const String& regex,
			const String& replacement
			);

		/**
		*
		*	@param input
		*	@param regex
		*	@param replacement
		*	@return
		*/
		inline
		String
			ReplaceAll(
			const String& input,
			const String& regex,
			const String& replacement
			);
	}
}

# include "SivRegex.inl"
