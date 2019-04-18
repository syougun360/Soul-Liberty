//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

template<typename SizeType, typename ElementType>
inline SizeType s3d::Rectangle<SizeType, ElementType>::_get_tl() const
{
	return pos;
}

template<typename SizeType, typename ElementType>
inline SizeType s3d::Rectangle<SizeType, ElementType>::_get_tr() const
{
	return { x + w - 1, y };
}

template<typename SizeType, typename ElementType>
inline SizeType s3d::Rectangle<SizeType, ElementType>::_get_bl() const
{
	return { x, y + h - 1};
}

template<typename SizeType, typename ElementType>
inline SizeType s3d::Rectangle<SizeType, ElementType>::_get_br() const
{
	return { x + w - 1, y + h - 1 };
}

template<typename SizeType, typename ElementType>
inline SizeType s3d::Rectangle<SizeType, ElementType>::_get_center() const
{
	return { x + w/2, y + h/2 };
}

template<typename SizeType, typename ElementType>
inline s3d::Line s3d::Rectangle<SizeType, ElementType>::_get_top() const
{
	return { tl, tr };
}

template<typename SizeType, typename ElementType>
inline s3d::Line s3d::Rectangle<SizeType, ElementType>::_get_right() const
{
	return { tr, br };
}

template<typename SizeType, typename ElementType>
inline s3d::Line s3d::Rectangle<SizeType, ElementType>::_get_bottom() const
{
	return { br, bl };
}

template<typename SizeType, typename ElementType>
inline s3d::Line s3d::Rectangle<SizeType, ElementType>::_get_left() const
{
	return { bl, tl };
}

template<typename SizeType, typename ElementType>
inline s3d::Rectangle<SizeType, ElementType> s3d::Rectangle<SizeType, ElementType>::stretched(ElementType xy) const
{
	return stretched({ xy, xy });
}

template<typename SizeType, typename ElementType>
inline s3d::Rectangle<SizeType, ElementType> s3d::Rectangle<SizeType, ElementType>::stretched(ElementType _x, ElementType _y) const
{
	return stretched({ _x, _y });
}

template<typename SizeType, typename ElementType>
inline s3d::Rectangle<SizeType, ElementType> s3d::Rectangle<SizeType, ElementType>::stretched(const SizeType& xy) const
{
	return { pos - xy, size + xy*2 };
}

/*
inline s3d::Quad s3d::Rect::rotate(double angle) const
{
	const Vec2 center(x + w*0.5, y + h*0.5);
	const double x = center.x;
	const double y = center.y;
	const double x0 = -size.x * 0.5f;
	const double x1 = size.x * 0.5f;
	const double y0 = -size.y * 0.5f;
	const double y1 = size.y * 0.5f;
	const double s = ::sin(angle);
	const double c = ::cos(angle);
	const double x0c = x0*c;
	const double x0s = x0*s;
	const double x1c = x1*c;
	const double x1s = x1*s;
	const double y0c = y0*c;
	const double y0s = y0*s;
	const double y1c = y1*c;
	const double y1s = y1*s;
	return s3d::Quad(Vec2(x0c - y0s + x, x0s + y0c + y), Vec2(x1c - y0s + x, x1s + y0c + y), Vec2(x1c - y1s + x, x1s + y1c + y), Vec2(x0c - y1s + x, x0s + y1c + y));
}

inline s3d::Quad s3d::RectF::rotate(double radian) const
{
	const Vec2 center(x + w*0.5, y + h*0.5);
	const double x = center.x;
	const double y = center.y;
	const double x0 = -size.x * 0.5f;
	const double x1 = size.x * 0.5f;
	const double y0 = -size.y * 0.5f;
	const double y1 = size.y * 0.5f;
	const double s = ::sin(radian);
	const double c = ::cos(radian);
	const double x0c = x0*c;
	const double x0s = x0*s;
	const double x1c = x1*c;
	const double x1s = x1*s;
	const double y0c = y0*c;
	const double y0s = y0*s;
	const double y1c = y1*c;
	const double y1s = y1*s;
	return s3d::Quad(Vec2(x0c - y0s + x, x0s + y0c + y), Vec2(x1c - y0s + x, x1s + y0c + y), Vec2(x1c - y1s + x, x1s + y1c + y), Vec2(x0c - y1s + x, x0s + y1c + y));
}
*/
