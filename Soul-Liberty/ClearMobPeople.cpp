#include "ClearMobPeople.h"
#include "Mob.h"
#include "Task.h"
#include "GameApplication.h"
#include "Resource.h"
#include "EnemyMob.h"
#include "ClearSoul.h"

const int NextSceneTime = 8;
const std::string EnemyMob = "enemy_mob";
const std::string Mob = "mob";
const std::string Soul = "soul";
const int MobNum = 6;

CClearMobPeople::CClearMobPeople():
ClearScene(CClearManager::Scene::End),
task(std::make_unique<CTask>()),
change_count(0)
{
	const Float2 MobPos = Float2(100, CGameApplication::ScreenHeight / 2 + 100);
	const float MobSpace = 200;

	auto mob = std::make_shared<CActor>();
	auto enemy_mob = std::make_shared<CActor>();
	auto soul = std::make_shared<CActor>();

	for (int i = 0; i < MobNum; i++)
	{
		mob->Append(std::make_shared<CMob>(Float3(MobPos.x + MobSpace * i, MobPos.y, 0), i, CMob::State::None));
		soul->Append(std::make_shared<CClearSoul>(Float3(MobPos.x + MobSpace * i, MobPos.y, 0)));
	}

	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 0, MobPos.y, 0), CResource::SlimeType::Black,CEnemyMob::State::Live));
	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 1, MobPos.y, 0), CResource::SlimeType::Blue, CEnemyMob::State::Live));
	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 2, MobPos.y, 0), CResource::SlimeType::Red, CEnemyMob::State::Live));
	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 3, MobPos.y, 0), CResource::SlimeType::Blue, CEnemyMob::State::Live));
	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 4, MobPos.y, 0), CResource::SlimeType::Red, CEnemyMob::State::Live));
	enemy_mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 5, MobPos.y, 0), CResource::SlimeType::Blue, CEnemyMob::State::Live));

	task->Append(Soul, soul);
	task->Append(Mob, mob);
	task->Append(EnemyMob, enemy_mob);
}

void CClearMobPeople::MobAction()
{
	
	auto mob = task->GetActor(Mob);
	auto enemy_mob = task->GetActor(EnemyMob);
	change_count++;
	if (change_count >= 180)
	{
		for (int i = 0; i < MobNum; i++)
		{
			std::dynamic_pointer_cast<CMob>(mob[i])->ChangeLive();
			std::dynamic_pointer_cast<CEnemyMob>(enemy_mob[i])->ChangeNone();
		}
		change_count = 0;
		state = State::Update;
	}

	for (int i = 0; i < MobNum; i++)
	{
		std::dynamic_pointer_cast<CEnemyMob>(enemy_mob[i])->Flashing();
	}
}

void CClearMobPeople::ChangeMob()
{
	if (state != State::Start) return;

	auto soul = task->GetActor(Soul);

	for (int i = 0; i < MobNum; i++)
	{
		if (std::dynamic_pointer_cast<CClearSoul>(soul[i])->IsHit())
		{
			state = State::Update;
		}
	}

}

void CClearMobPeople::Update()
{
	task->Update();
	ChangeMob();

	if (state != State::Update) return;
	MobAction();

	NextScene(NextSceneTime);
}

void CClearMobPeople::Draw()
{

	auto graph = TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::MobPeople));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

	task->Draw();
}