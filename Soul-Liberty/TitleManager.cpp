#include "TitleManager.h"
#include "TitleKeyEvent.h"
#include "TitleLogo.h"
#include "GameApplication.h"
#include "Resource.h"

CTitleManager::CTitleManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CTitleKeyEvent>())
{
	logo.insert(std::make_pair(CResource::TitleGraphicType::TitleLogo, 
		std::make_unique<CTitleLogo>(Float2(CGameApplication::ScreenWidth / 2, 200), Float2(1200, 450))));

	logo.insert(std::make_pair(CResource::TitleGraphicType::StartLogo,
		std::make_unique<CTitleLogo>(Float2(CGameApplication::ScreenWidth / 2, 550), Float2(600, 200),true)));

}

void CTitleManager::Init()
{
	CResource::GetInstance().PlayBGM(CBGMData::BGM::Title);
	key->Init(this);
}

void CTitleManager::Update()
{
	for (auto& it : logo)
	{
		it.second->Update();
	}
	key->Update(this);
	key->ChangeSceneMenu(app_scene);
	Draw();
}

void CTitleManager::Draw()
{
	TextureAsset(CResource::GetInstance().GetTitleGraphic(CResource::TitleGraphicType::BackGround)).resize(
		CGameApplication::ScreenWidth,CGameApplication::ScreenHeight).draw(0,0);

	for (auto& it : logo)
	{
		it.second->Draw(it.first);
	}
}
