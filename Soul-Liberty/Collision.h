
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <Siv3D.hpp>

///	Ç†ÇΩÇËîªíË
namespace collision
{
	// Rect And Rect Collision
	bool RectToRect(const Float3& pos, const Float3& size, const Float3& col_pos, const Float3& col_size);

	// Circle And Circle Collision
	bool CircleToCircle(const Float2& pos1, const Float2& col_pos, const float r1, const float r2);

	//Å@AABB Collision
	bool AABBToAABB(const Float3 &pos, const Float3 &size, const Float3 &col_pos, const Float3 &col_size);

	//Å@Sphere And Sphere
	bool SphereToSphere(const Float3& pos1, const Float3& col_pos, const float r1, const float r2);

	//Å@Box And Sphere Collision
	bool CubeToSphere(const Float3& cube_pos, const Float3& cube_scale, const Float3& sphere_pos, float sphere_radius);

	inline float Squared(float v) { return v * v; }

};
