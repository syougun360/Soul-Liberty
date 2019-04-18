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
# include <vector>
# include <memory>
# include "SivPointVector.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief ê¸ÇÃîzóÒ
	*/
	class LineString
	{
	private:

		class CLineString;

		std::shared_ptr<CLineString> m_detail;

	public:

		/**
		*
		*/
		LineString();

		/**
		*
		*	@param pts
		*/
		LineString(const String& pts);

		/**
		*
		*	@param pts
		*/
		LineString(const std::vector<Vec2>& pts);

		/**
		*
		*	@param pts
		*	@param size
		*/
		LineString(const Vec2* pts, size_t size);

		/**
		*
		*	@param pts
		*/
		template<size_t Size>
		LineString(const Vec2(&pts)[Size]) : LineString(&pts[0], Size) {}

		/**
		*
		*	@param il
		*/
		LineString(
			std::initializer_list<Vec2> il
			) :	LineString(il.begin(), il.size()) {}

		/**
		*
		*/
		Property_Get(size_t, num_points) const;

		/**
		*
		*	@param index
		*	@return
		*/
		Vec2& operator [] (size_t index);

		/**
		*
		*	@param index
		*	@return
		*/
		const Vec2& operator [] (size_t index) const;

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
		*	@param offset
		*	@return
		*/
		LineString substr(
			size_t offset
			) const;

		/**
		*
		*	@param offset
		*	@param count
		*	@return
		*/
		LineString substr(
			size_t offset,
			size_t count
			) const;

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
		*	@param image
		*	@param color
		*/
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*
		*	@param image
		*	@param thickness
		*	@param color
		*/
		void write(Image& image, int thickness, const Color& color = Palette::Black) const;

		/**
		*
		*	@param image
		*	@param thickness
		*	@param color
		*	@param isClosedCurve
		*/
		void
			writeCatmullRomSpline(
			Image& image,
			int thickness = 1,
			const Color& color = Palette::Black,
			bool isClosedCurve = false
			) const;

		/**
		*
		*	@param color
		*	@param isClosedCurve
		*/
		void draw(const Color& color = Palette::White, bool isClosedCurve = false) const;

		/**
		*
		*	@param thickness
		*	@param color
		*	@param isClosedCurve
		*/
		void draw(double thickness, const Color& color = Palette::White, bool isClosedCurve = false) const;

		/**
		*
		*	@param thickness
		*	@param color
		*	@param isClosedCurve
		*/
		void
			drawCatmullRomSpline(
			double thickness = 1.0,
			const Color& color = Palette::White,
			bool isClosedCurve = false
			) const;
	};

	/**
	*
	*	@param os
	*	@param lineStr
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const LineString& lineStr
		)
	{
		os << CharType('(');

		const size_t points = lineStr.num_points;

		for (size_t i = 0; i < points; ++i)
		{
			os << lineStr[i];

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
	*	@param lineStr
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		LineString& lineStr
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

		lineStr = LineString(pts);

		return is;
	}
}
