
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <Siv3D.hpp>
#include "Transform.h"

///	�J�����N���X
class CCamera :public Transform
{
public:
	CCamera(Float3 pos, Float3 lookat);

	void Update();

private:
	void Move();

	Float3 upvec;				//�@����
	const static float Near ;	//�@������߂��͈�
	const static float Far ;	//�@�����鉓���͈�
	const static float degree ;	// �Y�[��
	const static float Speed;	// ���x

};

