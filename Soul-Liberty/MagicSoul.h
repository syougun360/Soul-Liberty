/**
*
*	@author	yamada masamitsu
*	@date	2014.12.01
*
*/

#pragma once
#include "BossAttackState.h"
#include "Particle.h"

class CMagicSoul :public CBossAttackState
{
public:
	CMagicSoul();

	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();


private:
	//	ヒット時処理
	void OnHit();

	//	チャージ処理
	void Charge();

	//	移動処理
	void Move();

	//	パーティクルのアップデート
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;
	int count;
};

