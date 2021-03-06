
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	座標、大きさ、回転の情報
class Transform
{
public:
	Transform(Float3 pos, Float3 scale, Float3 rotation);

	Float3 GetPos()const{ return pos; }
	Float3 GetRotation()const{ return rotation; }
	Float3 GetScale()const{ return scale; }

	///	座標平行移動
	void Translate(const Float3& value);

	///	指定位置に変換
	void TransformPoint(const Float3& value);

	///	回転軸を移動
	void Rotation(const Float3& value);

	///	指定軸に変換
	void LookAt(const Float3& value);

	///	スケールを大きくする
	void Scaling(const Float3& value);

	///	指定スケールに変換
	void TransformScale(const Float3& value);

private:
	Float3 pos;
	Float3 rotation;
	Float3 scale;
};

