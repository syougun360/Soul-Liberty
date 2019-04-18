/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyAttack.h"
#include "Particle.h"

class CMagicAttack :public CEnemyAttack
{
public:
	CMagicAttack(const int power, const float jumpforce, const float mass, const float speed);
	
	void Update(CEnemyActor *enemy);
	void Init(CEnemyActor *enemy);
	void Draw();

private:
	//	あたり判定アップデート
	void CollisionUpdate(CEnemyActor *enemy);

	//	限界の距離
	void LimitDistance(CEnemyActor *enemy);

	//	終了処理
	void Finish(CEnemyActor *enemy);

	//	攻撃処理
	void Attack(CEnemyActor *enemy);

	//	移動処理
	void Move(CEnemyActor *enemy);

	//	準備
	void Appearance(CEnemyActor *enemy);

	//	チャージ
	void Charge(CEnemyActor *enemy);

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;

	Float3 destination;
};

