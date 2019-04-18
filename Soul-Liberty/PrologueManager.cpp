#include "PrologueManager.h"
#include "GameApplication.h"
#include "MobPeople.h"
#include "PrologueDevil.h"
#include "CharacterController.h"
#include "PrologueDevilMagic.h"
#include "MobToEnemyMob.h"
#include "Resource.h"
CPrologueManager::CPrologueManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager)
{
}

void CPrologueManager::Init()
{

	CResource::GetInstance().PlayBGM(CBGMData::BGM::Prologue);

	scene_table.clear();

	scene_table.insert(std::make_pair(Scene::MobPeople, std::make_shared<CMobPeople>()));
	scene_table.insert(std::make_pair(Scene::Devil, std::make_shared<CPrologueDevil>()));
	scene_table.insert(std::make_pair(Scene::DevilMagic, std::make_shared<CPrologueDevilMagic>()));
	scene_table.insert(std::make_pair(Scene::EnemyPeople, std::make_shared<CMobToEnemyMob>()));

	next_scene = scene_table.find(Scene::MobPeople)->second;

	isFade = false;
	alpha = 0.0;
	state = State::Init;
}

//　次のシーンに行かせる処理
void CPrologueManager::ChangeScene()
{
	if (isFade) return;
	if (!scene->IsEnd()) return;
	if (ChangeAppScene()) return;

	this->next_scene = scene_table.find(scene->GetNextScene())->second;
	isFade = true;
	alpha = 0.0;

}

void CPrologueManager::FadeOut()
{
	if (!isFade) return;

	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha += 0.03;
	if (alpha >= 1)
	{
		state = State::Init;
	}
}

void CPrologueManager::SceneInit()
{
	if (state != State::Init) return;

	isFade = false;
	scene = next_scene;
	state = State::Update;
}

bool CPrologueManager::ChangeAppScene()
{
	if (scene->GetNextScene() != Scene::End) return false;
	
	app_scene->ChangeScene(CSceneManager::Scene::GameOpening);
	return true;
}

void CPrologueManager::SceneUpdate()
{
	if (state != State::Update) return;

	scene->Update();
	ChangeScene();
	if (CharacterController::ChangeSceneKey())
	{
		app_scene->ChangeScene(CSceneManager::Scene::GameOpening);
	}
}

//　シーン管理のアップデート
void CPrologueManager::Update()
{
	SceneInit();
	SceneUpdate();
	scene->Draw();
	FadeOut();
}
