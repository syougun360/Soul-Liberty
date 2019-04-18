/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include "Resource.h"
struct MonsterUI
{
	MonsterUI(Point pos, Point pos_adjustment, CResource::MonsterUIType type) :
		pos(pos), type(type), pos_adjustment(pos_adjustment){}

	Point pos;
	Point pos_adjustment;
	CResource::MonsterUIType type;
};
