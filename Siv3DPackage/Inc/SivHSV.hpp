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
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief HSV カラー
	*
	*	色情報を 色相(H), 彩度(S), 明度(V) で表します。
	*/
	struct HSV
	{
		double h;	// [0.0,360.0)
		double s, v;	// [0.0,1.0]

		/**
		*
		*/
		HSV(){}

		/**
		*
		*	@param _h
		*/
		explicit HSV(double _h) : h(_h), s(1.0), v(1.0){}

		/**
		*
		*	@param _h
		*	@param _s
		*	@param _v
		*/
		HSV(double _h, double _s, double _v) : h(_h), s(_s), v(_v){}

		/**
		*
		*	@param col
		*/
		HSV(const Color& col);

		/**
		*
		*	@param col
		*/
		HSV(const ColorF& col);

		/**
		*
		*	@param hsv
		*	@return
		*/
		HSV operator + (const HSV& hsv) const;

		/**
		*
		*	@param hsv
		*	@return
		*/
		HSV operator - (const HSV& hsv) const;

		/**
		*
		*	@return
		*/
		operator Color() const
		{
			return toColor();
		}

		/**
		*
		*	@return
		*/
		Color toColor(unsigned alpha = 255) const;

		/**
		*
		*	@return
		*/
		ColorF toColorF(double alpha = 1.0) const;

		/**
		*
		*	@param r
		*	@param g
		*	@param b
		*/
		void convertFrom(double r, double g, double b);
	};

	/**
	*
	*	@param os
	*	@param hsv
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const HSV& hsv
		)
	{
		return os << CharType('(')
			<< hsv.h << CharType(',')
			<< hsv.s << CharType(',')
			<< hsv.v << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param hsv
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		HSV& hsv
		)
	{
		CharType unused;

		return	is >> unused
			>> hsv.h >> unused
			>> hsv.s >> unused
			>> hsv.v >> unused;
	}

	/**
	*
	*	@param color
	*	@param hsv
	*	@return
	*/
	inline HSV operator + (const Color& color, const HSV& hsv)
	{
		return HSV(color) + hsv;
	}

	/**
	*
	*	@param color
	*	@param hsv
	*	@return
	*/
	inline HSV operator - (const Color& color, const HSV& hsv)
	{
		return HSV(color) - hsv;
	}
}
