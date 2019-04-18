#include "EnemyMob.h"
#include "GameApplication.h"

const float JumpPower = -10.0f;
const Float3 GraphicSize = Float3(256, 256, 0.001f);
CEnemyMob::CEnemyMob(Float3 pos, CResource::SlimeType type, State state) :
CActor(nullptr, Transform(pos + Float3(0, GraphicSize.y/2,0), GraphicSize, Float3(0, 0, 0)),
state, L"engine/data/database/mob.ini"),
type(type),
max_force(JumpPower + Random(-5.0f,0.0f)),
force(0),
alpha(255),
count(0)
{
}

void CEnemyMob::Flashing()
{
	const int FlashTime = 10;

	count++;
	if (count == FlashTime)
	{
		alpha = 0;
	}
	else if (count >= FlashTime*2)
	{
		alpha = 255;
		count = 0;
	}
}

void CEnemyMob::ChangeNone()
{
	state = State::None;
	isDelete = true;
}

void CEnemyMob::Update()
{
	if (state != State::Move) return;
	transform.Translate(Float3(0, force, 0));
	force += 0.8f;
	if (transform.GetPos().y > CGameApplication::ScreenHeight - transform.GetScale().y / 2)
	{
		force = max_force;
	}
}

void CEnemyMob::Draw()
{
	if (state == State::None) return;
	auto graph = TextureAsset(CResource::GetInstance().GetSlime(type));
	graph.resize(Float2(transform.GetScale().x, transform.GetScale().y)).drawAt(
		Float2(transform.GetPos().x, transform.GetPos().y), Alpha(alpha));
}