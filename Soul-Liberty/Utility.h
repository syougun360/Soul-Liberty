
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <cmath>
#include <Siv3D.hpp>

///	実用的関数
namespace utility
{
	//	指定したボックス内にマウスが存在するかどうか
	bool IsMouseIncludeRectPointer(const Point& pos, const Point& size);

	bool IsMouseIncludeCirclePointer(const Point& pos, const int radius);

	//　距離を測る
	float Distance(const Float3 goal_pos, const Float3 start_pos);
	float Distance(const float goal_pos, const float start_pos);

	//　ッ指定した範囲に含まれているかどうか
	template<typename T>
	bool IsInclude(const T value, const T value2, const T include_value)
	{
		if (abs(value - value2) < include_value)
		{
			return true;
		}
		return false;
	}

	//　指定した方向に移動する
	Float3 MoveBy(const Float3 &pos, const Float3 &goal_pos, const float speed);

	//　指定位置に移動
	void MoveTo(const Float3 goal_pos, Float3 &pos, const Float3 velocity);
	void MoveTo(const Float2 goal_pos, Float2 &pos, const Float2 velocity);

	// 円運動
	void CircleRotation(float &pos1, float &pos2, const float ang, const float targetpos1, const float targetpos2);

	// ジオメトリにマッピングしたテクスチャを反転
	Mesh CreateMirroredBox(const Float3& size, const int dir);

	//　IDを取得する場合使用する
	template<typename T>
	static int GetId()
	{
		static int id;
		return id++;
	}
}

