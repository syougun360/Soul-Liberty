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
# include "SivPointVector.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief ‰š‚ðŠÜ‚Ü‚È‚¢ŽlŠpŒ`
	*/
	struct Quad
	{
#pragma warning(disable:4201)
		union
		{
			struct { Vec2 tl, tr, br, bl; };
			struct { Vec2 p[4]; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		Quad(){}

		/**
		*
		*	@param pts
		*/
		Quad(const String& pts);

		/**
		*
		*	@param x0
		*	@param y0
		*	@param x1
		*	@param y1
		*	@param x2
		*	@param y2
		*	@param x3
		*	@param y3
		*/
		Quad(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3) : tl(x0, y0), tr(x1, y1), br(x2, y2), bl(x3, y3){}

		/**
		*
		*	@param _tl
		*	@param _tr
		*	@param _br
		*	@param _bl
		*/
		Quad(const Vec2& _tl, const Vec2& _tr, const Vec2& _br, const Vec2& _bl) : tl(_tl), tr(_tr), br(_br), bl(_bl){}

		/**
		*
		*	@param x
		*	@param y
		*	@return
		*/
		Quad& moveBy(double x, double y) { return moveBy({ x, y }); }

		/**
		*
		*	@param v
		*	@return
		*/
		Quad& moveBy(const Vec2& v)
		{
			tl.moveBy(v);
			tr.moveBy(v);
			br.moveBy(v);
			bl.moveBy(v);
			return *this;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		Quad operator + (const Vec2& v) const { return { tl + v, tr + v, br + v, bl + v }; }

		/**
		*
		*	@param v
		*	@return
		*/
		Quad operator - (const Vec2& v) const { return { tl - v, tr - v, br - v, bl - v }; }

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
		const Quad& draw(const Color& col = Palette::White) const;

		/**
		*
		*	@param cols
		*	@return
		*/
		const Quad& draw(const Color(&cols)[4])const;

		/**
		*
		*	@param thickness
		*	@param col
		*	@return
		*/
		const Quad& drawFrame(double thickness = 1.0, const Color& col = Palette::White) const;

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
	*	@param quad
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Quad& quad
		)
	{
		return	os << CharType('(')
			<< quad.p[0] << CharType(',')
			<< quad.p[1] << CharType(',')
			<< quad.p[2] << CharType(',')
			<< quad.p[3] << CharType(')');
		}

	/**
	*
	*	@param is
	*	@param quad
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Quad& quad
		)
	{
		CharType unused;

		return	is >> unused
			>> quad.p[0] >> unused
			>> quad.p[1] >> unused
			>> quad.p[2] >> unused
			>> quad.p[3] >> unused;
	}
}
