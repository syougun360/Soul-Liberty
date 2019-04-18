#pragma once
#include "BossActor.h"
#include "Particle.h"

class CKing:public CBossActor
{
public:
	CKing(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();
	void SmokeUpdate();
	void CharacterDraw();
private:
	void Damage(const int power);
	std::unique_ptr<CParticleSystem> particle;
	int count;
};

