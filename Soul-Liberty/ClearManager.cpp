#include "ClearManager.h"
#include "ClearMobPeople.h"
#include "ClearCastleEvent.h"
#include "GameApplication.h"
#include "CharacterController.h"
#include "Resource.h"

CClearManager::CClearManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager)
{

}


void CClearManager::Init()
{

	CResource::GetInstance().PlayBGM(CBGMData::BGM::Ending);
	scene_table.clear();

	scene_table.insert(std::make_pair(Scene::Castle, std::make_shared<CClearCastleEvent>()));
	scene_table.insert(std::make_pair(Scene::Mob, std::make_shared<CClearMobPeople>()));

	next_scene = scene_table.find(Scene::Castle)->second;

	isFade = false;
	alpha = 0.0;
	state = State::Init;
}

//　次のシーンに行かせる処理
void CClearManager::ChangeScene()
{
	if (isFade) return;
	if (!scene->IsEnd()) return;
	if (ChangeAppScene()) return;

	this->next_scene = scene_table.find(scene->GetNextScene())->second;
	isFade = true;
	alpha = 0.0;

}

void CClearManager::FadeOut()
{
	if (!isFade) return;

	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha += 0.03;
	if (alpha >= 1)
	{
		state = State::Init;
	}
}

void CClearManager::SceneInit()
{
	if (state != State::Init) return;

	isFade = false;
	scene = next_scene;
	state = State::Update;
}

bool CClearManager::ChangeAppScene()
{
	if (scene->GetNextScene() != Scene::End) return false;

	CResource::GetInstance().PlaySE(CResource::SE::ChangeScene);
	app_scene->ChangeScene(CSceneManager::Scene::EndRoll);
	state = State::End;
	return true;
}

void CClearManager::SceneUpdate()
{
	if (state != State::Update) return;

	scene->Update();
	ChangeScene();
}

//　シーン管理のアップデート
void CClearManager::Update()
{
	SceneInit();
	SceneUpdate();
	scene->Draw();
	FadeOut();

	if (CharacterController::ChangeSceneKey())
	{
		app_scene->ChangeScene(CSceneManager::Scene::Title);
	}
}
