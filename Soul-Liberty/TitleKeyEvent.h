
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <memory>
#include "Scene.h"

class CTitleManager;

///	タイトルキーイベント
class CTitleKeyEvent
{
public:

	///	初期化
	void Init(CTitleManager *title);

	///	シーンを変更
	void ChangeSceneMenu(std::shared_ptr<CSceneManager> scene);

	///	アップデート
	void Update(CTitleManager *title);

	CSceneManager::Scene GetSelectNowScene()const{ return select_scene; }
private:
	///	選択シーン
	void SelectScene(CTitleManager *title);
	
	///	キー押した処理
	void PushKey();

	std::shared_ptr<CSceneManager> scene;	///<	シーン管理
	CSceneManager::Scene select_scene;		///<	選択シーン
	bool push_key;	///<	押したかどうか？
};

