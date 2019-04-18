#include "HelpKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"

CHelpKeyEvent::CHelpKeyEvent()
{
}

void CHelpKeyEvent::ChangeSceneGame(std::shared_ptr<CSceneManager> scene)
{
	if (CharacterController::ChangeSceneKey())
	{
		scene->ChangeScene(CSceneManager::Scene::Title);
	}
}

