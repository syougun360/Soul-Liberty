#include "HelpManager.h"
#include "GameApplication.h"
#include "HelpKeyEvent.h"

CHelpManager::CHelpManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CHelpKeyEvent>())
{

}
void CHelpManager::Init()
{
	Logo = new Font(50, Typeface::Black);
}

void CHelpManager::Update()
{
	key->ChangeSceneGame(app_scene);
	Draw();
}

void CHelpManager::Draw()
{
	Logo->drawCenter(L"Help", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}