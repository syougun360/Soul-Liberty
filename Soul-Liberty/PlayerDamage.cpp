#include "PlayerDamage.h"
#include "GameManager.h"
#include "Resource.h"

Float3 CPlayerDamage::action_speed;

CPlayerDamage::CPlayerDamage():
CPlayerState(),
count(0),
isLargeAction(false)
{
}

void CPlayerDamage::IniData(INIReader ini)
{
	action_speed = ini.get<Float3>(L"Damage.action_speed");
}

void CPlayerDamage::Update()
{
	if (state != State::Live) return;

	LargeUpdate();
	NormalUpdate();
	player->transform.Translate(velocity);
	CollisionUpdate();
}

void CPlayerDamage::LargeUpdate()
{
	if (!isLargeAction) return;

	if (player->IsJumpCollision() && velocity.y <= 0)
	{
		Finish();
	}

	velocity.y -= CPlayer::Mass;
}

void CPlayerDamage::NormalUpdate()
{
	if (isLargeAction) return;

	count++;
	if (count >= finish_count)
	{
		Finish();
	}
}
void CPlayerDamage::CollisionUpdate()
{
	if (player->IsBackCollision())
	{
		player->transform.Translate(Float3(-velocity.x*1.3f,0,0));
		Finish();
		return;
	}
}

void CPlayerDamage::Finish()
{
	count = 0;
	player->OnAnimation(CPlayer::AnimationType::Move);
	state = State::None;
	isLargeAction = false;
	velocity = Float3(0, 0, 0);

}

void CPlayerDamage::LargeAction()
{
	isLargeAction = true;
	velocity = Float3(-player->GetDirection() * ActionSpeed().x, ActionSpeed().y, 0);
}

void CPlayerDamage::StartAction()
{
	if (state != State::None) return;
	isLargeAction = false;
	finish_count = 10;
	state = State::Live;
	velocity = Float3(-player->GetDirection() * 3, 5, 0);
	CResource::GetInstance().PlaySE(CResource::SE::PlayerDamage);
}

void CPlayerDamage::Draw(const Mesh& mesh,const Float3& graphic_pos,const Texture texture)
{
	if (state != State::Live) return;
	mesh.translate(graphic_pos).draw(texture, Color(255, 0, 0, 150), *CResource::GetInstance().GetAlphaRenderer());
}