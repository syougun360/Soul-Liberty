#include "FireEffect.h"
#include "Resource.h"

const Float3 Size = Float3(256, 256, 0.0001f);
CFireEffect::CFireEffect(Float3 pos, int direction) :
transform(pos, Size, Float3(0, 0, 0)),
velocity(Float3(direction * 15, -10, 0)), 
state(State::Live),
speed(0.9f)
{
}

CFireEffect::CFireEffect(Float3 pos, int direction,float speed) :
transform(pos + Float3(Size.x / 3 * direction, Size.y/6, 0), Size / 2, Float3(0, 0, 0)),
velocity(Float3(direction * 15, 0, 0)),
state(State::Live),
speed(speed)
{
}

void CFireEffect::Finish()
{
	state = State::None;
}

void CFireEffect::Update()
{
	if (state != State::Live) return;
	
	transform.Scaling(Float3(-5, -5, 0));
	transform.Translate(velocity);
	velocity *= speed;

	if (transform.GetScale().x <= 1)
	{
		state = State::None;
	}
}

void CFireEffect::Draw()
{
	if (state != State::Live) return;

	auto texture = TextureAsset(CResource::GetInstance().GetEffect(CResource::EffectType::Fire));
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
}
