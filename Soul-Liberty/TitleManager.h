
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Scene.h"
#include <map>
#include "Resource.h"

class CTitleKeyEvent;
class CTitleLogo;

///	タイトル管理
class CTitleManager :public CScene
{
public:
	CTitleManager(std::shared_ptr<CSceneManager> manager);
	void Init();
	void Update();
	void Draw();

private:

	std::unique_ptr<CTitleKeyEvent> key;	///<	キーイベント
	std::map<CResource::TitleGraphicType, std::unique_ptr<CTitleLogo>> logo;	///<	ロゴ
};

