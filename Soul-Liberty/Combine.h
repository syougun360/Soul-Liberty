/**
*
*	@author	yamada masamitsu
*	@date	2014.11.12
*
*/

#pragma once
#include "PlayerState.h"
#include "Particle.h"
#include "CombineSoul.h"

class CMonsterActor;

class CCombine:public CPlayerState
{
public:
	CCombine(const Float3& back_size);

	void OnCombine(std::shared_ptr<CMonsterActor> monster);
	void Update();
	void Draw();
	void SoulDraw();

	//	Character描画
	void CharacterDraw(const int id);

	bool IsStart()const{ return (state == State::Start); }
private:
	//	魂が登場
	void SoulAppearance();

	//	Monsterアップデート
	void MonsterUpdate();

	//	パーティクルアップデート
	void ParticleUpdate();
	
	//	透過度を減少
	void AlphaDecrease();

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CCombineSoul> soul;
	std::shared_ptr<CMonsterActor> monster;
	Color color; 
	Float3 back_size;
	Mesh left;
	Mesh right;
	int alpha;
	int count;
};

