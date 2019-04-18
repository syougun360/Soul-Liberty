
/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/

#pragma once
#include "Actor.h"
#include "Resource.h"
#include "GameManager.h"

class CFence :public CActor
{
public:
	enum class TextureType;
	CFence(std::shared_ptr<CTask> task, Float3 pos, CGameManager::Stage type);

	void Draw();


private:
	CResource::ModelType type;
};

