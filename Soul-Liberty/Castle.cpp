#include "Castle.h"
#include "BackGround.h"
#include "GameApplication.h"
#include "Utility.h"

const Float3 Destination = Float3(0, -230, -30);
CCastle::CCastle():
CGameStage(L"engine/data/Castle.txt",CResource::GraphicType::BackGroundCastle),
camera(std::make_unique<CCamera>(Float3(0, 0, -800), Float3(0, 0, 0))),
count(0)
{
	monsters.push_back(std::make_unique<CMonsterCastle>(Float3(600, 0, -50), Float3(300, 0, 0), Destination,
		TextureAsset(CResource::GetInstance().GetSpirit(0)), *CResource::GetInstance().GetSpiritBackTexture(0), Palette::Yellow));

	monsters.push_back(std::make_unique<CMonsterCastle>(Float3(-600, 0, -50), Float3(-300, 0, 0), Destination,
		TextureAsset(CResource::GetInstance().GetVampire(0)), *CResource::GetInstance().GetVampireBackTexture(0), Palette::Purple));
	
	CResource::GetInstance().PlayBGM(CBGMData::BGM::Castle);
}

const Float3 BackGroundPos = Float3(0, 0, 0);
void CCastle::EventUpdate()
{
	CameraFixed();
	CameraZoom();
	camera->Update();

	for (auto& monster : monsters)
	{
		monster->Update();
	}
}

void CCastle::CameraFixed()
{
	if (state != State::Start) return;

	count++;
	if (count >= 100)
	{
		count = 0;
		state = State::Move;
	}
}

void CCastle::CameraZoom()
{
	if (state != State::Move) return;

	auto velocity = utility::MoveBy(camera->GetPos(), Destination, 3);
	camera->Translate(velocity);
	camera->Rotation(velocity);
	if (utility::IsInclude<float>(camera->GetPos().z, -100, 10))
	{
		state = State::FadeOut;
	}
}

void CCastle::EventDraw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Castle));
	Billboard(Float3(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight, 1),
		BackGroundPos).draw(texture, *CResource::GetInstance().GetAlphaRenderer());

	for (auto& monster : monsters)
	{
		monster->Draw();
	}
}
void CCastle::Draw()
{
	background->Draw();
}