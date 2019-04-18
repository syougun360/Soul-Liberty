#pragma once
#include "BossAttackState.h"

class CCreateEnemy :public CBossAttackState
{
public:
	CCreateEnemy();

	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();

private:

	int count;
};

