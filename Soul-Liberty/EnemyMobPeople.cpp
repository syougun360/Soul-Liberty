#include "EnemyMobPeople.h"
#include "EnemyMob.h"
#include "GameApplication.h"

const std::string MobName = "mob";

CEnemyMobPeople::CEnemyMobPeople() :
task(std::make_shared<CTask>())
{
	const Float2 MobPos = Float2(100, CGameApplication::ScreenHeight / 2 + 100);
	const float MobSpace = 200;

	auto mob = std::make_shared<CActor>();

	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 0, MobPos.y, 0), CResource::SlimeType::Black));
	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 1, MobPos.y, 0), CResource::SlimeType::Blue));
	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 2, MobPos.y, 0), CResource::SlimeType::Red));
	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 3, MobPos.y, 0), CResource::SlimeType::Blue));
	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 4, MobPos.y, 0), CResource::SlimeType::Red));
	mob->Append(std::make_shared<CEnemyMob>(Float3(MobPos.x + MobSpace * 5, MobPos.y, 0), CResource::SlimeType::Blue));

	task->Append(MobName, mob);
}

void CEnemyMobPeople::MobUpdate()
{
	task->Update();
}

void CEnemyMobPeople::Update()
{
	MobUpdate();
}

void CEnemyMobPeople::Draw()
{
	auto graph = TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::EnemyMobPeople));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

	task->Draw();

}