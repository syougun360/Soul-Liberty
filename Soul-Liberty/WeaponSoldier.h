/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyActor.h"
#include "GraphicAnimation.h"

class CWeaponSoldier :public CEnemyActor
{
public:

	CWeaponSoldier(std::shared_ptr<CTask> task, Float3 pos, CResource::MonsterUIType soul_type);

	void Start();
	void Update();
	void Draw();
	void StartAttack();

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
	bool IsGravity();
	void IniDataList();
	void ChangeDirection();
	void InitAttack();
	void Attack();

	static int max_hp;
	static int attack_power;
	static int soul_point;
	static float jump_power;
	static float mass;
	static float speed;

	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
	float gravity;
};

