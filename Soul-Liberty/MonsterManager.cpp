#include "MonsterManager.h"
#include "MonsterActor.h"
#include "FireKnight.h"
#include "Soul.h"
#include "task.h"
#include "MonsterCall.h"
#include "CharacterController.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "WaterShark.h"
#include "Golem.h"
#include "Spirit.h"
#include "Vampire.h"
#include "GameApplication.h"

const double MaxSoul = 0.0;
std::array<double, 5> CMonsterManager::soul_point = { MaxSoul, MaxSoul, MaxSoul, MaxSoul, MaxSoul };

const Point CMonsterManager::UI_Space = Point(100.0f, 0.0f);
const Point CMonsterManager::UI_Pos = Point(CGameApplication::ScreenWidth / 2 + UI_Space.x*1.5f, 70);
const Point CMonsterManager::UI_Size = Point(560, 130);

CMonsterManager::CMonsterManager(std::shared_ptr<CTask> task) :
CActor(task),
monster(std::make_shared<CTask>()),
ui(UIBackGround(UI_Pos - Point(UI_Space.x - 20, UI_Size.y / 2), UI_Size)),
count(0)
{
	actor.push_back(std::make_unique<CFireKnight>(task));
	actor.push_back(std::make_unique<CWaterShark>(task));
	actor.push_back(std::make_unique<CGolem>(task));
	actor.push_back(std::make_unique<CSpirit>(task));
	actor.push_back(std::make_unique<CVampire>(task));
	
}

void CMonsterManager::Start()
{
	player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);
	for (auto& it : actor)
	{
		it->Start(player);
	}
	for (unsigned int i = 0; i < soul_point.size(); i++)
	{
		auto it = actor[i];
		it->ContinuationSoul(soul_point[i]);
	}

}

//	召喚(呼べる)可能の処理
void CMonsterManager::EnableToCall()
{
	for (auto& it : actor)
	{
		it->EnableToCall();
	}
}

std::vector<std::shared_ptr<CMonsterActor>> CMonsterManager::GetMonsterActor()const
{
	return actor;
}

//	呼ぶ処理
void CMonsterManager::Call()
{
	if (state != State::Live) return;

	for (auto& it : actor)
	{
		if (!it->IsCall()) continue;
		player->MonsterCall();
		it->Init();
		it->OnAnimationSummons();
		monster->Append(it->GetName(), it);
		state = State::Call;
	}

}

//	呼べる限界カウント処理
void CMonsterManager::CallLimitCount()
{
	if (state != State::Call) return;

	for (auto& it : actor)
	{
		if (it->GetState() != State::Appearance) continue;
		it->SummonsEffectAnimation();
	}

	count++;
	if (count >= 30)
	{
		count = 0;
		state = State::Live;
		player->SetStandingAnimation();
	}
}

//	放出する魂を生成
void CMonsterManager::CreateSoulRelease(CResource::MonsterUIType type, Float3 create_pos,const int point)
{
	const int id = static_cast<int>(type);

	actor[id]->CreateRelease(create_pos, actor[id]->GetCallUIPos(), point);
}

void CMonsterManager::Update()
{
	Call();
	CallLimitCount();
	monster->Update();

}

//	自動的に魂を吸収(溜まる)
void CMonsterManager::AutoSoulAbsorption()
{
	for (auto& it : actor)
	{
		it->AutoSoulAbsorption();
	}
}

void CMonsterManager::Draw()
{
	const Float3 UIWorldPos = Float3(player->GetCameraPos().x + CGameApplication::ScreenWidth / 3 - 30, UI_Pos.y+20, 0);
	auto texture = TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Monster));
	texture.resize(ui.size).draw(ui.pos);

	monster->Draw();

	for (auto& it : actor)
	{
		it->UIDraw();
	}

}


void CMonsterManager::Finish()
{
	for (unsigned int i = 0; i < soul_point.size(); i++)
	{
		auto it = actor[i];
		it->OnInitSoul();
	}
}

void CMonsterManager::SoulClear()
{
	for (auto& point : soul_point)
	{
		point = 0;
	}
}