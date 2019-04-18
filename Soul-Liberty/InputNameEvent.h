
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once

#include "Scene.h"
class CPlayerStartEvent;
class CInputName;

//	名前入力イベント
class CInputNameEvent :public CScene
{
public:
	CInputNameEvent(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();
	String GetName()const;
private:
	std::unique_ptr<CInputName> input_name;
	std::unique_ptr<CPlayerStartEvent> player;
};

