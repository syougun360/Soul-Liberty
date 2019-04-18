#include "GameManager.h"
#include "Boneyard.h"
#include "Castle.h"
#include "GameApplication.h"
#include "Player.h"
#include "DoorManager.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"

const float CGameManager::Gravity = -9.81f;

CGameManager::CGameManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
game_object(std::make_unique<CGameObjectHousing>())
{

}

void CGameManager::NextStage()
{
	stage = Stage::Castle;
	state = State::Init;
}

void CGameManager::Init()
{
	alpha = 0.0;
	stage = Stage::Boneyard;
	state = State::Init;
}

void CGameManager::SetStage()
{
	if (stage == Stage::Boneyard)
	{
		game_stage = std::make_unique<CBoneyard>();
	}
	else if (stage == Stage::Castle)
	{
		game_stage = std::make_unique<CCastle>();
	}
}

void CGameManager::InitStage()
{
	if (state != State::Init) return;

	SetStage();
	game_object->Init(game_stage->GetMapReadData(), stage);
	state = State::Event;
	MonsterAllCallToEnable();
}

void CGameManager::MonsterAllCallToEnable()
{
	if (stage != CGameManager::Stage::Castle) return;
	auto monster = game_object->task->GetComponent<CMonsterManager>(CGameObjectHousing::MonsterManagerName, 0);
	monster->EnableToCall();

}
void CGameManager::Event()
{
	if (state != State::Event) return;
	
	game_stage->EventUpdate();
	game_stage->EventDraw();
	game_stage->FadeOut();

	if (game_stage->IsEventEnd())
	{
		alpha = 1.0f;
		state = State::FadeIn;
	}
}

void CGameManager::UpdateTask()
{
	if (state != State::Update) return;

	game_stage->Draw();
	game_object->Update();
	game_object->Draw();
	game_object->Remove();
	StageFinish();
	GameFinish();
	PlayerDeath();
}
void CGameManager::FadeOut()
{
	if (state != State::FadeOut) return;
	game_object->EventUpdate();
	game_stage->Draw();
	game_object->Draw();
	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha += 0.005;
	if (alpha >= 1)
	{
		NextStage();
	}
}

void CGameManager::FadeIn()
{
	if (state != State::FadeIn) return;

	game_stage->Draw();
	game_object->Update();
	game_object->Draw();
	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha -= 0.009;
	if (alpha <= 0)
	{
		state = State::Update;
	}
}
void CGameManager::StageFinish()
{
	if (stage != Stage::Boneyard) return;
	if (game_object->IsStageFinish())
	{
		alpha = 0;
		game_object->StageFinish();
		CResource::GetInstance().FadeStartBGM();
		state = State::FadeOut;
	}
}

void CGameManager::GameFinish()
{
	if (stage != Stage::Castle) return;
	if (game_object->IsGameFinish())
	{
		game_object->GameFinish();
		
		CResource::GetInstance().FadeStartBGM();
		app_scene->ChangeScene(CSceneManager::Scene::Clear);
	}
}
void CGameManager::PlayerDeath()
{
	if (!game_object->IsPlayerDeath()) return;

	app_scene->ChangeScene(CSceneManager::Scene::Title);
}

// ゲーム本体のアップデート
void CGameManager::Update()
{
	InitStage();
	Event();
	FadeIn();
	UpdateTask();
	FadeOut();
}
