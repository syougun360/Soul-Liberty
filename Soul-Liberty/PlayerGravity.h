/**
*
*	@author	yamada masamitsu
*	@date	2014.10.04
*
*/
#pragma once
#include "PlayerState.h"

class CPlayerGravity:public CPlayerState
{
public:
	CPlayerGravity();
	void Update();

	float GetGravity()const{ return gravity; }
private:
	float gravity;

};

