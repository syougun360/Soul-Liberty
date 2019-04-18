#include "PrologueDevil.h"
#include "Resource.h"
#include "FPS.h"
#include "GameApplication.h"

const int NextSceneTime = 2;
CPrologueDevil::CPrologueDevil() :
PrologueScene(CPrologueManager::Scene::DevilMagic)
{

}

void CPrologueDevil::Update()
{
	NextScene(NextSceneTime);

}

void CPrologueDevil::Draw()
{
	auto graph = TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::Devil));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

}