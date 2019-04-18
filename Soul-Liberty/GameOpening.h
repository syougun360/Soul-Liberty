
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.22
*
*/
#pragma once
#include "Scene.h"
#include "SubScene.h"
#include <map>

class CFloor;

class CGameOpening:public CScene
{
public:
	CGameOpening(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	enum class Scene
	{
		Fixing,
		Recovery,
		End,
	};

	static const Float3 TombstonePos;
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

	std::shared_ptr<CSubScene<CGameOpening::Scene> > scene;		///<	シーンのインスタンス
	std::shared_ptr<CSubScene<CGameOpening::Scene> > next_scene;	///<	シーンのインスタンス

	std::map<Scene, std::shared_ptr<CSubScene<CGameOpening::Scene> >> scene_table;

	std::vector<std::unique_ptr<CFloor>> floors;

	State state;	///<	シーン管理の状態
	float radius;	///<	フェードアウト用の変数
	bool isFade;	///<	フェードアウトフラグ

	String name_str;
	Font* name_font;
};


typedef CSubScene<CGameOpening::Scene> OpeningScene;