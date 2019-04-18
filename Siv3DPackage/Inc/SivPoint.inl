//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# include <cassert>

inline s3d::Point s3d::Point::_get_xx() const
{
	return { x, x };
}

inline s3d::Point s3d::Point::_get_xy() const
{
	return { x, y };
}

inline s3d::Point s3d::Point::_get_yx() const
{
	return { y, x };
}

inline s3d::Point s3d::Point::_get_yy() const
{
	return { y, y };
}

inline s3d::Point s3d::Point::operator + () const
{
	return *this;
}

inline s3d::Point s3d::Point::operator - () const
{
	return { -x, -y };
}

inline s3d::Point s3d::Point::operator + (const s3d::Point& p) const
{
	return { x + p.x, y + p.y };
}

inline s3d::Point s3d::Point::operator - (const s3d::Point& p) const
{
	return { x - p.x, y - p.y };
}

inline s3d::Point s3d::Point::operator * (int s) const
{
	return { x*s, y*s };
}

inline s3d::Vec2 s3d::Point::operator * (double s) const
{
	return { x*s, y*s };
}

inline s3d::Point s3d::Point::operator * (const Point& p) const
{
	return { x*p.x, y*p.y };
}

inline s3d::Point s3d::Point::operator / (int s) const
{
	return { x/s, y/s };
}

inline s3d::Vec2 s3d::Point::operator / (double s) const
{
	return { x / s, y / s };
}

inline s3d::Point& s3d::Point::operator += (const s3d::Point& p)
{
	x += p.x;
	y += p.y;
	return *this;
}

inline s3d::Point& s3d::Point::operator -= (const s3d::Point& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}

inline s3d::Point& s3d::Point::operator *= (int s)
{
	x *= s;
	y *= s;
	return *this;
}

inline s3d::Point& s3d::Point::operator /= (int s)
{
	assert(s != 0);
	x /= s;
	y /= s;
	return *this;
}

inline bool s3d::Point::operator == (const s3d::Point& p) const
{
	return x == p.x && y == p.y;
}

inline bool s3d::Point::operator != (const s3d::Point& p) const
{
	return x != p.x || y != p.y;
}

inline double s3d::Point::distanceFrom(const Point& v) const
{
	return ::sqrt(distanceFromSq(v));
}

inline double s3d::Point::distanceFromSq(const Point& v) const
{
	return (v.x - x)*(v.x - x) + (v.y - y)*(v.y - y);
}

inline s3d::Point operator * (int s, const s3d::Point& p)
{
	return p*s;
}

inline s3d::Vec2 operator * (double s, const s3d::Point& p)
{
	return p*s;
}