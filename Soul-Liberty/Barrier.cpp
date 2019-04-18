#include "Barrier.h"
#include "Resource.h"
#include "Devil.h"

CBarrier::CBarrier() :
CActor(nullptr,Transform(Float3(0,0,0),Float3(0, 0, 0),Float3(0,0,0)),State::None,L""),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 10.0f, CParticleScale(10.0f, 30.0f),
CParticleVelocity(Float3(-15, 1, -10), Float3(15, 10, 10)), CParticleDuration(30, 60), 100))
{
}

//	エフェクト含みでバリア生成
void CBarrier::Create(Float3 pos,CDevil *devil)
{
	if (state != State::None) return;

	transform.TransformPoint(pos + Float3(0,-150,0));
	state = State::Live;

	particles->TransformPoint(transform.GetPos());
	particles->CreateChildren();

	devil->PlayerDamageLargeAction();

}

//	アップデート
void CBarrier::Update(CDevil *devil)
{
	if (state != State::Live) return;

	particles->ChildrenUpdate();
	particles->Remove();

	if (particles->IsEmpty())
	{
		state = State::None;
		devil->ReturnAttackPreparation();
	}
}

//	描画
void CBarrier::Draw()
{
	if (state != State::Live) return;

	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));

	particles->Draw(texture, ColorF(0.2, 0.2, 0.2));

}