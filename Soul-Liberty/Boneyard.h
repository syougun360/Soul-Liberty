
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/

#pragma once
#include "GameStage.h"
#include "Camera.h"
#include "Light.h"
#include "PlayerEvent.h"
#include "BackGround.h"
#include "Floor.h"
#include "MonsterEvent.h"

class CBoneyard :public CGameStage
{
public:
	CBoneyard();

	void EventUpdate();
	void EventDraw();
	void Draw();
private:
	void DescriptionBoardPlacement();
	std::shared_ptr<CPlayerEvent> player;
	std::vector<std::unique_ptr<CMonsterEvent>> monsters;
	std::unique_ptr<CLight> light;		///<	���C�g
	std::unique_ptr<CCamera> camera;	///<	�J����
	std::vector<std::unique_ptr<CFloor>> floors;
	std::shared_ptr<CActor> description_board;
};

