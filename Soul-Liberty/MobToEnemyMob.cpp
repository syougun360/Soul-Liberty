#include "MobToEnemyMob.h"
#include "Resource.h"
#include "FPS.h"
#include "GameApplication.h"
#include "MobPeople.h"
#include "EnemyMobPeople.h"

const int NextSceneTime = 8;
CMobToEnemyMob::CMobToEnemyMob() :
CSubScene(CPrologueManager::Scene::End), 
mob(std::make_unique<CMobPeople>()),
enemy(std::make_unique<CEnemyMobPeople>()),
particle(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual,
Float3(CGameApplication::ScreenWidth + 300, CGameApplication::ScreenHeight / 2, 0), 200.0f, CParticleScale(128.0f, 256.0f),
CParticleVelocity(Float3(-25, -25, 0), Float3(25, 25, 0)), CParticleDuration(180, 320), 4))
{
}

void CMobToEnemyMob::MobUpdate()
{
	if (state != State::Start) return;

	mob->MobUpdate();
	particle->Transformlate(Float3(-5, 0, 0));
	particle->CreateChildren();
	ChangeEnemy();
}

void CMobToEnemyMob::ChangeEnemy()
{
	count++;
	if (count >= CFPS::FPS * 5)
	{
		count = 0;
		state = State::Update;
		CResource::GetInstance().PlaySE(CResource::SE::DarkMagic);
	}
}
void CMobToEnemyMob::Smoke()
{
	if (state != State::Update) return;

	NextScene(NextSceneTime);
	enemy->Update();
}

void CMobToEnemyMob::Update()
{
	MobUpdate();
	Smoke();
	particle->ChildrenUpdate();
	particle->Remove();
}

void CMobToEnemyMob::Draw()
{
	if (state == State::Start)
	{
		mob->Draw();
	}
	else if (state == State::Update)
	{
		enemy->Draw();
	}
	auto particle_graph = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Smoke));
	particle->Draw2D(particle_graph);


}