#pragma once
#include "Actor.h"
#include "Resource.h"

class CDescriptionBoard:public CActor
{
public:
	CDescriptionBoard(Float3 pos,CResource::DescriptionType);

	void Update();
	void Draw();

private:
	CResource::DescriptionType type;
};

