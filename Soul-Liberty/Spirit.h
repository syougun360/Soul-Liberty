/**
*
*	@author	yamada masamitsu
*	@date	2014.11.14
*
*/

#pragma once
#include "MonsterActor.h"

class CMagicBullet;

class CSpirit :public CMonsterActor
{
public:
	CSpirit(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:
	///	合体した時の攻撃
	void CombineAttack();

	//	攻撃時の情報
	void OnAttackInfo();

	//	攻撃処理
	void Attack();

	//	攻撃終了処理
	void AttackFinish();

	//	魔法とオブジェクトのあたり判定
	void CollisionMagicToObject();

	//　魔法弾の描画
	void MagicBulletDraw();

	std::vector<std::unique_ptr<CMagicBullet>> magics;
};

