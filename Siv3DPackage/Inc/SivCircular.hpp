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
# include <iostream>
# include "SivPropertyMacro.hpp"
# include "SivPointVector.hpp"
# include "SivMathConstants.hpp"

namespace s3d
{
	/**
	*	@brief ã…ç¿ïW
	*/
	struct Circular
	{
		double r, theta;

		/**
		*
		*/
		Circular(){}

		/**
		*
		*	@param _r
		*	@param _theta
		*/
		Circular(double _r, double _theta) : r(_r), theta(_theta){}

		/**
		*
		*	@param pos
		*/
		Circular(const Vec2& pos) : r(pos.length()), theta(::atan2(pos.x, -pos.y)){}

		/**
		*
		*	@return
		*/
		Circular operator + () const;

		/**
		*
		*	@return
		*/
		Circular operator - () const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vec2 operator + (const Vec2& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vec2 operator - (const Vec2& v) const;

		/**
		*
		*	@return
		*/
		operator Vec2() const;
	};

	/**
	*
	*	@param os
	*	@param c
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Circular& c
		)
	{
		return os << CharType('(') << c.r << CharType(',') << v.theta << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param c
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Circular& c
		)
	{
		CharType unused;
		return is >> unused >> c.r >> unused >> c.theta >> unused;
	}

	/**
	*
	*	@param pos
	*	@param c
	*	@return
	*/
	inline Vec2 operator + (const Vec2& pos, const Circular& c)
	{
		return c + pos;
	}

	/**
	*
	*	@param pos
	*	@param c
	*	@return
	*/
	inline Vec2 operator - (const Vec2& pos, const Circular& c)
	{
		return pos + (-c);
	}
}

# include "SivCircular.inl"
