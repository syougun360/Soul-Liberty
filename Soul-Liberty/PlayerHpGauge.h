/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/
#pragma once
#include <siv3D.hpp>
#include "PlayerState.h"

class CPlayerHpGauge:public CPlayerState
{
public:
	CPlayerHpGauge();

	void IniData(INIReader ini);
	void Update();
	void Draw();
	void Damage(const int power);

private:
	float hp;
	float now_hp;
	static float max_hp;
	Float2 size;
	Float2 pos;

};

