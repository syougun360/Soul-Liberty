#include "PrologueDevilMagic.h"
#include "Resource.h"
#include "GameApplication.h"

const int NextSceneTime = 5;

CPrologueDevilMagic::CPrologueDevilMagic():
PrologueScene(CPrologueManager::Scene::EnemyPeople),
particle(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual,
Float3(CGameApplication::ScreenWidth / 2 - 400, CGameApplication::ScreenHeight / 2 + 50, 0), 50.0f, CParticleScale(100.0f, 180.0f),
CParticleVelocity(Float3(-20,-20,0),Float3(-5,20,0)),CParticleDuration(60,120),2))
{
}


void CPrologueDevilMagic::Update()
{
	NextScene(NextSceneTime);
	particle->Update();
}

void CPrologueDevilMagic::Draw()
{
	auto graph = TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::Devil_Magic));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

	auto particle_graph = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Smoke));
	particle->Draw2D(particle_graph);

}