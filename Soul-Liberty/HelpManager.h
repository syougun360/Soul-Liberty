
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "Scene.h"

class CHelpKeyEvent;

///	メニュー管理
class CHelpManager :public CScene
{
public:
	CHelpManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

private:
	Font* Logo;		///<	ロゴ
	std::unique_ptr<CHelpKeyEvent> key;	///<	キーイベント
};
