#include "OpeningRecovery.h"
#include "Resource.h"
#include "Resource.h"
#include "collision.h"
#include "utility.h"

const int NextSceneTime = 6;
const Float3 PlayerSize = Float3(256, 256, 0);
const Float3 PlayerPos = Float3(-200, PlayerSize.y/5, -100);

COpeningRecovery::COpeningRecovery() :
OpeningScene(CGameOpening::Scene::End),
soul_state(SoulState::Release),
soul(Transform(CGameOpening::TombstonePos, Float3(50, 50, 0.0001f), Float3(0, 0, 0))),
velocity(utility::MoveBy(CGameOpening::TombstonePos, PlayerPos,2))
{
	velocity.y = 6.0f;
}

void COpeningRecovery::SoulRelease()
{
	if (soul_state != SoulState::Release) return;

	soul.Translate(velocity);
	velocity.y -= 0.1f;

	if (collision::SphereToSphere(soul.GetPos(), PlayerPos - Float3(0,20,0), 10, 10))
	{
		soul_state = SoulState::Stop;
	}
}

void COpeningRecovery::Update()
{
	NextScene(NextSceneTime);

	SoulRelease();
}

void COpeningRecovery::Draw()
{
	if (soul_state == SoulState::Release)
	{
		auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::ParticleGauss));
		Billboard(soul.GetScale(), soul.GetPos()).draw(texture,Palette::Lightgoldenrodyellow, *CResource::GetInstance().GetAlphaRenderer());
	}
	else
	{
		auto texture = TextureAsset(CResource::GetInstance().GetPlayer(0));
		Billboard(Float3(256, 256, 1), soul.GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
	}
}