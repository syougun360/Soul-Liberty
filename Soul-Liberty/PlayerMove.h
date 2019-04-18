
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "PlayerState.h"
#include "FootSmoke.h"

class CPlayerMove:public CPlayerState
{
public:
	CPlayerMove();

	void IniData(INIReader ini);

	void Update();
	void Draw();
	void Finish();
	void OnSpecialAttack();

	//	���̃X�e�[�W�ɍs���C�x���g
	void NextStageEvent();

	///	��~
	void Stop();

	///	�ړ��ʂ��擾
	Float3 GetVelocity()const{ return velocity; }

	void SpeedDown();

	bool CanFootSmoke()const;

	static float LimitSpeed(){ return limit_speed; }
	static float AccelerationSpeed(){ return acceleration_speed; }
	static float MaxSpeed(){ return max_speed; }
private:
	void Normal();

	//	��Ԃ�LIVE�ς��鏈��
	void ChangeStateLive();

	///	�E�ړ�
	void Right();	

	///	���ړ�
	void Left();	

	///	�ړ��ʐݒ�
	void VelocitySpeed(const float speed);	

	///	�Փ˔��胊�X�g
	void CollisionList();
	
	///	���x�����A�b�v�f�[�g
	void SpeedDownUpdate();

	///	�����x
	struct Acceleration
	{
		Acceleration() :left(0), right(0){}
		float left, right;	///<	���E

		///	�~�܂������̏���
		void OnStop();

		///	���A�b�v�f�[�g
		void LeftUpdate();

		///	�E�A�b�v�f�[�g
		void RightUpdate();
	};

	static float limit_speed;			///<	�������x
	static float acceleration_speed;	///<	�����x�ݒ�
	static float max_speed;

	bool isSpeedDown;
	int count;
	float speed;	///<	���x
	Float3 velocity;			///<	�ړ���
	Acceleration acceleration;	///<	�����x
	std::unique_ptr<CFootSmokeSystem> foot_smoke;	///<	����
};