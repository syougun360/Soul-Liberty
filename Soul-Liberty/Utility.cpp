// ------------------------------------------------
//			実用関数
//					code by yamada masamitsu
// ------------------------------------------------
#include "Utility.h"

namespace utility
{

	bool IsMouseIncludeRectPointer(const Point& pos, const Point& size)
	{
		const int mouse_radius = 10;
		const Point mouse_pos1 = Mouse::Pos();
		Point mouse_pos2 = pos + Point(mouse_radius, mouse_radius);

		Point col_pos1 = pos;
		Point col_pos2 = pos + size;
		
		if (col_pos1.x <= mouse_pos1.x &&
			col_pos2.x >= mouse_pos1.x &&
			col_pos1.y <= mouse_pos1.y &&
			col_pos2.y >= mouse_pos1.y)
		{
			return true;
		}

		return false;
	}
	bool IsMouseIncludeCirclePointer(const Point& pos, const int radius)
	{
		const Point mouse_pos = Mouse::Pos();
		const int mouse_radius = 2;

		const int dx = pos.x - mouse_pos.x;//水平方向の距離
		const int dy = pos.y - mouse_pos.y;//鉛直方向の距離
		const int r = radius + mouse_radius;//半径の和

		//三平方の定理
		return ((dx*dx) + (dy*dy) < (r*r));
	}

	// 点を(target1,target2)を中心にang角回転する
	void CircleRotation(float &pos1, float &pos2, const float ang, const float targetpos1, const float targetpos2)
	{
		const float ox = pos1 - targetpos1, oy = pos2 - targetpos2;
		pos1 = ox * cos(ang) + oy * sin(ang);
		pos2 = -ox * sin(ang) + oy * cos(ang);
		pos1 += targetpos1;
		pos2 += targetpos2;

	}

	//　指定位置に移動
	void MoveTo(const Float3 goal_pos, Float3 &pos, const Float3 velocity)
	{
		const Float3 dist = goal_pos - pos;

		float lengh = sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);

		pos += dist / lengh * velocity;
	}
	void MoveTo(const Float2 goal_pos, Float2 &pos, const Float2 velocity)
	{
		const Float2 dist = goal_pos - pos;

		float lengh = sqrt(dist.x * dist.x + dist.y * dist.y);

		pos += dist / lengh * velocity;
	}

	//　指定した方向に移動する
	Float3 MoveBy(const Float3 &pos, const  Float3& goal_pos, const float speed)
	{
		const Float3 dist = goal_pos - pos;

		float lengh = sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);

		return dist / lengh * speed;

	}

	//　距離を測る
	float Distance(const Float3 goal_pos, const Float3 start_pos)
	{

		const Float3 dist = goal_pos - start_pos;

		return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);

	}
	float Distance(const float goal_pos, const float start_pos)
	{

		const float dist = goal_pos - start_pos;

		return sqrt(dist * dist);

	}


	// ジオメトリにマッピングしたテクスチャを反転
	Mesh CreateMirroredBox(const Float3& size,const int dir)
	{
		MeshObject meshObject = Geometry3D::CreateBox(size);

		for (auto& vertex : meshObject.vertices)
		{
			vertex.texcoord.x = dir * vertex.texcoord.x;
		}

		return Mesh(meshObject);
	}

}