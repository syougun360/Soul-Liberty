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
# include "SivPointVector.hpp"
# include "SivChar.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief 三角形
	*/
	struct Triangle
	{
#pragma warning(disable:4201)
		union
		{
			struct { Vec2 p0, p1, p2; };
			struct { Vec2 p[3]; };
		};
#pragma warning(default:4201)

		/*
		*
		*/
		Triangle(){}

		/*
		*
		*	@param sides
		*/
		explicit Triangle(double sides);

		/*
		*
		*	@param sides
		*	@param angle
		*/
		Triangle(double sides, double angle);

		/*
		*
		*	@param x
		*	@param y
		*	@param sides
		*/
		Triangle(double x, double y, double sides) : Triangle({ x, y }, sides){}

		/*
		*
		*	@param pos
		*	@param sides
		*/
		Triangle(const Vec2& pos, double sides);

		/*
		*
		*	@param x
		*	@param y
		*	@param sides
		*	@param angle
		*/
		Triangle(double x, double y, double sides, double angle) : Triangle({ x, y }, sides, angle){}

		/*
		*
		*	@param pos
		*	@param sides
		*	@param angle
		*/
		Triangle(const Vec2& pos, double sides, double angle);

		/*
		*
		*	@param x0
		*	@param y0
		*	@param x1
		*	@param y1
		*	@param x2
		*	@param y2
		*/
		Triangle(double x0, double y0, double x1, double y1, double x2, double y2) : p0(x0, y0), p1(x1, y1), p2(x2, y2){}

		/**
		*
		*	@param _p0
		*	@param _p1
		*	@param _p2
		*/
		Triangle(const Vec2& _p0, const Vec2& _p1, const Vec2& _p2) : p0(_p0), p1(_p1), p2(_p2){}

		/**
		*
		*	@param x
		*	@param y
		*	@return
		*/
		Triangle& moveBy(double x, double y) { return moveBy({ x, y }); }

		/**
		*
		*	@param v
		*	@return
		*/
		Triangle& moveBy(const Vec2& v);

		/**
		*
		*	@param x
		*	@param y
		*	@return
		*/
		Triangle& setCentroid(double x, double y) { return setCentroid({ x, y }); }

		/**
		*
		*	@param pos
		*	@return
		*/
		Triangle& setCentroid(const Vec2& pos);

		/**
		*
		*	@param angle
		*	@return
		*/
		Triangle rotate(double angle) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param angle
		*	@return
		*/
		Triangle rotateAt(double x, double y, double angle) const;

		/**
		*
		*	@param pos
		*	@param angle
		*	@return
		*/
		Triangle rotateAt(const Vec2& pos, double angle) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Triangle operator + (const Vec2& v) const { return { p0 + v, p1 + v, p2 + v }; }

		/**
		*
		*	@param v
		*	@return
		*/
		Triangle operator - (const Vec2& v) const { return { p0 - v, p1 - v, p2 - v }; }

		/**
		*
		*	@return
		*/
		double area() const;

		/**
		*
		*	@return
		*/
		double perimeter() const;

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		bool intersects(const Shape& shape) const
		{
			return Geometry::Intersect(*this, shape);
		}

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		bool contains(const Shape& shape) const
		{
			return Geometry::Within(shape, *this);
		}

		/**
		*	三角形の重心座標を返します。
		*/
		Property_Get(Vec2, centroid) const;

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
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*
		*	@param col
		*	@return
		*/
		const Triangle& draw(const Color& col = Palette::White) const;

		/**
		*
		*	@param cols
		*	@return
		*/
		const Triangle& draw(const Color(&cols)[3]) const;

		/**
		*
		*	@param thickness
		*	@param col
		*	@return
		*/
		const Triangle& drawFrame(double thickness = 1.0, const Color& col = Palette::White) const;
	};

	/**
	*
	*	@param os
	*	@param triangle
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Triangle& triangle
		)
	{
		return	os << CharType('(')
			<< triangle.p[0] << CharType(',')
			<< triangle.p[1] << CharType(',')
			<< triangle.p[2] << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param triangle
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Triangle& triangle
		)
	{
		CharType unused;

		return	is >> unused
			>> triangle.p[0] >> unused
			>> triangle.p[1] >> unused
			>> triangle.p[2] >> unused;
	}
}
