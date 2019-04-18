#include "Transform.h"


Transform::Transform(Float3 pos, Float3 scale, Float3 rotation) :
pos(pos), scale(scale), rotation(rotation)
{

}


///	���W���s�ړ�
void Transform::Translate(const Float3& value)
{
	pos += value;
}

///	�w��ʒu�ɕϊ�
void Transform::TransformPoint(const Float3& value)
{
	pos = value;
}

///	��]�����ړ�
void Transform::Rotation(const Float3& value)
{
	rotation += value;
}

///	�w�莲�ɕϊ�
void Transform::LookAt(const Float3& value)
{
	rotation = value;
}

///	�X�P�[����傫������
void Transform::Scaling(const Float3& value)
{
	scale += value;
}

///	�w��X�P�[���ɕϊ�
void Transform::TransformScale(const Float3& value)
{
	scale = value;
}
