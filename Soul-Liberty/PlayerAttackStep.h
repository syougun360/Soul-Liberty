/**
*
*	@author	yamada masamitsu
*	@date	2014.10.12
*
*/
#pragma once
#include <siv3D.hpp>

struct AttackStep
{
	AttackStep(int power)
	:power(power)
	{
	}

	///	�U���͂��擾
	int GetPower()const{ return power; }

	int power;	///<	�U����
};

