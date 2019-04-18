#include "InputNameEvent.h"
#include "GameApplication.h"
#include "Resource.h"
#include "PlayerStartEvent.h"
#include "Utility.h"
#include "InputName.h"

CInputNameEvent::CInputNameEvent(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
player(std::make_unique<CPlayerStartEvent>()),
input_name(std::make_unique<CInputName>())
{

}

String CInputNameEvent::GetName()const
{
	return input_name->GetName();
}

void CInputNameEvent::Init()
{
	player->Init();
	input_name->Init();
}

void CInputNameEvent::Update()
{
	input_name->Update();
	player->Update();
	if (input_name->IsDecision())
	{
		player->ChangeMontion();
	}

	if (player->IsFinish())
	{
		app_scene->ChangeScene(CSceneManager::Scene::Prologue);
		CResource::GetInstance().FadeStartBGM();
	}

	Draw();
}

void CInputNameEvent::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::BackGroundBoneyard));
	texture.resize(CGameApplication::ScreenWidth,CGameApplication::ScreenHeight).draw(0, 0);
	input_name->Draw();
	player->Draw();

}