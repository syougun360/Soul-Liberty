
/**
*
*	@author	yamada masamitsu
*	@date	2014.10.01
*
*/
#pragma once
#include "Actor.h"
#include "Resource.h"
#include "GameManager.h"
class CFloor :public CActor
{
public:
	enum class TextureType
	{
		Boneyard,
		Castle,
	};
	CFloor(std::shared_ptr<CTask> task, Float3 pos, CGameManager::Stage);
	CFloor(Float3 pos, CGameManager::Stage);

	void Draw();

private:
	CResource::FloorType type;
};

