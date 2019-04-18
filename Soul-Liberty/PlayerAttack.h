/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/
#pragma once
#include "PlayerState.h"
#include "Transform.h"
#include <map>
#include "PlayerSpecialAttack.h"

struct AttackStep;

class CPlayerAttack:public CPlayerState
{
public:
	CPlayerAttack();

	void IniData(INIReader ini);
	void Start(std::shared_ptr<CPlayer> player);
	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();
	Transform transform;	///<	���W�A�T�C�Y�A��]

	void OnHit(){ isCollision = false; }
	int GetPower()const;
	bool IsCollision()const{ return isCollision; }

	static int LimitCollisionCount(){ return limit_collision_count; };
	static int LimitTime(){ return limit_time; }
private:
	///	����
	void Create();

	///	����U������
	void SpecialCreate();

	///	�i�K�ؑ�
	void ChangeStep();

	///	��������
	void LimitTimeUpdate();

	///	�����蔻��̐�������
	void CollisionLimitTime();

	///	���݂���ꍇ�̏���
	void Exist();

	std::map<int, std::shared_ptr<AttackStep>> step_list;	///<	�R���{���X�g
	std::shared_ptr<AttackStep> step;	///<	�R���{����
	std::unique_ptr<CPlayerSpecialAttack> special;	///<	����U��

	int now_step;			///<	���݂̒i�K�U��
	int collision_count;	///<	�����蔻��̃J�E���g
	int limit_count;	///<	�������Ԃ̃J�E���g
	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

	static int limit_collision_count;
	static int limit_time;
};

