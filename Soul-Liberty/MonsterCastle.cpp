#include "MonsterCastle.h"
#include "Utility.h"
#include "Resource.h"

CMonsterCastle::CMonsterCastle(Float3 pos, Float3 destination, Float3 absorption_pos, Texture texture, Texture back_texture, ColorF color) :
destination(destination),
absorption_pos(absorption_pos + Float3(0,30,0)),
alpha(255),
transform(pos, Float3(256, 256, 0.001f), Float3(0, 0, 0)),
texture(texture),
back_texture(back_texture),
color(color),
state(State::Appearance),
speed(0)
{
	velocity = utility::MoveBy(transform.GetPos(), destination, 20);
}

//	ìoèÍèàóù
void CMonsterCastle::Appearance()
{
	if (state != State::Appearance) return;

	transform.Translate(velocity);
	velocity *= 0.95f;

	if (utility::IsInclude<float>(transform.GetPos().x, destination.x, 10))
	{
		state = State::Soul;
	}
}


//	ç∞Ç…ïœêgÇ∑ÇÈ
void CMonsterCastle::TransformSoul()
{
	if (state != State::Soul) return;
	alpha -= 3;
	transform.Scaling(Float3(-2, -2, 0));

	if (alpha <= 20)
	{
		transform.TransformScale(Float3(126,126,0.001f));
		state = State::Move;
		alpha = 255;
	}
}

//	ãzé˚Ç≥ÇÍÇÈèàóù
void CMonsterCastle::AbsorptionMove()
{
	if (state != State::Move) return;

	transform.Scaling(Float3(-0.5f, -0.5f, 0));
	velocity = utility::MoveBy(transform.GetPos(), absorption_pos, speed);
	transform.Translate(velocity);
	speed += 0.016f;
	alpha -= 1;

	if (utility::IsInclude<float>(transform.GetPos().x, absorption_pos.x, 10))
	{
		state = State::Absorption;
	}
}

void CMonsterCastle::Update()
{
	Appearance();
	TransformSoul();
	AbsorptionMove();
}

void CMonsterCastle::Draw()
{
	CharaterDraw();
	SoulDraw();
}

void CMonsterCastle::CharaterDraw()
{
	if (state != State::Appearance && state != State::Soul) return;

	Billboard(transform.GetScale()*1.2f, transform.GetPos()).draw(back_texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, Alpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}

void CMonsterCastle::SoulDraw()
{
	if (state != State::Move) return;

	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Soul));
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}
