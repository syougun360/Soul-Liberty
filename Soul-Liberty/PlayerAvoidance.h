/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/
#pragma once
#include "PlayerState.h"

class CPlayerAvoidance:public CPlayerState
{
public:
	CPlayerAvoidance();

	void IniData(INIReader ini);

	void Update();

	///	�I������
	void Finish();

	///	�ړ��ʂ��擾
	Float3 GetVelocity()const{ return velocity; }

	static float MaxSpeed(){ return max_speed; }
	static int LimitCount(){ return limit_count; }

private:
	///	�C�x���g��
	void OnEvent();

	///	�ړ�
	void Move();
	
	///	�����߂�
	void PushBack();

	Float3 velocity;			///<	�ړ���
	int count;


	static float max_speed;
	static int limit_count;

};

