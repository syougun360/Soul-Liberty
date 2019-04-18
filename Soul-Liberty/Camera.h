
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <Siv3D.hpp>
#include "Transform.h"

///	カメラクラス
class CCamera :public Transform
{
public:
	CCamera(Float3 pos, Float3 lookat);

	void Update();

private:
	void Move();

	Float3 upvec;				//　方向
	const static float Near ;	//　見える近い範囲
	const static float Far ;	//　見える遠い範囲
	const static float degree ;	// ズーム
	const static float Speed;	// 速度

};

