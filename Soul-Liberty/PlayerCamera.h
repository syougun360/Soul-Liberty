/**
*
*	@author	yamada masamitsu
*	@date	2014.10.04
*
*/
#pragma once
#include "PlayerState.h"
#include "Camera.h"
#include "Light.h"

class CPlayerCamera:public CPlayerState
{
public:
	CPlayerCamera();

	void Update();
	void Start(std::shared_ptr<CPlayer> player);

	void BossInField();

	Float3 GetPos()const;
private:
	
	void Move();
	void BossInFiledMove();

	std::unique_ptr<CLight> light;		///<	ƒ‰ƒCƒg
	std::unique_ptr<CCamera> camera;	///<	ƒJƒƒ‰

};

