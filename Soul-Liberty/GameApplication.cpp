#include "GameApplication.h"
#include "Resource.h"
#include "TitleManager.h"
#include "GameManager.h"
#include "ClearManager.h"
#include "PrologueManager.h"
#include "InputNameEvent.h"
#include "GameOpening.h"
#include "EndRollManager.h"

const int CGameApplication::ScreenWidth = 1280;
const int CGameApplication::ScreenHeight = 720;

CGameApplication::CGameApplication():
fps(std::make_unique<CFPS>()),
scene_manager(std::make_shared<CSceneManager>(this))
{
	CResource::GetInstance();

	scene.insert(std::make_pair(CSceneManager::Scene::Title, std::make_unique<CTitleManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::NameInput, std::make_unique<CInputNameEvent>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Prologue, std::make_unique<CPrologueManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::GameOpening, std::make_unique<CGameOpening>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Game, std::make_unique<CGameManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Clear, std::make_unique<CClearManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::EndRoll, std::make_unique<CEndRollManager>(scene_manager)));

	scene_manager->ChangeScene(CSceneManager::Scene::Title);
}

std::shared_ptr<CScene> CGameApplication::SceneFind(CSceneManager::Scene scene)
{
	auto it = this->scene.find(scene);
	return it->second;
}

///	アップデート
void CGameApplication::Update()
{
	CResource::GetInstance().BGMUpdate();

	fps->Wait();
	scene_manager->Update();
	fps->Update();
}
