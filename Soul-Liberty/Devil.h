/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossActor.h"

class CBarrier;
class CBossAttackState;

//	¤
class CDevil:public CBossActor
{
public:
	CDevil(std::shared_ptr<CTask> task,Float3 pos);

	void Update();
	void Draw();

	//	GÄ«ð¶¬
	void CreateEnemy();

private:
	//	Uõ
	void AttackPreparation();

	//	oAAbvf[g
	void BarrierUpdate();

	//	UíÞðÝè
	void SetAttackType();

	//	U
	void Attack();

	//	FieldÉüÁ½
	void InField();

	void Damage(const int power);
	enum class AttackType
	{
		CreateEnemy,
		Magic,
		MaxType,
	};
	std::unique_ptr<CBarrier> barrier;
	std::shared_ptr<CBossAttackState> attack;
	std::map<AttackType, std::shared_ptr<CBossAttackState>> attack_table;
};

