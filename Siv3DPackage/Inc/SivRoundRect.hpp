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
# include "SivRectangle.hpp"
# include "SivPolygon.hpp"

namespace s3d
{
	Polygon RoundRect(const RectF& rect, double r);

	inline Polygon RoundRect(
		double x,
		double y,
		double w,
		double h,
		double r
		)
	{
		return RoundRect({ x, y, w, h }, r);
	}
}
