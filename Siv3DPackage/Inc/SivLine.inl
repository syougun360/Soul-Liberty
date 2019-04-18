//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

inline bool s3d::LineInt::operator == (const s3d::LineInt& line) const
{
	return begin == line.begin && end == line.end;
}

inline s3d::LineInt& s3d::LineInt::moveBy(int _x, int _y)
{
	begin.x += _x;
	begin.y += _y;
	end.x += _x;
	end.y += _y;

	return *this;
}

inline s3d::LineInt& s3d::LineInt::moveBy(const s3d::Point& v)
{
	begin += v;
	end += v;

	return *this;
}

inline s3d::LineInt s3d::LineInt::operator + (const s3d::Point& v) const
{
	return { begin + v, end + v };
}

inline s3d::LineInt s3d::LineInt::operator - (const s3d::Point& v) const
{
	return { begin - v, end - v };
}

inline s3d::Point s3d::LineInt::vector() const
{
	return end - begin;
}

inline double s3d::LineInt::length() const
{
	return s3d::Vec2(begin).distanceFrom(end);
}

inline double s3d::LineInt::lengthSq() const
{
	return s3d::Vec2(begin).distanceFromSq(end);
}

inline bool s3d::LineInt::operator != (const s3d::LineInt& line) const
{
	return begin != line.begin || end != line.end;
}

inline s3d::Line& s3d::Line::moveBy(double _x, double _y)
{
	begin.x += _x;
	begin.y += _y;
	end.x += _x;
	end.y += _y;

	return *this;
}

inline s3d::Line& s3d::Line::moveBy(const s3d::Vec2& v)
{
	begin += v;
	end += v;

	return *this;
}

inline s3d::Line s3d::Line::operator + (const s3d::Vec2& v) const
{
	return{ begin + v, end + v };
}

inline s3d::Line s3d::Line::operator - (const s3d::Vec2& v) const
{
	return{ begin - v, end - v };
}

inline s3d::Vec2 s3d::Line::vector() const
{
	return end - begin;
}

inline double s3d::Line::length() const
{
	return begin.distanceFrom(end);
}

inline double s3d::Line::lengthSq() const
{
	return begin.distanceFromSq(end);
}
