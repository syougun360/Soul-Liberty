
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.10
*
*/
#pragma once
#include "GameOpening.h"
#include "Transform.h"

class COpeningRecovery:public OpeningScene
{
public:
	COpeningRecovery();

	void Update();
	void Draw();

private:
	void SoulRelease();

	enum class SoulState
	{
		Stop,
		Release,
	};
	SoulState soul_state;
	Transform soul;
	Float3 velocity;
};

