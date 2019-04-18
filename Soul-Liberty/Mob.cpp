#include "Mob.h"
#include "Resource.h"
#include "GameApplication.h"

const float JumpPower = -10.0f;
const Float3 GraphicSize = Float3(256, 256, 0.001f);

CMob::CMob(Float3 pos, int id, State state) :
CActor(nullptr, Transform(pos + Float3(0, GraphicSize.y/2,0), GraphicSize, Float3(0, 0, 0)),
state, L"engine/data/database/mob.ini"),
id(id),
max_force(JumpPower + Random(-5.0f,0.0f)),
force(JumpPower)
{
}

void CMob::Update()
{
	if (state != State::Live) return;
	transform.Translate(Float3(0, force, 0));
	force += 0.8f;
	if (transform.GetPos().y > CGameApplication::ScreenHeight - transform.GetScale().y / 2)
	{
		force = max_force;
	}
}

void CMob::ChangeLive()
{
	state = State::Live;
}


void CMob::Draw()
{
	if (state != State::Live) return;

	auto graph = TextureAsset(CResource::GetInstance().GetMob(id));
	graph.resize(Float2(transform.GetScale().x, transform.GetScale().y)).drawAt(Float2(transform.GetPos().x, transform.GetPos().y));
}