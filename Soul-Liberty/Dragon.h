/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossActor.h"

class CBossAttackState;
class CKing;

//	hS
class CDragon:public CBossActor
{
public:
	CDragon(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();

private:

	//	Uνή
	enum class AttackType
	{
		Flame,
		Breath,
		FlyBreath,
		MaxType,
	};

	//	Character`ζ
	void CharacterDraw();

	//	ΜΝ
	void HitPoint(const int power);

	//	Uυ
	void AttackPreparation();

	//	UIΉ
	void AttackFinish();

	//	Uνήπέθ
	void SetAttackType();

	//	_[W
	void Damage(const int power);

	//	U
	void Attack();

	//	S
	void Death();

	std::map<AttackType, std::shared_ptr<CBossAttackState>> attack_table;
	std::shared_ptr<CBossAttackState> attack;
	AttackType attack_type;
	std::unique_ptr<CKing> king;
	int death_count;
};

