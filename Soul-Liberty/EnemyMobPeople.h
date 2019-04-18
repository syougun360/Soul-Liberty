
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.06
*
*/
#pragma once
#include "Task.h"

class CEnemyMobPeople 
{
public:
	CEnemyMobPeople();

	void Update();
	void Draw();
private:
	void MobUpdate();
	std::shared_ptr<CTask> task;
	double alpha;
};

