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
#  ifdef _DEBUG
#   pragma comment (lib, "Box2D_d")
#  else
#   pragma comment (lib, "Box2D")
#  endif
# include "../Box2D/Box2D.h"
# include "../SivFormat.hpp"

	/**
	*
	*	@param os
	*	@param v
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const b2Vec2& v
		)
	{
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param v
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		b2Vec2& v
		)
	{
		CharType unused;
		return is >> unused >> v.x >> unused >> v.y >> unused;
	}
