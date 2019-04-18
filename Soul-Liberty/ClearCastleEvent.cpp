#include "ClearCastleEvent.h"
#include "Resource.h"
#include "GameApplication.h"

const int NextSceneTime = 3;

CClearCastleEvent::CClearCastleEvent() :
ClearScene(CClearManager::Scene::Mob)
{
}


void CClearCastleEvent::Update()
{
	NextScene(NextSceneTime);
}

void CClearCastleEvent::Draw()
{
	auto graph = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Castle2));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

}