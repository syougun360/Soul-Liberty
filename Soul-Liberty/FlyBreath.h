/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossAttackState.h"
#include "Particle.h"

//	飛行ブレス
class CFlyBreath :public CBossAttackState
{
public:
	CFlyBreath();

	void Start(std::shared_ptr<CBossActor> dragon);
	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();


private:
	//	飛行（上昇）
	void Fly();
	
	//	ドラゴンを下降
	void DragonDescent();

	//	ヒット時
	void OnHit();

	//	チャージ
	void Charge();

	//	移動
	void Move();

	//	パーティクルアップデート
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;
	Float3 player_pos;
	int count;
	float force;
};

