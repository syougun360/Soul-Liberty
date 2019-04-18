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
# include "SivForward.hpp"
# include "SivStringRef.hpp"

namespace s3d
{
	/**
	*	@brief カラーパレット
	*/
	enum class Palette : unsigned
	{
		// Color Name			  0xaaBBggRR
		Black					= 0xff000000,
		Dimgray					= 0xff696969,
		Gray					= 0xff808080,
		Darkgray				= 0xffA9a9A9,
		Silver					= 0xffC0c0C0,
		Lightgrey				= 0xffD3d3D3,
		Gainsboro				= 0xffDCdcDC,
		Whitesmoke				= 0xffF5f5F5,
		White					= 0xffFFffFF,
		Snow					= 0xffFAfaFF,
		Ghostwhite				= 0xffFFf8F8,
		Floralwhite				= 0xffF0faFF,
		Linen					= 0xffE6f0FA,
		Antiquewhite			= 0xffD7ebFA,
		Papayawhip				= 0xffD5efFF,
		Blanchedalmond			= 0xffCDebFF,
		Bisque					= 0xffC4e4FF,
		Moccasin				= 0xffB5e4FF,
		Navajowhite				= 0xffADdeFF,
		Peachpuff				= 0xffB9daFF,
		Mistyrose				= 0xffE1e4FF,
		Lavenderblush			= 0xffF5f0FF,
		Seashell				= 0xffEEf5FF,
		Oldlace					= 0xffE6f5FD,
		Ivory					= 0xffF0ffFF,
		Honeydew				= 0xffF0ffF0,
		Mintcream				= 0xffFAffF5,
		Azure					= 0xffFFffF0,
		Aliceblue				= 0xffFFf8F0,
		Lavender				= 0xffFAe6E6,
		Lightsteelblue			= 0xffDEc4B0,
		Lightslategray			= 0xff998877,
		Slategray				= 0xff908070,
		Steelblue				= 0xffB48246,
		Royalblue				= 0xffE16941,
		Midnightblue			= 0xff701919,
		Navy					= 0xff800000,
		Darkblue				= 0xff8B0000,
		Mediumblue				= 0xffCD0000,
		Blue					= 0xffFF0000,
		Dodgerblue				= 0xffFF901E,
		Cornflowerblue			= 0xffED9564,
		Deepskyblue				= 0xffFFbf00,
		Lightskyblue			= 0xffFAce87,
		Skyblue					= 0xffEBce87,
		Lightblue				= 0xffE6d8AD,
		Powderblue				= 0xffE6e0B0,
		Paleturquoise			= 0xffEEeeAF,
		Lightcyan				= 0xffFFffE0,
		Cyan					= 0xffFFff00,
		Aqua					= 0xffFFff00,
		Turquoise				= 0xffD0e040,
		Mediumturquoise			= 0xffCCd148,
		Darkturquoise			= 0xffD1ce00,
		Lightseagreen			= 0xffAAb220,
		Cadetblue				= 0xffA09e5F,
		Darkcyan				= 0xff8B8b00,
		Teal					= 0xff808000,
		Darkslategray			= 0xff4F4f2F,
		Darkgreen				= 0xff006400,
		Green					= 0xff008000,
		Forestgreen				= 0xff228b22,
		Seagreen				= 0xff578b2E,
		Mediumseagreen			= 0xff71b33C,
		Mediumaquamarine		= 0xffAAcd66,
		Darkseagreen			= 0xff8Fbc8F,
		Aquamarine				= 0xffD4ff7F,
		Palegreen				= 0xff98fb98,
		Lightgreen				= 0xff90ee90,
		Springgreen				= 0xff7Fff00,
		Mediumspringgreen		= 0xff9Afa00,
		Lawngreen				= 0xff00fc7C,
		Chartreuse				= 0xff00ff7F,
		Greenyellow				= 0xff2FffAD,
		Lime					= 0xff00ff00,
		Limegreen				= 0xff32cd32,
		Yellowgreen				= 0xff32cd9A,
		Darkolivegreen			= 0xff2F6b55,
		Olivedrab				= 0xff238e6B,
		Olive					= 0xff008080,
		Darkkhaki				= 0xff6Bb7BD,
		Palegoldenrod			= 0xffAAe8EE,
		Cornsilk				= 0xffDCf8FF,
		Beige					= 0xffDCf5F5,
		Lightyellow				= 0xffE0ffFF,
		Lightgoldenrodyellow	= 0xffD2faFA,
		Lemonchiffon			= 0xffCDfaFF,
		Wheat					= 0xffB3deF5,
		Burlywood				= 0xff87b8DE,
		Tan						= 0xff8Cb4D2,
		Khaki					= 0xff8Ce6F0,
		Yellow					= 0xff00ffFF,
		Gold					= 0xff00d7FF,
		Orange					= 0xff00a5FF,
		Sandybrown				= 0xff60a4F4,
		Darkorange				= 0xff008cFF,
		Goldenrod				= 0xff20a5DA,
		Peru					= 0xff3F85CD,
		Darkgoldenrod			= 0xff0B86B8,
		Chocolate				= 0xff1E69D2,
		Sienna					= 0xff2D52A0,
		Saddlebrown				= 0xff13458B,
		Maroon					= 0xff000080,
		Darkred					= 0xff00008B,
		Brown					= 0xff2A2aA5,
		Firebrick				= 0xff2222B2,
		Indianred				= 0xff5C5cCD,
		Rosybrown				= 0xff8F8fBC,
		Darksalmon				= 0xff7A96E9,
		Lightcoral				= 0xff8080F0,
		Salmon					= 0xff7280FA,
		Lightsalmon				= 0xff7Aa0FF,
		Coral					= 0xff507fFF,
		Tomato					= 0xff4763FF,
		Orangered				= 0xff0045FF,
		Red						= 0xff0000FF,
		Crimson					= 0xff3C14DC,
		Mediumvioletred			= 0xff8515C7,
		Deeppink				= 0xff9314FF,
		Hotpink					= 0xffB469FF,
		Palevioletred			= 0xff9370DB,
		Pink					= 0xffCBc0FF,
		Lightpink				= 0xffC1b6FF,
		Thistle					= 0xffD8bfD8,
		Magenta					= 0xffFF00FF,
		Fuchsia					= 0xffFF00FF,
		Violet					= 0xffEE82EE,
		Plum					= 0xffDDa0DD,
		Orchid					= 0xffD670DA,
		Mediumorchid			= 0xffD355BA,
		Darkorchid				= 0xffCC3299,
		Darkviolet				= 0xffD30094,
		Darkmagenta				= 0xff8B008B,
		Purple					= 0xff800080,
		Indigo					= 0xff82004B,
		Darkslateblue			= 0xff8B3d48,
		Blueviolet				= 0xffE22b8A,
		Mediumpurple			= 0xffDB7093,
		Slateblue				= 0xffCD5a6A,
		Mediumslateblue			= 0xffEE687B,
	};

	/**
	*	@brief カラー
	*
	*	R,G,B,A それぞれ 8bit 整数の色情報を持ちます。
	*/
# pragma warning ( disable: 4201 )
	union Color
	{
		unsigned c;
		unsigned char elem[4];
		struct
		{
			unsigned r : 8;
			unsigned g : 8;
			unsigned b : 8;
			unsigned a : 8;
		};

		/**
		*
		*/
		Color(){}

		/**
		*
		*	@param _r
		*	@param _g
		*	@param _b
		*	@param _a
		*/
		Color(unsigned _r, unsigned _g, unsigned _b, unsigned _a = 255) : r(_r & 0xFF), g(_g & 0xFF), b(_b & 0xFF), a(_a & 0xFF){}

		/**
		*
		*	@param rgb
		*/
		explicit Color(unsigned rgb) : r(rgb & 0xFF), g(rgb & 0xFF), b(rgb & 0xFF), a(0xFF) {}

		/**
		*
		*	@param _rgb
		*	@param _a
		*/
		Color(unsigned _rgb, unsigned _a) : r(_rgb & 0xFF), g(_rgb & 0xFF), b(_rgb & 0xFF), a(_a & 0xFF) {}

		/**
		*
		*	@param col
		*/
		Color(Palette col) : c(static_cast<unsigned>(col)) {}

		/**
		*
		*	@param col
		*	@param _a
		*/
		Color(Palette col, unsigned _a) : c(static_cast<unsigned>(col)) { a = _a; }

		/**
		*
		*	@param col
		*/
		Color(const Color& col);

		/**
		*
		*	@param col
		*/
		Color(const ColorF& col);

		/**
		*	カラーを初期化します。
		*	@param code L"#FFF" または L"#FFFFFF" のような # から始まるカラーコード
		*/
		Color(const StringRef& code);

		/**
		*
		*	@param col
		*	@return
		*/
		Color& operator = (const Color& col);

		/**
		*
		*	@param col
		*	@return
		*/
		Color& operator = (const ColorF& col);

		/**
		*
		*	@param rgb
		*	@return
		*/
		Color& operator = (unsigned rgb);

		/**
		*
		*	@param col
		*	@return
		*/
		Color& operator = (Palette col);

		/**
		*
		*	@return
		*/
		Color operator ~ () const;

		/**
		*
		*	@param col
		*	@return
		*/
		bool operator == (const Color& col) const;

		/**
		*
		*	@param col
		*	@return
		*/
		bool operator != (const Color& col) const;

		/**
		*
		*	@param _r
		*	@param _g
		*	@param _b
		*	@param _a
		*	@return
		*/
		Color& set(unsigned _r, unsigned _g, unsigned _b, unsigned _a = 255);

		/**
		*
		*	@param alpha
		*	@return
		*/
		Color& setAlpha(unsigned alpha);

		/**
		*
		*/
		Property_Get(unsigned, code) const;

		/**
		*
		*/
		Property_Get(unsigned char, grayscale) const;
	};
# pragma warning ( default: 4201 )

	/**
	*
	*	@param os
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Color& color
		)
	{
		return os << CharType('(')
			<< color.r << CharType(',')
			<< color.g << CharType(',')
			<< color.b << CharType(',')
			<< color.a << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Color& color
		)
	{
		unsigned cols[4];
		CharType unused;

		is >> unused
			>> cols[0] >> unused
			>> cols[1] >> unused
			>> cols[2] >> unused;

		if (unused == CharType(','))
		{
			is >> cols[3] >> unused;
		}
		else
		{
			cols[3] = 255;
		}

		for (int i = 0; i < 4; ++i)
		{
			color.elem[i] = cols[i] & 0xFF;
		}

		return is;
	}
}

namespace s3d
{
	/**
	* @brief カラー
	*
	* R,G,B,A それぞれ 64bit 浮動小数の色情報を持ちます。
	*/
# pragma warning ( disable: 4201 )
	struct ColorF
	{
		struct
		{
			double r, g, b, a;
		};

		/**
		*
		*/
		ColorF(){}

		/**
		*
		*	@param _rgb
		*/
		explicit ColorF(double _rgb) : r(_rgb), g(_rgb), b(_rgb), a(1.0){}

		/**
		*
		*	@param _rgb
		*	@param _a
		*/
		ColorF(double _rgb, double _a) : r(_rgb), g(_rgb), b(_rgb), a(_a){}

		/**
		*
		*	@param _r
		*	@param _g
		*	@param _b
		*	@param _a
		*/
		ColorF(double _r, double _g, double _b, double _a = 1.0) : r(_r), g(_g), b(_b), a(_a){}

		/**
		*
		*	@param rgb
		*/
		explicit ColorF(const Vec3& rgb);

		/**
		*
		*	@param rgb
		*	@param _a
		*/
		ColorF(const Vec3& rgb, double _a);

		/**
		*
		*	@param col
		*/
		ColorF(Palette col);

		/**
		*
		*	@param col
		*	@param _a
		*/
		ColorF(Palette col, double _a);

		/**
		*
		*	@param col
		*/
		ColorF(const Color& col) : r(col.r / 255.0), g(col.g / 255.0), b(col.b / 255.0), a(col.a / 255.0) {}

		/**
		*
		*	@param col
		*/
		ColorF(const ColorF& col) : r(col.r), g(col.g), b(col.b), a(col.a) {}

		/**
		*	カラーを初期化します。
		*	@param code L"#FFF" または L"#FFFFFF" のような # から始まるカラーコード
		*/
		ColorF(const StringRef& code);

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator = (const ColorF& col);

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator = (const Color& col);

		/**
		*
		*	@param rgb
		*	@return
		*/
		ColorF& operator = (double rgb);

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator = (Palette col);

		/**
		*
		*	@param s
		*	@return
		*/
		ColorF operator * (double s) const;

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator += (const ColorF& col);

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator -= (const ColorF& col);

		/**
		*
		*	@param s
		*	@return
		*/
		ColorF& operator *= (double s);

		/**
		*
		*	@param col
		*	@return
		*/
		ColorF& operator *= (const ColorF& col);

		/**
		*
		*	@param _r
		*	@param _g
		*	@param _b
		*	@param _a
		*	@return
		*/
		ColorF& set(double _r, double _g, double _b, double _a = 1.0);

		/**
		*
		*	@param alpha
		*	@return
		*/
		ColorF& setAlpha(double alpha);

		/**
		*
		*/
		Property_Get(Color, col) const;

		/**
		*
		*/
		Property_Get(double, grayscale) const;

		/**
		*
		*/
		Property_Get(Vec2, rg) const;

		/**
		*
		*/
		Property_Get(Vec2, gb) const;

		/**
		*
		*/
		Property_Get(Vec2, ba) const;

		/**
		*
		*/
		Property_Get(Vec3, rgb) const;

		/**
		*
		*/
		Property_Get(Vec3, gba) const;

		/**
		*
		*/
		Property_Get(Vec4, rgba) const;

		/**
		*
		*/
		Property_Get(Vec4, argb) const;
	};
# pragma warning ( default: 4201 )

	/**
	*
	*	@param os
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const ColorF& color
		)
	{
		return os << CharType('(')
			<< color.r << CharType(',')
			<< color.g << CharType(',')
			<< color.b << CharType(',')
			<< color.a << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		ColorF& color
		)
	{
		CharType unused;

		is >> unused
			>> color.r >> unused
			>> color.g >> unused
			>> color.b >> unused;

		if (unused == CharType(','))
		{
			is >> color.a >> unused;
		}
		else
		{
			color.a = 1.0;
		}

		return is;
	}

	/**
	*
	*	@param alpha
	*	@return
	*/
	inline Color Alpha(unsigned alpha)
	{
		return { 255, 255, 255, alpha };
	}

	/**
	*
	*	@param dst
	*	@param src
	*	@param alpha
	*	@return
	*/
	inline Color BlendColor(const Color& dst, const Color& src, unsigned alpha = 255)
	{
		const unsigned a = (src.a * alpha) / 255;
		const unsigned r = ((src.r * a) + (dst.r * (255 - a))) / 255;
		const unsigned g = ((src.g * a) + (dst.g * (255 - a))) / 255;
		const unsigned b = ((src.b * a) + (dst.b * (255 - a))) / 255;

		return{ r, g, b, dst.a };
	}

	/**
	*
	*	@param dst
	*	@param src
	*	@param alpha
	*	@return
	*/
	Color BlendColor(const ColorF& dst, const ColorF& src, double alpha = 1.0);

	/**
	*
	*	@param s
	*	@param col
	*	@return
	*/
	const ColorF operator * (double s, const ColorF& col);

	/**
	*
	*	@param col1
	*	@param col2
	*	@return
	*/
	const ColorF operator * (const ColorF& col1, const ColorF& col2);
}

# include "SivColor.inl"
