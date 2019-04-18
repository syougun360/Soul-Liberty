
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.03
*
*/
#pragma once
#include "Task.h"
#include "PrologueManager.h"

class CMobPeople :public PrologueScene
{
public:
	CMobPeople();

	void MobUpdate();
	void Update();
	void Draw();
private:

	std::shared_ptr<CTask> task;
};

