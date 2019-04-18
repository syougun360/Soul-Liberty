/**
*
*	@author	yamada masamitsu
*	@date	2014.12.03
*
*/
#pragma once
#include "Particle.h"
#include "PrologueManager.h"

class CEnemyMobPeople;
class CMobPeople;

class CMobToEnemyMob :public PrologueScene
{
public:
	CMobToEnemyMob();

	void Update();
	void Draw();

private:
	void MobUpdate();
	void Smoke();
	void ChangeEnemy();
	void EnemyMobUpdate();
	std::unique_ptr<CParticleSystem> particle;
	std::unique_ptr<CMobPeople> mob;
	std::unique_ptr<CEnemyMobPeople> enemy;

};

