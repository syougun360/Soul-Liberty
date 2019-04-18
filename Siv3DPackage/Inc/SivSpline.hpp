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

namespace s3d
{
	/**
	*	@brief
	*/
	namespace Spline
	{
		/**
		*
		*	@param p0
		*	@param p1
		*	@param p2
		*	@param a
		*	@param b
		*	@return
		*/
		template<typename Type>
		inline
		Type
			CalculateTangent(
			const Type& p0,
			const Type& p1,
			const Type& p2,
			const double a = 0.0,
			const double b = 0.0
			)
		{
			return ((1 - a)*(1 + b)) / 2 * (p1 - p0) + ((1 - a)*(1 - b)) / 2 * (p2 - p1);
		}

		/**
		*
		*	@param p0
		*	@param p1
		*	@param m0
		*	@param m1
		*	@param t
		*	@return
		*/
		template<typename Type>
		inline
		Type
			Hermite(
			const Type& p0,
			const Type& p1,
			const Type& m0,
			const Type& m1,
			const double t
			)
		{
			const double t2 = t * t;
			const double t3 = t2 * t;

			return (2 * t3 - 3 * t2 + 1)*p0 + (t3 - 2 * t2 + t)*m0 + (t3 - t2)*m1 + (-2 * t3 + 3 * t2)*p1;
		}

		/**
		*
		*	@param p0
		*	@param p1
		*	@param p2
		*	@param p3
		*	@param t
		*	@return
		*/
		template<typename Type>
		inline
		Type
			CatmullRom(
			const Type& p0,
			const Type& p1,
			const Type& p2,
			const Type& p3,
			const double t
			)
		{
			return Hermite(p1, p2, CalculateTangent(p0, p1, p2), CalculateTangent(p1, p2, p3), t);
		}
	}
}
