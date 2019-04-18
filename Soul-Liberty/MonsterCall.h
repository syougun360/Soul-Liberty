/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/


#pragma once
#include <memory>
#include <string>
#include "Resource.h"

class CMonsterCall
{
public:
	CMonsterCall(Float2 pos, Float2 absorption_pos, CResource::MonsterUIType id, int alpha = 255);

	void Update();
	void Draw();
	void MaxAlpha(){ alpha = 255; }
	CResource::MonsterUIType GetId()const{ return id; }
	int GetAlpha()const{ return alpha; }
	Float2 GetPos()const{ return pos; }
	Float2 GetAbsorptionPos()const{ return absorption_pos; }
	Float2 GetSize()const{ return size; }
private:
	int alpha;
	CResource::MonsterUIType id;
	Float2 pos;
	Float2 absorption_pos;
	Float2 size;
};

