/**
*
*	@author	yamada masamitsu
*	@date	2014.11.06
*
*/
#pragma once
#include "EnemyAttack.h"

class CSlimeAttack:public CEnemyAttack
{
public:
	CSlimeAttack(const int power, const float jumpforce, const float mass, const float speed);
	
	void Update(CEnemyActor *actor);
	void Init(CEnemyActor *actor);

private:
};

