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
# include "SivForward.hpp"
# include "SivColor.hpp"
# include "SivPropertyMacro.hpp"
# include "SivFormat.hpp"

namespace s3d
{
	/**
	*	@brief “_
	*/
	struct Point
	{
		typedef int value_type;

		int x, y;

		/**
		*
		*/
		Point(){}

		/**
		*
		*	@param _x
		*	@param _y
		*/
		Point(int _x, int _y) : x(_x), y(_y){}

		/**
		*
		*	@param _x
		*	@param _y
		*/
		template<typename U, typename V>
		Point(U _x, V _y) : x{ static_cast<int>(_x) }, y{ static_cast<int>(_y) }{}

		/**
		*
		*/
		Property_Get(Point, xx) const;

		/**
		*
		*/
		Property_Get(Point, xy) const;

		/**
		*
		*/
		Property_Get(Point, yx) const;

		/**
		*
		*/
		Property_Get(Point, yy) const;

		/**
		*
		*	@return
		*/
		Point operator + () const;

		/**
		*
		*	@return
		*/
		Point operator - () const;

		/**
		*
		*	@param p
		*	@return
		*/
		Point operator + (const Point& p) const;

		/**
		*
		*	@param p
		*	@return
		*/
		Point operator - (const Point& p) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Point operator * (int s) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vec2  operator * (double s) const;

		/**
		*
		*	@param p
		*	@return
		*/
		Point operator * (const Point& p) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Point operator / (int s) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vec2  operator / (double s) const;

		/**
		*
		*	@param p
		*	@return
		*/
		Point& operator += (const Point& p);

		/**
		*
		*	@param p
		*	@return
		*/
		Point& operator -= (const Point& p);

		/**
		*
		*	@param s
		*	@return
		*/
		Point& operator *= (int s);

		/**
		*
		*	@param s
		*	@return
		*/
		Point& operator /= (int s);

		/**
		*
		*	@param p
		*	@return
		*/
		bool operator == (const Point& p) const;

		/**
		*
		*	@param p
		*	@return
		*/
		bool operator != (const Point& p) const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Point& set(int _x, int _y) { x = _x; y = _y; return *this; }

		/**
		*
		*	@param p
		*	@return
		*/
		Point& set(const Point& p) { return *this = p; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Point& moveBy(int _x, int _y) { x += _x; y += _y; return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Point& moveBy(const Point& v) { return *this += v; }

		/**
		*
		*/
		Property_Get(bool, isZero) const { return x == 0 && y == 0; }

		/**
		*
		*	@param v
		*	@return
		*/
		double
			distanceFrom(
			const Point& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		double
			distanceFromSq(
			const Point& v
			) const;

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		bool
			intersects(
			const Shape& shape
			) const
		{
			return Geometry::Intersect(*this, shape);
		}

		/**
		*
		*/
		Property_Get(bool, leftClicked) const;

		/**
		*
		*/
		Property_Get(bool, leftPressed) const;

		/**
		*
		*/
		Property_Get(bool, leftReleased) const;

		/**
		*
		*/
		Property_Get(bool, rightClicked) const;

		/**
		*
		*/
		Property_Get(bool, rightPressed) const;

		/**
		*
		*/
		Property_Get(bool, rightReleased) const;

		/**
		*
		*/
		Property_Get(bool, mouseOver) const;

		/**
		*
		*	@param image
		*	@param color
		*/
		void
			write(
			Image& image,
			const Color& color = Palette::Black
			) const;

		/**
		*
		*	@param col
		*	@return
		*/
		const Point&
			draw(
			const Color& col = Palette::White
			) const;

		/**
		*	Point{ 0, 0 }
		*/
		const static Point Zero;

		/**
		*	Point{ 1, 1 }
		*/
		const static Point One;

		/**
		*	Point{ 1, 0 }
		*/
		const static Point UnitX;

		/**
		*	Point{ 0, 1 }
		*/
		const static Point UnitY;

		/**
		*	Point{ -1, 0 }
		*/
		const static Point Left;

		/**
		*	Point{ 1, 0 }
		*/
		const static Point Right;

		/**
		*	Point{ 0, -1 }
		*/
		const static Point Up;

		/**
		*	Point{ 0, 1 }
		*/
		const static Point Down;
	};

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
		const Point& v
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
		Point& v
		)
	{
		CharType unused;
		return is >> unused >> v.x >> unused >> v.y >> unused;
	}

	/**
	*
	*	@param s
	*	@param p
	*	@return
	*/
	inline Point operator * (int s, const Point& p);

	/**
	*
	*	@param s
	*	@param p
	*	@return
	*/
	inline Vec2 operator * (double s, const Point& p);
}
