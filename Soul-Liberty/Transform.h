
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	���W�A�傫���A��]�̏��
class Transform
{
public:
	Transform(Float3 pos, Float3 scale, Float3 rotation);

	Float3 GetPos()const{ return pos; }
	Float3 GetRotation()const{ return rotation; }
	Float3 GetScale()const{ return scale; }

	///	���W���s�ړ�
	void Translate(const Float3& value);

	///	�w��ʒu�ɕϊ�
	void TransformPoint(const Float3& value);

	///	��]�����ړ�
	void Rotation(const Float3& value);

	///	�w�莲�ɕϊ�
	void LookAt(const Float3& value);

	///	�X�P�[����傫������
	void Scaling(const Float3& value);

	///	�w��X�P�[���ɕϊ�
	void TransformScale(const Float3& value);

private:
	Float3 pos;
	Float3 rotation;
	Float3 scale;
};

