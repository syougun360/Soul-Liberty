/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossAttackState.h"
#include "Particle.h"

//	Breath（単発）
class CBreath :public CBossAttackState
{
public:
	CBreath();

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

