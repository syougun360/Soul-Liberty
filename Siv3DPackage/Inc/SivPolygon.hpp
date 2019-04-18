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
# include <memory>
# include <vector>
# include <initializer_list>
# include "SivForward.hpp"
# include "SivPointVector.hpp"
# include "SivTriangle.hpp"
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief ëΩäpå`
	*/
	class Polygon
	{
	private:

		struct PolygonDetail;

		std::shared_ptr<PolygonDetail> m_detail;

	public:

		/**
		*
		*/
		Polygon(){}

		/**
		*
		*	@param pts
		*/
		Polygon(const String& pts);

		/**
		*
		*	@param pts
		*/
		Polygon(const std::vector<Vec2>& pts);

		/**
		*
		*	@param pts
		*	@param size
		*/
		Polygon(const Vec2* pts, size_t size);

		/**
		*
		*	@param il
		*/
		Polygon(
			std::initializer_list<Vec2> il
			) : Polygon(il.begin(),il.size()) {}

		/**
		*
		*	@param pts
		*/
		template<size_t Size>
		Polygon(const Vec2(&pts)[Size]) { *this = Polygon(&pts[0], Size); }

		explicit operator bool() const { return !isEmpty; }

		Property_Get(bool, isEmpty) const;

		/**
		*
		*	@param x
		*	@param y
		*	@return
		*/
		Polygon& moveBy(double x, double y) { return moveBy({ x, y }); }

		/**
		*
		*	@param v
		*	@return
		*/
		Polygon& moveBy(const Vec2& v);

		/**
		*
		*	@param v
		*	@return
		*/
		Polygon operator + (const Vec2& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Polygon operator - (const Vec2& v) const { return *this +(-v); }

		/**
		*
		*	@param x
		*	@param y
		*	@return
		*/
		Polygon rotate(double angle) const { return rotateAt({ 0, 0 }, angle); }

		/**
		*
		*	@param v
		*	@return
		*/
		Polygon rotateAt(const Vec2& pos, double angle) const;

		/**
		*
		*	@return
		*/
		std::vector<Vec2>::const_iterator begin() const;

		/**
		*
		*	@return
		*/
		std::vector<Vec2>::const_iterator end() const;

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
		*/
		Property_Get(RectF, boundingRect) const;

		/**
		*
		*	@return
		*/
		Polygon computeConvexHull() const;

		/**
		*
		*	@return
		*/
		Polygon simplify(double maxDistance = 2.0) const;

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
		*	@param image
		*	@param x
		*	@param y
		*	@param color
		*/
		void write(Image& image, int x, int y, const Color& color = Palette::Black) const;

		/**
		*
		*	@param image
		*	@param pos
		*	@param color
		*/
		void write(Image& image, const Point& pos, const Color& color = Palette::Black) const;

		/**
		*
		*	@param color
		*/
		void draw(const Color& color = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param color
		*/
		void draw(double x, double y, const Color& color = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param color
		*/
		void draw(const Vec2& pos, const Color& color = Palette::White) const;

		/**
		*
		*	@param thickness
		*	@param col
		*/
		void drawFrame(double thickness = 1.0, const Color& col = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param thickness
		*	@param color
		*/
		void drawFrame(double x, double y, double thickness = 1.0, const Color& color = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param thickness
		*	@param color
		*/
		void drawFrame(const Vec2& pos, double thickness = 1.0, const Color& color = Palette::White) const;

		/**
		*
		*	@param color
		*/
		void drawWireframe(const Color& color = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param color
		*/
		void drawWireframe(double x, double y, const Color& color = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param color
		*/
		void drawWireframe(const Vec2& pos, const Color& color = Palette::White) const;

		/**
		*
		*	@return
		*/
		const PolygonDetail* detail() const;

		/**
		*
		*/
		Property_Get(size_t, num_points) const;

		/**
		*
		*	@param index
		*	@return
		*/
		const Vec2& operator[](unsigned index) const;
	};

	/**
	*
	*	@param os
	*	@param polygon
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Polygon& polygon
		)
	{
		os << CharType('(');

		const size_t points = polygon.num_points;

		for (size_t i = 0; i < points; ++i)
		{
			os << polygon[i];

			if (i != points - 1)
			{
				os << CharType(',');
			}
		}

		return os << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param polygon
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Polygon& polygon
		)
	{
		CharType unused;

		is >> unused;

		std::vector<Vec2> pts;

		for (;;)
		{
			Vec2 v;

			is >> v;

			if (!is)
			{
				break;
			}

			is >> unused;

			pts.push_back(v);

			if (unused == L')')
			{
				break;
			}
		}

		polygon = Polygon(pts);

		return is;
	}

	/**
	*	@brief 2 éüå≥ê}å`ÇÃäÙâΩåvéZ
	*/
	namespace Geometry
	{
		/**
		*
		*	@param pts
		*	@return
		*/
		std::vector<Triangle>
			Triangulate(
			const std::vector<Vec2>& pts
			);

		/**
		*
		*	@param pts
		*	@param size
		*	@return
		*/
		std::vector<Triangle>
			Triangulate(
			const Vec2* pts,
			size_t size
			);

		/**
		*
		*	@param begin
		*	@param end
		*	@return
		*/
		template <typename Iterator>
		inline
			std::vector<s3d::Triangle>
			Triangulate(
			Iterator begin,
			Iterator end
			)
		{
			if (begin == end)
			{
				return{};
			}

			return Triangulate(&(*begin), std::distance(begin, end));
		}

		Polygon ImageToPolygon(const Image& image);
	}
}
