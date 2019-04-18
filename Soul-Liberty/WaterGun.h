/**
*
*	@author	yamada masamitsu
*	@date	2014.10.07
*
*/

#pragma once
#include "Transform.h"
#include "WaterParticle.h"

class CWaterGun
{
public:
	CWaterGun(Float3 pos, Float3 target_pos);
	CWaterGun(Float3 pos, int direction);

	void Update();
	void Draw();
	void Finish();
	enum class State
	{
		None,
		Live,
		Effect,
	};
	Transform transform;
	bool IsCollision()const{ return(state == State::Live); }
	bool IsDelete()const{ return(state == State::None); }
private:
	void Move();
	void Effect();

	std::unique_ptr<CWaterParticleSystem> particle;
	State state;
	Float3 velocity;
};

