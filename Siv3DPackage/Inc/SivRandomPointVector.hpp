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
# include <utility>
# include "SivRandom.hpp"
# include "SivPointVector.hpp"

namespace s3d
{
	inline
	Point
		RandomPoint(
		const std::pair<int, int>& xMinMax,
		const std::pair<int, int>& yMinMax
		)
	{
		Point p;
		p.x = Random(xMinMax.first, xMinMax.second);
		p.y = Random(yMinMax.first, yMinMax.second);
		return p;
	}

	inline
	Point
		RandomPoint(
		int xMax,
		int yMax
		)
	{
		return RandomPoint({ 0, xMax }, { 0, yMax });
	}

	inline
	Vec2
		RandomVec2(
		const std::pair<double, double>& xMinMax,
		const std::pair<double, double>& yMinMax
		)
	{
		Vec2 v;
		v.x = Random(xMinMax.first, xMinMax.second);
		v.y = Random(yMinMax.first, yMinMax.second);
		return v;
	}

	inline
	Vec2
		RandomVec2(
		double xMax,
		double yMax
		)
	{
		return RandomVec2({ 0.0, xMax }, { 0.0, yMax });
	}

	inline
	Vec3
		RandomVec3(
		const std::pair<double, double>& xMinMax,
		const std::pair<double, double>& yMinMax,
		const std::pair<double, double>& zMinMax
		)
	{
		Vec3 v;
		v.x = Random(xMinMax.first, xMinMax.second);
		v.y = Random(yMinMax.first, yMinMax.second);
		v.z = Random(zMinMax.first, zMinMax.second);
		return v;
	}

	inline
	Vec3
		RandomVec3(
		double xMax,
		double yMax,
		double zMax
		)
	{
		return RandomVec3({ 0.0, xMax }, { 0.0, yMax }, { 0.0, zMax });
	}

	inline
	Vec4
		RandomVec4(
		const std::pair<double, double>& xMinMax,
		const std::pair<double, double>& yMinMax,
		const std::pair<double, double>& zMinMax,
		const std::pair<double, double>& wMinMax
		)
	{
		Vec4 v;
		v.x = Random(xMinMax.first, xMinMax.second);
		v.y = Random(yMinMax.first, yMinMax.second);
		v.z = Random(zMinMax.first, zMinMax.second);
		v.w = Random(wMinMax.first, wMinMax.second);
		return v;
	}

	inline
	Vec4
		RandomVec4(
		double xMax,
		double yMax,
		double zMax,
		double wMax
		)
	{
		return RandomVec4({ 0.0, xMax }, { 0.0, yMax }, { 0.0, zMax }, { 0.0, wMax });
	}
}
