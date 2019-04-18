
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/
#pragma once
#include "BossAttackState.h"
#include "Particle.h"

//	炎（連発）
class CFlame:public CBossAttackState
{
public:
	CFlame(Float3 pos, Float3 player_pos);

	void Update();
	void Draw();

	//	ヒット時
	void OnHit();
	
private:
	//	移動
	void Move();

	//	パーティクルアップデート
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
};

//	炎管理
class CFlameManager :public CBossAttackState
{
public:
	CFlameManager();

	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();

private:
	//	終了処理
	void Finish();

	//	あたり判定アップデート
	void CollisionUpdate();

	//	静的オブジェクトあたり判定
	void CollisionStaticObject(std::unique_ptr<CFlame>& flame);
	
	//	プレイヤーあたり判定
	void CollisionPlayer(std::unique_ptr<CFlame>& flame);

	int count;
	std::vector<std::unique_ptr<CFlame>> flames;

};