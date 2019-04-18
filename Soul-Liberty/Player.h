
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <map>
#include "Actor.h"
#include "GraphicAnimation.h"

class CPlayerMove;
class CPlayerCamera;
class CPlayerJump;
class CPlayerAttack;
class CPlayerAvoidance;
class CPlayerDamage;
class CPlayerGravity;
class CPlayerHpGauge;
class CCombine;
struct MagicBackGraphic;

///	�v���C���[�{��
class CPlayer:public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task,Float3 pos);

	enum class AnimationType
	{
		Standing,
		Move,
		JumpStep1,
		JumpStep2,
		Attack_1,
		Attack_2,
		Attack_3,
		Attack_4,
		Damage,
		Death,
		Call,
		Avoidance,
	};

	void Start();
	void Update();
	void Draw();

	void DirectionRight();
	void DirectionLeft();

	///	���̃X�e�[�W�ɍs�����߂̃C�x���g
	void NextStageEventUpdate();

	///	�A�j���[�V�����ݒ�
	void OnAnimation(AnimationType type);

	///	���������X�^�[������
	void MonsterCall();

	///	���ߍU���ړ�����
	void OnSpecialAttackMove();

	//	�U���̂����蔻����Ȃ���
	void AttackNonCollision();

	///	���̏���
	void Combine();

	///	���x����
	void SpeedDown();

	///	�U����������������
	void AttackHit();

	///	�{�X��Field�ɓ��鏈��
	void BossInField();

	//	���S����
	void Death();

	///	�_���[�W����
	void Damage(const int power);

	//	�_���[�W��傫���A�N�V��������
	void DamageLargeAction();

	//	�������[�V�����̃A�j���[�V�����ɐݒ�
	void SetStandingAnimation();

	///	�t�F���X�̏Փˏ���
	void FenceCollision();

	Direction GetDirection()const{ return direction; }

	Float3 GetCameraPos()const;

	///	�U���̂����蔻����W
	Float3 GetAttackCollisionPos();

	///	�ړ��ʂ��擾
	Float3 GetVelocity()const;

	///	�U���̂����蔻��͈�
	float GetAttackCollisionRadius();

	///	�U����
	int GetAttacPower()const;

	///	�U�����Ă邩�ǂ���
	bool IsNowAttack()const;

	///	�O�Ɉړ��ł��邩�ǂ���
	bool IsForwardMove()const;

	///	������Ă��邩�ǂ���
	bool IsNowAvoid()const;

	///	�d��
	bool IsGravity();

	///	�W�����v�̏Փˏ���
	bool IsJumpCollision();

	///	���̏Փˏ���
	bool IsFrontCollision();
	bool IsBackCollision();

	///	�W�����v���Ă��邩�ǂ���
	bool IsNowJump()const;

	///	�_���[�W���󂯂Ă��邩�ǂ���
	bool IsNowDamage()const;

	///	��_���[�W���󂯂Ă��邩�ǂ���
	bool IsLargeAction()const;

	///	�ړ����Ă��邩�ǂ���
	bool IsNowMove()const;

	///	���݁A�U�������蔻�肪���邩�ǂ���
	bool IsNowCollisionAttack()const;

	bool IsBossFiledNowEvent()const{ return (state == State::BossInFiled); }

	///	�����A�j���[�V�������Ă��邩�ǂ���
	bool IsSummonsCallAnimation()const{ return (state == State::Call); }

	static const float Mass;
private:
	//	ini�f�[�^��List
	void IniDataList();

	//	Animation��o�^
	void SignUpAnimation();
	
	///	�ړ�����
	void Move();

	///	�摜��`��
	void GraphicDraw();

	//	�{�X�t�B�[���h�̃C�x���g
	void BossFieldEvent();

	//	�ړ��ł���͈�
	void MoveRange();
	
	//	�h�A�̓���������
	void OnHitDoor();

	std::unique_ptr<CPlayerMove> move;		///<	�ړ�����
	std::unique_ptr<CPlayerCamera> camera;	///<	�J��������
	std::unique_ptr<CPlayerJump> jump;		///<	�W�����v����
	std::unique_ptr<CPlayerAttack> attack;	///<	�U������
	std::unique_ptr<CPlayerGravity> gravity;	///<	�d�͏���
	std::unique_ptr<CPlayerAvoidance> avoidance;	///<	�������
	std::unique_ptr<CPlayerDamage> damage;			///<	�_���[�W����
	std::unique_ptr<CPlayerHpGauge> hp_gauge;		///<	�̗̓Q�[�W
	std::unique_ptr<CCombine> combine;				///<	����

	std::shared_ptr<CGraphicAnimation<AnimationType>> animation;
	Mesh left;
	Mesh right;
	Direction direction;
};

