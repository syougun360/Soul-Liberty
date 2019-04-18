#include "GameObjectHousing.h"
#include "Scene.h"
#include "Player.h"
#include "MonsterManager.h"
#include "Actor.h"
#include "MapRead.h"
#include "Floor.h"
#include "BackGround.h"
#include "EnemyManager.h"
#include "Tombstone.h"
#include "Fence.h"
#include "DoorManager.h"
#include "ObjectDelete.h"
#include "BossManager.h"

const std::string CGameObjectHousing::PlayerName = "player";
const std::string CGameObjectHousing::FloorName = "floor";
const std::string CGameObjectHousing::TombstoneName = "tombstone";
const std::string CGameObjectHousing::FenceName = "fence";
const std::string CGameObjectHousing::MonsterManagerName = "monster_manager";
const std::string CGameObjectHousing::EnemyManagerName = "enemy_manager";
const std::string CGameObjectHousing::DoorName = "door";
const std::string CGameObjectHousing::BossName = "boss";

std::vector<std::string> CGameObjectHousing::collision_table;
std::vector<std::string> CGameObjectHousing::collision_gravity_table;
std::vector<std::string> CGameObjectHousing::collision_side_table;
std::vector<std::string> CGameObjectHousing::collision_floor_table;

CGameObjectHousing::CGameObjectHousing()
{
}

bool CGameObjectHousing::IsStageFinish()const
{
	return (task->GetComponent<CDoorManager>(DoorName, 0)->GetState() == CDoorManager::State::None);
}

bool CGameObjectHousing::IsGameFinish()const
{
	return (task->GetComponent<CBossManager>(BossName, 0)->IsDeath());
}

bool CGameObjectHousing::IsPlayerDeath()const
{
	return (task->GetComponent<CPlayer>(PlayerName, 0)->GetState() == CPlayer::State::Death);
}


void CGameObjectHousing::Init(std::shared_ptr<CMapRead> stage, CGameManager::Stage now_stage)
{

	task = std::make_shared<CTask>();
	task->Clear();

	auto monster_manager = std::make_shared<CActor>();
	auto enemy_manager = std::make_shared<CActor>();
	auto player = std::make_shared<CActor>();
	auto floor = std::make_shared<CActor>();
	auto tombstone = std::make_shared<CActor>();
	auto fence = std::make_shared<CActor>();
	auto door = std::make_shared<CActor>();
	auto boss = std::make_shared<CActor>();

	auto map_read = stage;
	
	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			switch (map_read->GetElement(Point(x, y)))
			{
			case 1:
				player->Append(std::make_shared<CPlayer>(task, Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0)));
				break;
			case 2:
				floor->Append(std::make_shared<CFloor>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0), now_stage));
				break;

			case 22:
				tombstone->Append(std::make_shared<CTombstone>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0), CTombstone::ScaleType::Normal));
				break;

			case 23:
				tombstone->Append(std::make_shared<CTombstone>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0), CTombstone::ScaleType::Huge));
				break;

			case 24:
				fence->Append(std::make_shared<CFence>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0), now_stage));
				break;

			case 25:
				door->Append(std::make_shared<CDoorManager>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0)));
				break;

			case 32:
				boss->Append(std::make_shared<CBossManager>(task,
					Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), 0)));
				break;
			}
		}
	}

	monster_manager->Append(std::make_shared<CMonsterManager>(task));
	enemy_manager->Append(std::make_shared<CEnemyManager>(task, map_read));

	task->Append(BossName, boss);
	task->Append(MonsterManagerName, monster_manager);
	task->Append(PlayerName, player);
	task->Append(EnemyManagerName, enemy_manager);
	task->Append(FloorName, floor);
	task->Append(TombstoneName, tombstone);
	task->Append(FenceName, fence);
	task->Append(DoorName, door);
	task->GetComponent<CEnemyManager>(EnemyManagerName, 0)->Create();
	Start();
}

void CGameObjectHousing::SetCollisionTable()
{
	collision_table.push_back(FloorName);
	collision_table.push_back(TombstoneName);
	collision_table.push_back(FenceName);

	collision_gravity_table.push_back(FloorName);
	collision_gravity_table.push_back(TombstoneName);

	collision_floor_table.push_back(FloorName);
	collision_floor_table.push_back(FenceName);
	collision_floor_table.push_back(TombstoneName);

	collision_side_table.push_back(TombstoneName);
	collision_side_table.push_back(FenceName);
	collision_side_table.push_back(DoorName);

	object_delete_table.push_back(TombstoneName);
	object_delete_table.push_back(DoorName);
	object_delete_table.push_back(FenceName);
	object_delete_table.push_back(FloorName);

}

void CGameObjectHousing::Start()
{
	SetCollisionTable();
	object_delete = std::make_unique<CObjectDelete>(task,
		task->GetComponent<CPlayer>(PlayerName, 0), object_delete_table);
	task->IniDataList();
	task->Start();
}

void CGameObjectHousing::EventUpdate()
{
	task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0)->NextStageEventUpdate();
}

void CGameObjectHousing::Update()
{
	task->IniDataUpdate();
	task->Update();
}

void CGameObjectHousing::Draw()
{
	task->Draw();
}

void CGameObjectHousing::Remove()
{
	object_delete->Update();
	task->Remove();
}

void CGameObjectHousing::StageFinish()
{
	task->Finish();
}
void CGameObjectHousing::GameFinish()
{
	auto monster = task->GetComponent<CMonsterManager>(MonsterManagerName, 0);
	monster->SoulClear();
	StageFinish();
}