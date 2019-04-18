/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyActor.h"
#include "GraphicAnimation.h"

class CMagicSoldier :public CEnemyActor
{
public:

	CMagicSoldier(std::shared_ptr<CTask> task, Float3 pos,CResource::MonsterUIType soul_type);

	void Start();
	void Update();
	void Draw();
	void OnAttackFinish();

	//	�ÓI�I�u�W�F�N�g�ƏՓ˂������ǂ����iList�j
	bool IsCollisionStaticObjectList(const Transform &transform);


	static int MaxHp(){ return max_hp; }
	static int AttackPower(){ return attack_power; };
	static int SoulPoint(){ return soul_point; };
	static float JumpPower(){ return jump_power; };
	static float Mass(){ return mass; };
	static float Speed(){ return speed; };
private:
	enum class AnimationType
	{
		Move,
		Attack,
	};
	void IniDataList();

	//	�ÓI�I�u�W�F�N�g�ƏՓ˂������ǂ���
	bool IsCollisionStaticObject(const std::string &name, const Transform &transform);

	//	������ύX
	void ChangeDirection();

	//	�U��
	void Attack();

	//	�U��������
	void InitAttack();

	static int max_hp;
	static int attack_power;
	static int soul_point;
	static float jump_power;
	static float mass;
	static float speed;

	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
};

