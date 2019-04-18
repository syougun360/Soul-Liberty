
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.03
*
*/
#pragma once
#include "Actor.h"
#include "Resource.h"

class CEnemyMob:public CActor
{
public:
	CEnemyMob(Float3 pos, CResource::SlimeType type, State state = State::Move);

	void Update();
	void Draw();
	void ChangeNone();
	void Flashing();

private:

	CResource::SlimeType type;
	float force;
	const float max_force;
	int count;
	int alpha;
};

