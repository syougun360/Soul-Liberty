/**
*
*	@author	yamada masamitsu
*	@date	2014.12.06
*
*/
#pragma once
#include "PrologueManager.h"
#include "Particle.h"

class CPrologueDevilMagic :public PrologueScene
{
public:
	CPrologueDevilMagic();

	void Update();
	void Draw();

private:
	std::unique_ptr<CParticleSystem> particle;
};

