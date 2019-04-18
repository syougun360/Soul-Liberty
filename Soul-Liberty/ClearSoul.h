#pragma once
#include "Actor.h"

class CClearSoul:public CActor
{
public:
	CClearSoul(Float3 mob_pos);

	void Update();
	void Draw();
	bool IsHit()const{ return state == State::None; }
private:
	Float3 mob_pos;
};

