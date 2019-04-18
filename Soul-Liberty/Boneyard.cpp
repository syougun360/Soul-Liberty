#include "Boneyard.h"
#include "BackGround.h"
#include "PlayerEvent.h"
#include "Floor.h"
#include "MapRead.h"
#include "DescriptionBoard.h"

const Float3 TombstonePos = Float3(300, -150, 50);

CBoneyard::CBoneyard():
CGameStage(L"engine/data/Boneyard.txt", CResource::GraphicType::BackGroundBoneyard),
player(std::make_shared<CPlayerEvent>()),
camera(std::make_unique<CCamera>(player->GetPos() + Float3(300,80,-580),Float3(player->GetPos().x+300,0,0))),
light(std::make_unique<CLight>(0,CLight::Type::Point,Float3(0,0,-600),3000.0f,ColorF(2,2,2))),
description_board(std::make_shared<CActor>())
{
	for (int i = -3; i < 10; i++)
	{
		floors.push_back(std::make_unique<CFloor>(
			Float3(i * CMapRead::FloorSize.x, -270.0f, 0), CGameManager::Stage::Boneyard));
	}

	monsters.clear();

	monsters.push_back(std::make_unique<CMonsterEvent>(player, Float3(400, -50, 50),
		MonsterUI(Point(0, 0), Point(0, 0), CResource::MonsterUIType::FireKnight),
		TextureAsset(CResource::GetInstance().GetFireKnight(0)), *CResource::GetInstance().GetFireKnightBackTexture(0), Palette::Red));

	monsters.push_back(std::make_unique<CMonsterEvent>(player, Float3(600, 0, 50),
		MonsterUI(Point(CMonsterEvent::UI_Space.x, 0), Point(0, 0), CResource::MonsterUIType::WaterShark),
		TextureAsset(CResource::GetInstance().GetWaterShark(0)), *CResource::GetInstance().GetWaterSharkBackTexture(0), Palette::Aqua));

	monsters.push_back(std::make_unique<CMonsterEvent>(player, Float3(550, -150, 50),
		MonsterUI(Point(CMonsterEvent::UI_Space.x*2, 0), Point(0, 0), CResource::MonsterUIType::Golem),
		TextureAsset(CResource::GetInstance().GetGolem(0)), *CResource::GetInstance().GetGolemBackTexture(0), Palette::Green));

	
	CResource::GetInstance().PlayBGM(CBGMData::BGM::Boneyard);

	DescriptionBoardPlacement();

}

void CBoneyard::DescriptionBoardPlacement()
{
	const float ZPos = 100;
	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			switch (map_read->GetElement(Point(x, y)))
			{
			case 45:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Move));
				break;
			case 46:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Jump));
				break;
			case 47:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Attack));
				break;
			case 48:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Avoid));
				break;
			case 49:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Summons));
				break;
			case 50:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Combine));
				break;
			case 51:
				description_board->Append(std::make_shared<CDescriptionBoard>(Float3(x * CMapRead::Size, map_read->TransformMapToScreenY(y), ZPos),
					CResource::DescriptionType::Jump2));
				break;
			}
		}
	}

	
}

void CBoneyard::EventUpdate()
{
	light->Update();
	camera->Update();
	player->Update();

	for (auto& monster : monsters)
	{
		monster->Update();
		if (monster->IsAbsorption())
		{
			state = State::FadeOut;
		}
	}

}

void CBoneyard::EventDraw()
{
	Draw();
	for (auto& floor : floors)
	{
		floor->Draw();
	}

	CResource::GetInstance().GetModel(CResource::ModelType::Tombstone)->Draw(
		TombstonePos, Float3(1, 1, 1), Float3(0, PiF / 180 * 180, 0), CModel::Mode::TextureNormal);

	player->Draw();
	for (auto& monster : monsters)
	{
		monster->Draw();
	}
}


void CBoneyard::Draw()
{
	background->Draw();
	description_board->Draw();
}