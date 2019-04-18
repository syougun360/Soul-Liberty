
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.03
*
*/
#pragma once
#include "Actor.h"

class CMob :public CActor
{
public:
	CMob(Float3 pos,int id,State state = State::Live);

	void Update();
	void Draw();
	void ChangeLive();

private:
	int id;
	float force;
	const float max_force;
};

