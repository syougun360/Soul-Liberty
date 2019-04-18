
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include "Actor.h"

class CDoorLeft;
class CDoorRight;

class CDoorManager:public CActor
{
public:
	CDoorManager(std::shared_ptr<CTask> task, Float3 pos);

	void OnHit();
	void Update();
	void Draw();
	
private:
	std::unique_ptr<CDoorLeft> left;
	std::unique_ptr<CDoorRight> right;
};

