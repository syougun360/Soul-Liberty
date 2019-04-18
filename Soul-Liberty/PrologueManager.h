
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <map>
#include "Scene.h"
#include "SubScene.h"

///	プロローグ管理
class CPrologueManager :public CScene
{
public:
	CPrologueManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	///	シーン
	enum class Scene
	{
		MobPeople,		//	モブ達
		Devil,			//	魔王
		DevilMagic,		//	魔王が魔法をかける
		EnemyPeople,	//	敵達
		End,			//	終了
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
	};

	std::shared_ptr<CSubScene<CPrologueManager::Scene>> scene;		///<	シーンのインスタンス
	std::shared_ptr<CSubScene<CPrologueManager::Scene>> next_scene;	///<	シーンのインスタンス
	
	std::map<Scene, std::shared_ptr<CSubScene<CPrologueManager::Scene>>> scene_table;

	State state;	///<	シーン管理の状態
	double alpha;	///<	フェードアウト用の変数
	bool isFade;	///<	フェードアウトフラグ
};

typedef CSubScene<CPrologueManager::Scene> PrologueScene;