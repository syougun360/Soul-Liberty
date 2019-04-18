
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once

#include "Scene.h"
#include "SubScene.h"
#include <map>

///	クリア管理
class CClearManager :public CScene
{
public:
	CClearManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	enum class Scene
	{
		Castle,
		Mob,
		End,
	};
private:

	//　次のシーンに行かせる処理
	void ChangeScene();

	///	フェードアウト
	void FadeOut();

	///	シーンの初期化
	void SceneInit();

	///	シーンのアップデート
	void SceneUpdate();

	//	アプリシーンを変更
	bool ChangeAppScene();

	//　シーン管理の状態
	enum class State
	{
		Init,	///<	初期化
		Update,	///<	アップデート処理
		End,
	};

	std::shared_ptr<CSubScene<CClearManager::Scene> > scene;		///<	シーンのインスタンス
	std::shared_ptr<CSubScene<CClearManager::Scene> > next_scene;	///<	シーンのインスタンス

	std::map<Scene, std::shared_ptr<CSubScene<CClearManager::Scene> >> scene_table;

	State state;	///<	シーン管理の状態
	double alpha;	///<	フェードアウト用の変数
	bool isFade;	///<	フェードアウトフラグ
};

typedef CSubScene<CClearManager::Scene> ClearScene;