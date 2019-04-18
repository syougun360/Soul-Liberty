
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Noncopyable.h"
#include "Scene.h"
#include "FPS.h"
#include <map>

///	ゲームアプリケーション
class CGameApplication :private Noncopyable
{
public:
	CGameApplication();

	///	アップデート
	void Update();

	static const int ScreenWidth;
	static const int ScreenHeight;

	std::shared_ptr<CScene> SceneFind(CSceneManager::Scene scene);
private:
	std::map<CSceneManager::Scene, std::shared_ptr<CScene>> scene;	///<	シーン情報
	std::shared_ptr<CSceneManager> scene_manager;	///<	シーン管理
	std::unique_ptr<CFPS> fps;	///<	フレームレート
};

