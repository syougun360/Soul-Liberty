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
# include "SivForward.hpp"
# include "SivColor.hpp"
# include "SivPointVector.hpp"

namespace s3d
{
	/**
	*	@brief ê¸ï™
	*/
	struct LineInt
	{
#pragma warning(disable:4201)
		union
		{
			struct { Point begin, end; };
			struct { Point p[2]; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		LineInt(){}

		/**
		*
		*	@param x0
		*	@param y0
		*	@param x1
		*	@param y1
		*/
		LineInt(int x0, int y0, int x1, int y1) : begin(x0, y0), end(x1, y1){}

		/**
		*
		*	@param p0
		*	@param x1
		*	@param y1
		*/
		LineInt(const Point& p0, int x1, int y1) : begin(p0), end(x1, y1){}

		/**
		*
		*	@param x0
		*	@param y0
		*	@param p1
		*/
		LineInt(int x0, int y0, const Point& p1) : begin(x0, y0), end(p1){}

		/**
		*
		*	@param p0
		*	@param p1
		*/
		LineInt(const Point& p0, const Point& p1) : begin(p0), end(p1){}

		/**
		*
		*	@param line
		*	@return
		*/
		bool operator == (const s3d::LineInt& line) const;

		/**
		*
		*	@param line
		*	@return
		*/
		bool operator != (const s3d::LineInt& line) const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		LineInt&
			moveBy(
			int _x,
			int _y
			);

		/**
		*
		*	@param v
		*	@return
		*/
		LineInt&
			moveBy(
			const Point& v
			);

		/**
		*
		*	@param v
		*	@return
		*/
		LineInt operator + (const Point& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		LineInt operator - (const Point& v) const;

		/**
		*
		*	@return
		*/
		Point
			vector(
			) const;

		/**
		*
		*	@return
		*/
		double
			length(
			) const;

		/**
		*
		*	@return
		*/
		double
			lengthSq(
			) const;

		/**
		*
		*	@param pos
		*	@return
		*/
		Vec2
			closest(
			const Vec2& pos
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
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		__declspec(deprecated("** LineInt::within(SHAPE) is deprecated; use SHAPE::contains(line) instead **"))
		bool
			within(
			const Shape& shape
			) const
		{
			return Geometry::Within(*this, shape);
		}

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
		*	@param image
		*	@param thickness
		*	@param color
		*/
		void
			write(
			Image& image,
			int thickness = 1,
			const Color& color = Palette::Black
			) const;

		/**
		*
		*	@param image
		*	@param thickness
		*	@param headSize
		*	@param color
		*/
		void
			writeArrow(
			Image& image,
			double thickness = 1,
			const Vec2& headSize = Vec2(5.0, 5.0),
			const Color& color = Palette::Black
			) const;

		/**
		*
		*	@param col
		*	@return
		*/
		const LineInt&
			draw(
			const Color& col = Palette::White
			) const;

		/**
		*
		*	@param cols
		*	@return
		*/
		const LineInt&
			draw(
			const Color(&cols)[2]
			) const;

		/**
		*
		*	@param thickness
		*	@param col
		*	@return
		*/
		const LineInt&
			draw(
			int thickness,
			const Color& col = Palette::White
			) const;

		/**
		*
		*	@param thickness
		*	@param cols
		*	@return
		*/
		const LineInt&
			draw(
			int thickness,
			const Color(&cols)[2]
			) const;

		/**
		*
		*	@param thickness
		*	@param headSize
		*	@param color
		*	@return
		*/
		const LineInt&
			drawArrow(
			double thickness = 1,
			const Vec2& headSize = Vec2(5.0, 5.0),
			const Color& color = Palette::White
			) const;
	};

	/**
	*
	*	@param os
	*	@param line
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const LineInt& line
		)
	{
		return	os << CharType('(')
			<< line.p[0] << CharType(',')
			<< line.p[1] << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param line
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		LineInt& line
		)
	{
		CharType unused;

		return	is >> unused
			>> line.p[0] >> unused
			>> line.p[1] >> unused;
	}

	/**
	*	@brief ê¸ï™
	*/
	struct Line
	{
#pragma warning(disable:4201)
		union
		{
			struct { Vec2 begin, end; };
			struct { Vec2 p[2]; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		Line(){}

		/**
		*
		*	@param x0
		*	@param y0
		*	@param x1
		*	@param y1
		*/
		Line(double x0, double y0, double x1, double y1) : begin(x0, y0), end(x1, y1){}

		/**
		*
		*	@param p0
		*	@param x1
		*	@param y1
		*/
		Line(const Vec2& p0, double x1, double y1) : begin(p0), end(x1, y1){}

		/**
		*
		*	@param x0
		*	@param y0
		*	@param p1
		*/
		Line(double x0, double y0, const Vec2& p1) : begin(x0, y0), end(p1){}

		/**
		*
		*	@param p0
		*	@param p1
		*/
		Line(const Vec2& p0, const Vec2& p1) : begin(p0), end(p1){}

		/**
		*
		*	@param line
		*/
		Line(const LineInt& line) : begin(line.begin), end(line.end){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Line&
			moveBy(
			double _x,
			double _y
			);

		/**
		*
		*	@param v
		*	@return
		*/
		Line&
			moveBy(
			const Vec2& v
			);

		/**
		*
		*	@param v
		*	@return
		*/
		Line operator + (const Vec2& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Line operator - (const Vec2& v) const;

		/**
		*
		*	@return
		*/
		Vec2
			vector(
			) const;

		/**
		*
		*	@return
		*/
		double
			length(
			) const;

		/**
		*
		*	@return
		*/
		double
			lengthSq(
			) const;

		/**
		*
		*	@param pos
		*	@return
		*/
		Vec2
			closest(
			const Vec2& pos
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
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		__declspec(deprecated("** Line::within(SHAPE) is deprecated; use SHAPE::contains(line) instead **"))
		bool
			within(
			const Shape& shape
			) const
		{
			return Geometry::Within(*this, shape);
		}

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
		*	@param image
		*	@param thickness
		*	@param color
		*/
		void
			write(
			Image& image,
			int thickness = 1,
			const Color& color = Palette::Black
			) const;

		/**
		*
		*	@param image
		*	@param thickness
		*	@param headSize
		*	@param color
		*/
		void
			writeArrow(
			Image& image,
			double thickness = 1,
			const Vec2& headSize = Vec2(5.0, 5.0),
			const Color& color = Palette::Black
			) const;

		/**
		*
		*	@param col
		*	@return
		*/
		const Line&
			draw(
			const Color& col = Palette::White
			) const;

		/**
		*
		*	@param cols
		*	@return
		*/
		const Line&
			draw(
			const Color(&cols)[2]
			) const;

		/**
		*
		*	@param thickness
		*	@param col
		*	@return
		*/
		const Line&
			draw(
			double thickness,
			const Color& col = Palette::White
			) const;

		/**
		*
		*	@param thickness
		*	@param cols
		*	@return
		*/
		const Line&
			draw(
			double thickness,
			const Color(&cols)[2]
			) const;

		/**
		*
		*	@param thickness
		*	@param headSize
		*	@param color
		*	@return
		*/
		const Line&
			drawArrow(
			double thickness = 1,
			const Vec2& headSize = Vec2(5.0, 5.0),
			const Color& color = Palette::White
			) const;
	};

	/**
	*
	*	@param os
	*	@param line
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Line& line
		)
	{
		return	os << CharType('(')
			<< line.p[0] << CharType(',')
			<< line.p[1] << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param line
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Line& line
		)
	{
		CharType unused;

		return	is >> unused
			>> line.p[0] >> unused
			>> line.p[1] >> unused;
	}
}

# include "SivLine.inl"
