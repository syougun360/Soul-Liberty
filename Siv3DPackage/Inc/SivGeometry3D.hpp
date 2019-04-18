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
# include "SivPointVector.hpp"

namespace s3d
{
	enum class PlaneFace
	{
		XZ,

		XY,

		YZ,
	};

	/**
	*	@brief 3 éüå≥ê}å`ÇÃçÏê¨Ç∆äÙâΩåvéZ
	*/
	namespace Geometry3D
	{
		MeshObject
			CreatePlane(
			const Vec2& size = { 1, 1 },
			const Vec2& uvScale = { 1, 1 },
			const Vec2& uvOffset = { 0, 0 },
			PlaneFace face = PlaneFace::XZ
			);

		MeshObject
			CreatePlaneXZ(
			const Vec2& size = { 1, 1 },
			const Vec2& uvScale = { 1, 1 },
			const Vec2& uvOffset = { 0, 0 }
		);

		MeshObject
			CreatePlaneXY(
			const Vec2& size = { 1, 1 },
			const Vec2& uvScale = { 1, 1 },
			const Vec2& uvOffset = { 0, 0 }
		);

		MeshObject
			CreatePlaneYZ(
			const Vec2& size = { 1, 1 },
			const Vec2& uvScale = { 1, 1 },
			const Vec2& uvOffset = { 0, 0 }
		);

		MeshObject
			CreateBox(
			const Vec3& size = { 1, 1, 1 },
			bool flipNormals = false
			);

		MeshObject
			CreateSphere(
			double r = 1.0,
			unsigned quality = 24,
			bool flipNormals = false
			);

		MeshObject
			CreateDisc(
			double r = 1.0,
			PlaneFace face = PlaneFace::XZ,
			unsigned quality = 63
			);

		MeshObject
			CreateCylinder(
			double r = 1.0,
			double h = 1.0
			);

		MeshObject
			CreateCone(
			double r = 1.0,
			double h = 1.0
			);

		bool Intersect(const Vec3& a,	const Sphere& b);
		bool Intersect(const Vec3& a,	const Box& b);
		bool Intersect(const Sphere& a, const Vec3& b);
		bool Intersect(const Sphere& a,	const Sphere& b);
		bool Intersect(const Sphere& a, const Box& b);
		bool Intersect(const Sphere& a, const Ray& b);
		bool Intersect(const Box& a,	const Vec3& b);
		bool Intersect(const Box& a,	const Sphere& b);
		bool Intersect(const Box& a,	const Box& b);
		bool Intersect(const Box& a,	const Ray& b);
		bool Intersect(const Ray& a,	const Sphere& b);
		bool Intersect(const Ray& a,	const Box& b);
	}

	enum class PrimitiveType
	{
		Plane,

		Box,

		Sphere,

		Disc,

		Cylinder,

		Cone,

		Billboard
	};
}
