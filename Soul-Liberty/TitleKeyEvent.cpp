#include "TitleKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"
#include "GameApplication.h"
#include "TitleManager.h"

void CTitleKeyEvent::Init(CTitleManager *title)
{
	title = nullptr;
	push_key = false;
	select_scene = CSceneManager::Scene::NameInput;
}

void CTitleKeyEvent::ChangeSceneMenu(std::shared_ptr<CSceneManager> scene)
{
	if (!push_key) return;
	scene->ChangeScene(select_scene);
}


void CTitleKeyEvent::SelectScene(CTitleManager *title)
{
	title = nullptr;

	if (push_key) return;

	if (CharacterController::SelectSceneUpKey())
	{
		select_scene = CSceneManager::Scene::NameInput;
	}
}

void CTitleKeyEvent::PushKey()
{
	if (push_key) return;
	if (CharacterController::ChangeSceneKey() && !push_key)
	{
		push_key = true;
		CResource::GetInstance().PlaySE(CResource::SE::Decision);
	}
}

void CTitleKeyEvent::Update(CTitleManager *title)
{
	PushKey();
	SelectScene(title);
}