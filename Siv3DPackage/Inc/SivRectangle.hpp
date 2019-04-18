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
# include "SivLine.hpp"
# include "SivQuad.hpp"

namespace s3d
{
	/**
	*	@brief ’·•ûŒ`
	*/
	template<typename SizeType, typename ElementType>
	struct Rectangle
	{
		static_assert(sizeof(SizeType) == 2 * sizeof(ElementType), "");

#pragma warning(disable:4201)
		union
		{
			struct { SizeType pos, size; };
			struct { ElementType x, y, w, h; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		Rectangle(){}

		/**
		*
		*	@param _w
		*	@param _h
		*/
		Rectangle(ElementType _w, ElementType _h) : x(0), y(0), w(_w), h(_h){}

		/**
		*
		*	@param size
		*/
		explicit Rectangle(SizeType _size) : pos(0, 0), size(_size){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _w
		*	@param _h
		*/
		Rectangle(ElementType _x, ElementType _y, ElementType _w, ElementType _h) : x(_x), y(_y), w(_w), h(_h){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _size
		*/
		Rectangle(ElementType _x, ElementType _y, SizeType _size) : x(_x), y(_y), size(_size){}

		/**
		*
		*	@param _pos
		*	@param _w
		*	@param _h
		*/
		Rectangle(SizeType _pos, ElementType _w, ElementType _h) : pos(_pos), w(_w), h(_h){}

		/**
		*
		*	@param _pos
		*	@param _size
		*/
		Rectangle(SizeType _pos, SizeType _size) : pos(_pos), size(_size){}

		/**
		*
		*	@param r
		*/
		template<typename T, typename U>
		Rectangle(const Rectangle<T, U>& r) : x(static_cast<ElementType>(r.x)), y(static_cast<ElementType>(r.y)),
			w(static_cast<ElementType>(r.w)), h(static_cast<ElementType>(r.h)){}

		/**
		*
		*	@param s
		*	@return
		*/
		Rectangle& operator *= (ElementType s) { size *= s; return *this; }

		/**
		*
		*	@param s
		*	@return
		*/
		Rectangle& operator /= (ElementType s) { size /= s; return *this; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Rectangle& setPos(ElementType _x, ElementType _y) { pos.set(_x, _y); return *this; }

		/**
		*
		*	@param _pos
		*	@return
		*/
		Rectangle& setPos(const SizeType& _pos) { pos.set(_pos); return *this; }

		/**
		*
		*	@param _w
		*	@param _h
		*	@return
		*/
		Rectangle& setSize(ElementType _w, ElementType _h) { size.set(_w, _h); return *this; }

		/**
		*
		*	@param _size
		*	@return
		*/
		Rectangle& setSize(const SizeType& _size) { size.set(_size); return *this; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Rectangle& setCenter(ElementType _x, ElementType _y) { pos.set(_x - w / 2, _y - h / 2); return *this; }

		/**
		*
		*	@param _pos
		*	@return
		*/
		Rectangle& setCenter(const SizeType& _pos) { pos.set(_pos - size / 2); return *this; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Rectangle& moveBy(ElementType _x, ElementType _y) { pos.moveBy(_x, _y); return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Rectangle& moveBy(const SizeType& v) { pos.moveBy(v); return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Rectangle operator + (const SizeType& v) const { return { pos + v, size }; }

		/**
		*
		*	@param v
		*	@return
		*/
		Rectangle operator - (const SizeType& v) const { return { pos - v, size }; }

		/**
		*
		*/
		Property_Get(SizeType, tl) const;

		/**
		*
		*/
		Property_Get(SizeType, tr) const;

		/**
		*
		*/
		Property_Get(SizeType, bl) const;

		/**
		*
		*/
		Property_Get(SizeType, br) const;

		/**
		*
		*/
		Property_Get(SizeType, center) const;

		/**
		*
		*/
		Property_Get(Line, top) const;

		/**
		*
		*/
		Property_Get(Line, right) const;

		/**
		*
		*/
		Property_Get(Line, bottom) const;

		/**
		*
		*/
		Property_Get(Line, left) const;

		/**
		*
		*	@return
		*/
		ElementType area() const { return w*h; }

		/**
		*
		*	@return
		*/
		ElementType perimeter() const { return (w+h)*2; }

		/**
		*
		*	@param xy
		*	@return
		*/
		Rectangle stretched(ElementType xy) const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Rectangle stretched(ElementType _x, ElementType _y) const;

		/**
		*
		*	@param xy
		*	@return
		*/
		Rectangle stretched(const SizeType& xy) const;

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
		__declspec(deprecated("** Rect::within(SHAPE) is deprecated; use SHAPE::contains(rect) instead **"))
		bool within(const Shape& shape) const
		{
			return Geometry::Within(*this, shape);
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
		*	@param col
		*	@return
		*/
		const Rectangle& draw(const Color& col = Palette::White) const;

		/**
		*
		*	@param cols
		*	@return
		*/
		const Rectangle& draw(const Color(&cols)[4]) const;

		/**
		*
		*	@param innerThickness
		*	@param outerThickness
		*	@param col
		*	@return
		*/
		const Rectangle& drawFrame(double innerThickness = 1.0, double outerThickness = 0.0, const Color& col = Palette::White) const;

		/**
		*
		*	@param angle
		*	@return
		*/
		Quad rotate(double angle) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param angle
		*	@return
		*/
		Quad rotateAt(double x, double y, double angle) const;

		/**
		*
		*	@param pos
		*	@param angle
		*	@return
		*/
		Quad rotateAt(const Vec2& pos, double angle) const;

		/**
		*
		*	@param image
		*	@param color
		*/
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*
		*	@param tex
		*	@return
		*/
		TexturedQuad operator()(const Texture& tex) const;

		/**
		*
		*	@param tex
		*	@return
		*/
		TexturedQuad operator()(const TextureRegion& tex) const;
	};

	/**
	*
	*	@param os
	*	@param r
	*	@return
	*/
	template<typename CharType, typename SizeType, typename ElementType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Rectangle<SizeType, ElementType>& r
		)
	{
		return os << CharType('(')
			<< r.x << CharType(',')
			<< r.y << CharType(',')
			<< r.w << CharType(',')
			<< r.h << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param r
	*	@return
	*/
	template<typename CharType, typename SizeType, typename ElementType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Rectangle<SizeType, ElementType>& r
		)
	{
		CharType unused;
		return is >> unused
			>> r.x >> unused
			>> r.y >> unused
			>> r.w >> unused
			>> r.h >> unused;
	}

	typedef Rectangle<Point, int> Rect;

	typedef Rectangle<Vec2, double> RectF;
}

# include "SivRectangle.inl"
