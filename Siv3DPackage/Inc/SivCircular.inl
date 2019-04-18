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
	inline Circular Circular::operator + () const
	{
		return *this;
	}

	inline Circular Circular::operator - () const
	{
		return { r, theta + Math::Pi };
	}

	inline Vec2 Circular::operator + (const Vec2& v) const
	{
		return operator Vec2() + v;
	}

	inline Vec2 Circular::operator - (const Vec2& v) const
	{
		return operator Vec2() - v;
	}

	inline Circular::operator Vec2() const
	{
		return { ::sin(theta)*r, -::cos(theta)*r };
	}
}
