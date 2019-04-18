//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

namespace s3d
{
	inline Color::Color(const Color& col)
	{
		c = col.c;
	}

	inline Color::Color(const ColorF& col)
		:	Color{ col.col }
	{

	}

	inline Color& Color::operator = (const Color& col)
	{
		c = col.c;
		return *this;
	}

	inline Color& Color::operator = (const ColorF& col)
	{
		return *this = col.col;
	}

	inline Color& Color::operator = (unsigned rgb)
	{
		r = g = b = (rgb & 0xFF);
		a = 255;
		return *this;
	}

	inline Color& Color::operator = (Palette col)
	{
		c = static_cast<unsigned>(col);
		return *this;
	}

	inline Color Color::operator ~ () const
	{
		Color col;
		col.c = ~c;
		col.a = a;
		return col;
	}

	inline bool Color::operator == (const Color& col) const
	{
		return code == col.code;
	}

	inline bool Color::operator != (const Color& col) const
	{
		return code != col.code;
	}

	inline Color& Color::set(unsigned _r, unsigned _g, unsigned _b, unsigned _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
		return *this;
	}

	inline Color& Color::setAlpha(unsigned alpha)
	{
		a = alpha;
		return *this;
	}

	inline unsigned Color::_get_code() const
	{
		return c;
	}

	inline unsigned char Color::_get_grayscale() const
	{
		return static_cast<unsigned char>(0.299*r + 0.587*g + 0.114*b);
	}
}
