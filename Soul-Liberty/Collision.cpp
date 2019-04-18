// ------------------------------------------------
//			あたり判定
//					code by yamada masamitsu
// ------------------------------------------------
#include "Collision.h"

namespace collision
{
	//　Box And Sphere Collision
	bool CubeToSphere(const Float3& cube_pos, const Float3& cube_scale, const Float3& sphere_pos, float sphere_radius)
	{
		float dist_squared = sphere_radius * sphere_radius;

		const Float3 BoxMin = cube_pos;
		const Float3 BoxMax = Float3(cube_pos.x + cube_scale.x / 2, cube_pos.y + cube_scale.y / 2, cube_pos.z + cube_scale.z / 2);

		if (sphere_pos.x < BoxMin.x){
			dist_squared -= Squared(sphere_pos.x - BoxMin.x);
		}
		else if (sphere_pos.x > BoxMax.x){
			dist_squared -= Squared(sphere_pos.x - BoxMax.x);
		}
		if (sphere_pos.y < BoxMin.y){
			dist_squared -= Squared(sphere_pos.y - BoxMin.y);
		}
		else if (sphere_pos.y > BoxMax.y){
			dist_squared -= Squared(sphere_pos.y - BoxMax.y);
		}
		if (sphere_pos.z < BoxMin.z) {
			dist_squared -= Squared(sphere_pos.z - BoxMin.z);
		}
		else if (sphere_pos.z > BoxMax.z){
			dist_squared -= Squared(sphere_pos.z - BoxMax.z);
		}
		return dist_squared > 0;
	}

	// ボックスのあたり判定 2D
	bool RectToRect(const Float3& pos, const Float3& size, const Float3& col_pos, const Float3& col_size)
	{

		const float x0 = pos.x;
		const float y0 = pos.y;
		const float x1 = pos.x + size.x - 1;
		const float y1 = pos.y + size.y - 1;

		const float x2 = col_pos.x;
		const float y2 = col_pos.y;
		const float x3 = col_pos.x + col_size.x - 1;
		const float y3 = col_pos.y + col_size.y - 1;

		//	二つの矩形が何かしらの形で重なっているか？
		if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
		{
			//	重なっていた
			return true;
		}

		//	重なってなかった
		return false;
	}


	// 球のあたり判定
	bool CircleToCircle(const Float2& pos1, const Float2& col_pos, const float r1, const float r2)
	{
		const Float2 vec = col_pos - pos1;
		const float r = (r1 + r2);

		if ((vec.x*vec.x + vec.y*vec.y < r*r))	{
			return true;
		}
		else{
			return false;
		}
	};

	// 球体のあたり判定
	bool SphereToSphere(const Float3& pos1, const Float3& col_pos, const float r1, const float r2)
	{
		Float3 vec;
		vec.x = (col_pos.x - pos1.x);
		vec.y = (col_pos.y - pos1.y);
		vec.z = (col_pos.z - pos1.z);
		float r = (r1 + r2);

		if ((vec.x*vec.x + vec.y*vec.y + vec.z*vec.z < r*r))	{
			return true;
		}
		else{
			return false;
		}
	};

	//　ボックスのあたり判定
	bool AABBToAABB(const Float3 &obj, const Float3 &size, const Float3 &col_pos, const Float3 &col_size)
	{

		if (Abs(obj.x - col_pos.x) > (size.x / 2 + col_size.x / 2) + 1)
			return false;

		if (Abs(obj.y - col_pos.y) > (size.y / 2 + col_size.y / 2) + 1)
			return false;

		if (Abs(obj.z - col_pos.z) > (size.z / 2 + col_size.z / 2) + 1)
			return false;


		return true;
	}
}