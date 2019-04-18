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
# include "SivPointVector.hpp"

namespace s3d
{
	struct Ray
	{
		Vec3 origin;

		Vec3 direction;

		Ray() = default;

		Ray(const Vec3& _origin, const Vec3& _direction)
			: origin{ _origin }
			, direction{ _direction }
		{

		}

		/**
		*
		*	@param primitive
		*	@return
		*/
		template<typename Primitive>
		bool intersects(const Primitive& primitive) const
		{
			return Geometry3D::Intersect(*this, primitive);
		}

		bool test(const Sphere& sphere, double& distance) const;

		bool test(const Box& box, double& distance) const;
	};
}
