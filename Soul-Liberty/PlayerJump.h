/**
*
*	@author	yamada masamitsu
*	@date	2014.10.05
*
*/
#pragma once
#include "PlayerState.h"
#include "Resource.h"
class CPlayer;

class CPlayerJump :public CPlayerState
{
public:
	CPlayerJump();

	void IniData(INIReader ini);

	///	�A�b�v�f�[�g
	void Update();

	void Finish();

	enum class Step
	{
		None,
		First,
		Second,
	};

	Step GetStep()const{ return step; }

	static float MaxPower(){ return max_power; }

private:
	///	�L�[�C�x���g
	void OnKeyEvent(Step next_state, float jump_power, CPlayer::AnimationType step, CResource::SE jump_se);

	///	��Ԃ��Ȃ����ɉ�����C�x���g
	void StateNoneOnEvent();

	///	1�i�W�����v
	void FirstStep();

	///	2�i�W�����v
	void SecondStep();

	///	�����蔻�胊�X�g
	void CollisionList();

	///	�ړ�����
	void Move();

	static float max_power;

	Step step;
	float force;
};

