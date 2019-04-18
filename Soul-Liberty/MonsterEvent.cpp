#include "MonsterEvent.h"
#include "Resource.h"
#include "GameApplication.h"
#include "Utility.h"
#include "PlayerEvent.h"

const Point CMonsterEvent::UI_Space = Point(100.0f, 0.0f);
const Point CMonsterEvent::UI_Pos = Point(CGameApplication::ScreenWidth / 2 + UI_Space.x * 2, 50);

CMonsterEvent::CMonsterEvent(std::shared_ptr<CPlayerEvent> player,Float3 pos,
	MonsterUI ui, Texture texture, Texture back_texture , ColorF color) :
player(player),
destination(pos),
alpha(255),
transform(pos + Float3(400,0,0), Float3(126, 126, 1), Float3(0, 0, 0)),
texture(texture),
back_texture(back_texture),
color(color),
call(std::make_unique<CMonsterCall>(UI_Pos + ui.pos, ui.pos_adjustment, ui.type)),
state(State::Appearance),
speed(0)
{
	velocity = utility::MoveBy(transform.GetPos(), destination, 20);
}

//	ìoèÍèàóù
void CMonsterEvent::Appearance()
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
void CMonsterEvent::TransformSoul()
{
	if (state != State::Soul) return;
	alpha -= 3;
	transform.Scaling(Float3(-1, -1, 0));

	if (alpha <= 20)
	{
		state = State::Move;
	}
}

//	ãzé˚Ç≥ÇÍÇÈèàóù
void CMonsterEvent::AbsorptionMove()
{
	if (state != State::Move) return;

	velocity = utility::MoveBy(transform.GetPos(), player->GetPos(), speed);
	transform.Translate(velocity);
	speed += 0.03f;
	
	if (utility::IsInclude<float>(transform.GetPos().x, player->GetPos().x, 20))
	{
		state = State::Absorption;
	}
}

void CMonsterEvent::Update()
{
	Appearance();
	TransformSoul();
	AbsorptionMove();
}

void CMonsterEvent::Draw()
{
	UIDraw();
	CharaterDraw();
	SoulDraw();
}

void CMonsterEvent::CharaterDraw()
{
	if (state != State::Appearance && state != State::Soul) return;

	Billboard(transform.GetScale()*1.2f, transform.GetPos()).draw(back_texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, Alpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}

void CMonsterEvent::SoulDraw()
{
	if (state != State::Move) return;

	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Soul));
	Billboard(Float3(100,100,1), transform.GetPos()).draw(texture, color.setAlpha(250), *CResource::GetInstance().GetAlphaRenderer());
}

void CMonsterEvent::UIDraw()
{
	if (state != State::Absorption) return;
	TextureAsset(CResource::GetInstance().GetMonsterUI(call->GetId())).resize(call->GetSize()).drawAt(call->GetPos());
}

