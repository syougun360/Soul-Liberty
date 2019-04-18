
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <siv3D.hpp>
#include "Noncopyable.h"

class CSceneManager;
class CGameApplication;

// シーンの基底クラス
class CScene :private Noncopyable
{
public:
	CScene(std::shared_ptr<CSceneManager> scene) :app_scene(scene){}
	virtual ~CScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;

protected:
	std::shared_ptr<CSceneManager> app_scene;	///<	シーン管理

private:


};

//　シーン管理
class CSceneManager :private Noncopyable
{
public:
	enum class Scene;

	CSceneManager(CGameApplication* app);

	void Update();

	//　次のシーンに行かせる処理
	void ChangeScene(Scene next_scene);

	///	シーン
	enum class Scene
	{
		Title,			///<	タイトル
		Help,			///<	ヘルプ
		NameInput,		///<	名前入力
		Prologue,		///<	プロローグ
		GameOpening,	///<	Opening
		Game,			///<	ゲーム
		Clear,			///<	クリア
		EndRoll,		///<	エンドロール
	};

	///	名前を書き込む
	void NameWrite(String& name_str);

private:
	///	フェードアウト
	void FadeOut();

	///	シーンの初期化
	void SceneInit();

	///	シーンのアップデート
	void SceneUpdate();

	//　シーン管理の状態
	enum class State
	{
		Init,	///<	初期化
		Update,	///<	アップデート処理
	};

	std::shared_ptr<CScene> scene;		///<	シーンのインスタンス
	std::shared_ptr<CScene> next_scene;	///<	シーンのインスタンス
	std::shared_ptr<CGameApplication> app;	///<	アプリケーション

	State state;	///<	シーン管理の状態
	double alpha;	///<	フェードアウト用の変数
	bool isFade;	///<	フェードアウトフラグ
};

