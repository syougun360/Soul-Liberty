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

//	魔王
class CDevil:public CBossActor
{
public:
	CDevil(std::shared_ptr<CTask> task,Float3 pos);

	void Update();
	void Draw();

	//	雑魚てきを生成
	void CreateEnemy();

private:
	//	攻撃準備
	void AttackPreparation();

	//	バリアアップデート
	void BarrierUpdate();

	//	攻撃種類を設定
	void SetAttackType();

	//	攻撃
	void Attack();

	//	Fieldに入った時
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

