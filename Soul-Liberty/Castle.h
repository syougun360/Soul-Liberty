
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/

#pragma once
#include "GameStage.h"
#include "Camera.h"
#include "MonsterCastle.h"
class CCastle :public CGameStage
{
public:
	CCastle();

	void EventUpdate();
	void EventDraw();
	void Draw();

private:
	void CameraFixed();
	void CameraZoom();
	std::unique_ptr<CCamera> camera;
	std::vector<std::unique_ptr<CMonsterCastle>> monsters;
	int count;
};

