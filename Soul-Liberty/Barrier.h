/**
*
*	@author	yamada masamitsu
*	@date	2014.12.15
*
*/
#pragma once
#include "Actor.h"
#include "Particle.h"

class CDevil;
class CBarrier :public CActor
{
public:
	CBarrier();

	void Update(CDevil *devil);
	void Draw();
	void Create(Float3 pos,CDevil *devil);

private:
	std::unique_ptr<CParticleSystem> particles;


};

