/**
*
*	@author	yamada masamitsu
*	@date	2014.11.06
*
*/
#pragma once
#include "SlimeActor.h"

class CSlimeBlue:public CSlimeActor
{
public:
	CSlimeBlue(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type,CResource::MonsterUIType soul_type);

	void Start();
	void Update();
	void Draw();

	static int MaxHp(){ return max_hp; }
	static int AttackPower(){ return attack_power; };
	static int SoulPoint(){ return soul_point; };
	static float JumpPower(){ return jump_power; };
	static float Mass(){ return mass; };
	static float Speed(){ return speed; };
private:
	static int max_hp;
	static int attack_power;
	static int soul_point;
	static float jump_power;
	static float mass;
	static float speed;

	void IniDataList();

	void Attack();
	void InitAttack();
};

