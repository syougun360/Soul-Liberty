#include "WaterGun.h"
#include "Utility.h"
#include "Resource.h"

const Float3 Scale = Float3(20, 20, 20);
CWaterGun::CWaterGun(Float3 pos, Float3 target_pos) :
transform(pos - Scale / 2, Scale, Float3(0, 0, 0)),
state(State::Live),
particle(std::make_unique<CWaterParticleSystem>()),
velocity(utility::MoveBy(transform.GetPos(), target_pos, 20))
{
	velocity.y += 10.0f;
}

CWaterGun::CWaterGun(Float3 pos,int direction) :
transform(pos, Scale, Float3(0, 0, 0)),
state(State::Live),
velocity(Float3(20 * direction,10,0)),
particle(std::make_unique<CWaterParticleSystem>())
{
}

//	終了処理
void CWaterGun::Finish()
{
	if (state != State::Live) return;
	particle->Create(transform.GetPos());
	state = State::Effect;
	transform.TransformPoint(Float3(0, 0, 0));
	velocity.y -= 3.0f;
}

//	エフェクト処理
void CWaterGun::Effect()
{
	if (state != State::Effect) return;

	particle->Update();

	if (!particle->IsEmpty()) return;
	state = State::None;
}

//	移動処理
void CWaterGun::Move()
{
	if (state != State::Live) return;

	transform.Translate(velocity);
	velocity.y -= 1.0f;

}

void CWaterGun::Update()
{
	Move();
	Effect();
}

void CWaterGun::Draw()
{
	particle->Draw();

	if (state != State::Live) return;
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));
	Billboard(transform.GetScale().x*2 , transform.GetPos()).draw(texture,Palette::Aqua, *CResource::GetInstance().GetAlphaRenderer());

}