
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "Scene.h"

class CGameStage;
class CGameObjectHousing;

class CGameManager:public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

	static const float Gravity;

	enum class Stage
	{
		Boneyard,
		Castle,
	};
private:
	//	Monsterのすべて呼び出せるようにする
	void MonsterAllCallToEnable();

	//	次のステージに行く
	void NextStage();

	//	ステージを設定
	void SetStage();

	//	ステージの初期化
	void InitStage();

	//	各ステージのイベント処理
	void Event();

	//	タスクのアップデート
	void UpdateTask();

	//	ステージ終了処理
	void StageFinish();
	
	//	ゲーム終了処理
	void GameFinish();

	//	フェードアウト
	void FadeOut();

	//	フェードイン
	void FadeIn();

	//	プレイヤーが死んだときに移りうるシーン
	void PlayerDeath();

	///<	状態
	enum class State
	{
		Init,	///<	初期化
		Event,	///<	イベント
		FadeIn,	///<	フェードイン
		Update,	///<	アップデート
		FadeOut,	///<	フェードアウト
	};


	Stage stage;
	State state;	///<	状態
	double alpha;
	std::unique_ptr<CGameStage> game_stage;
	std::unique_ptr<CGameObjectHousing> game_object;

};
