#include "EnemyManager.h"
#include "SlimeRed.h"
#include "SlimeBlue.h"
#include "SlimeBlack.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "MapRead.h"
#include "WeaponSoldier.h"
#include "MagicSoldier.h"
#include "ObjectDelete.h"

const std::string CEnemyManager::SlimeName = "slime";
const std::string CEnemyManager::MagicName = "magic";
const std::string CEnemyManager::WeaponName = "weapon";

CEnemyManager::CEnemyManager(std::shared_ptr<CTask> task, std::shared_ptr<CMapRead> map) :
CActor(task),
map(map),
enemy_task(std::make_shared<CTask>()), 
enemy(std::make_shared<CActor>()),
weapon_enemy(std::make_shared<CActor>()),
magic_enemy(std::make_shared<CActor>())
{
}

void CEnemyManager::Start()
{

}

int CEnemyManager::SlimeGetSize()const
{
	return enemy_task->GetActor(SlimeName).size();
}
int CEnemyManager::WeaponGetSize()const
{
	return enemy_task->GetActor(WeaponName).size();
}
int CEnemyManager::MagicGetSize()const
{
	return enemy_task->GetActor(MagicName).size();
}

std::shared_ptr<CSlimeActor> CEnemyManager::SlimeGetInstance(const int id)const
{
	return enemy_task->GetComponent<CSlimeActor>(SlimeName, id);
}
std::shared_ptr<CWeaponSoldier> CEnemyManager::WeaponGetInstance(const int id)const
{
	return enemy_task->GetComponent<CWeaponSoldier>(WeaponName, id);
}
std::shared_ptr<CMagicSoldier> CEnemyManager::MagicGetInstance(const int id)const
{
	return enemy_task->GetComponent<CMagicSoldier>(MagicName, id);
}


struct AppendElement
{
	int id;
	CSlimeActor::ScaleType scale;
	CResource::MonsterUIType ui;
};

struct AppendElement2
{
	int id;
	CResource::MonsterUIType ui;
};


void CEnemyManager::Create()
{
	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			SlimeBlackAppandElement(x, y);
			SlimeRedAppandElement(x, y);
			SlimeBlueAppandElement(x, y);
			MagicAppandElement(x,y);
			WeaponAppandElement(x, y);
		}
	}

	enemy_task->Append(SlimeName, enemy);
	enemy_task->Append(WeaponName, weapon_enemy);
	enemy_task->Append(MagicName, magic_enemy);
	
	enemy_task->Start();

	AppendDeleteName();
	object_delete = std::make_unique<CObjectDelete>(enemy_task,
		task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0), delete_table);
}

template<class T, class FLOAT3>
void CEnemyManager::SlimeCreate(FLOAT3 pos)
{
	AppendElement2 elements[] =
	{
		{ 0, CResource::MonsterUIType::FireKnight },
		{ 1, CResource::MonsterUIType::WaterShark },
		{ 2, CResource::MonsterUIType::Golem },
		{ 3, CResource::MonsterUIType::Spirit },
		{ 4, CResource::MonsterUIType::Vampire },
	};
	const int MaxRandom = 4;
	auto create_id = Random(0, MaxRandom);
	for (auto & element : elements)
	{
		if (element.id != create_id) continue;
		enemy->Append(std::make_shared<T>(task,
			pos, CSlimeActor::ScaleType::Small, element.ui));
	}
}

void CEnemyManager::CreateSlimeToBoss(Float3 pos)
{
	//SlimeCreate<CSlimeBlack,Float3>(pos);
	SlimeCreate<CSlimeBlue, Float3>(pos);
	SlimeCreate<CSlimeRed, Float3>(pos);
	
	enemy_task->Append(SlimeName, enemy);
	enemy_task->Start();
}

void CEnemyManager::AppendDeleteName()
{
	delete_table.push_back(SlimeName);
	delete_table.push_back(WeaponName);
	delete_table.push_back(MagicName);
}

void CEnemyManager::MagicAppandElement(const int x, const int y)
{

	AppendElement2 element[] =
	{
		{ 26, CResource::MonsterUIType::FireKnight },
		{ 27, CResource::MonsterUIType::WaterShark },
		{ 28, CResource::MonsterUIType::Golem },
		{ 33, CResource::MonsterUIType::Spirit },
		{ 34, CResource::MonsterUIType::Vampire },
	};

	for (auto& it : element)
	{
		if (it.id != map->GetElement(Point(x, y))) continue;
		magic_enemy->Append(std::make_shared<CMagicSoldier>(task,
			Float3(x * CMapRead::Size, map->TransformMapToScreenY(y), 0),it.ui));
	}
}

void CEnemyManager::WeaponAppandElement(const int x, const int y)
{

	AppendElement2 element[] =
	{
		{ 29, CResource::MonsterUIType::FireKnight },
		{ 30, CResource::MonsterUIType::WaterShark },
		{ 31, CResource::MonsterUIType::Golem },
		{ 35, CResource::MonsterUIType::Spirit },
		{ 36, CResource::MonsterUIType::Vampire },
	};

	for (auto& it : element)
	{
		if (it.id != map->GetElement(Point(x, y))) continue;
		weapon_enemy->Append(std::make_shared<CWeaponSoldier>(task,
			Float3(x * CMapRead::Size, map->TransformMapToScreenY(y), 0), it.ui));
	}
}

void CEnemyManager::SlimeBlackAppandElement(const int x, const int y)
{

	AppendElement black_element[] =
	{
		{ 10, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::FireKnight },
		{ 11, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::WaterShark },
		{ 12, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Golem },

		{ 19, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::FireKnight },
		{ 20, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::WaterShark },
		{ 21, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Golem },
	};

	for (auto& it : black_element)
	{
		if (it.id != map->GetElement(Point(x, y))) continue;
		enemy->Append(std::make_shared<CSlimeBlack>(task,
			Float3(x * CMapRead::Size, map->TransformMapToScreenY(y), 0),
			it.scale, it.ui));
	}
}

void CEnemyManager::SlimeBlueAppandElement(const int x, const int y)
{
	AppendElement blue_element[] =
	{
		{ 7, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::FireKnight },
		{ 8, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::WaterShark },
		{ 9, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Golem },
		{ 37, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Spirit },
		{ 38, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Vampire },

		{ 16, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::FireKnight },
		{ 17, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::WaterShark },
		{ 18, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Golem },
		{ 41, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Spirit },
		{ 42, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Vampire },
	};

	for (auto& it : blue_element)
	{
		if (it.id != map->GetElement(Point(x, y))) continue;
		enemy->Append(std::make_shared<CSlimeBlue>(task,
			Float3(x * CMapRead::Size, map->TransformMapToScreenY(y), 0),
			it.scale,it.ui));
	}
}
void CEnemyManager::SlimeRedAppandElement(const int x, const int y)
{
	AppendElement red_element[] =
	{
		{ 4, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::FireKnight },
		{ 5, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::WaterShark },
		{ 6, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Golem },
		{ 39, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Spirit },
		{ 40, CSlimeActor::ScaleType::Small, CResource::MonsterUIType::Vampire },

		{ 13, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::FireKnight },
		{ 14, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::WaterShark },
		{ 15, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Golem },
		{ 43, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Spirit },
		{ 44, CSlimeActor::ScaleType::Big, CResource::MonsterUIType::Vampire },
	};

	for (auto& it : red_element)
	{
		if (it.id != map->GetElement(Point(x, y))) continue;
		enemy->Append(std::make_shared<CSlimeRed>(task,
			Float3(x * CMapRead::Size, map->TransformMapToScreenY(y), 0),
			it.scale, it.ui));
	}
}

void CEnemyManager::Update()
{
	enemy_task->IniDataUpdate();
	enemy_task->Update();
	object_delete->Update();
}

void CEnemyManager::Draw()
{
	enemy_task->Draw();
	enemy_task->Remove();
}