#pragma once
#include "ClearManager.h"

class CMob;
class CTask;

class CClearMobPeople:public ClearScene
{
public:
	CClearMobPeople();

	void Update();
	void Draw();

private:
	void ChangeMob();
	void MobAction();
	std::unique_ptr<CTask> task;
	int change_count;
};

