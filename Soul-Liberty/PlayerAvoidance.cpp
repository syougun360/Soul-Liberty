#include "PlayerAvoidance.h"
#include "CharacterController.h"
#include "GameManager.h"
#include "Player.h"
#include "Resource.h"

float CPlayerAvoidance::max_speed ;
int CPlayerAvoidance::limit_count ;

CPlayerAvoidance::CPlayerAvoidance():
CPlayerState(),
velocity(Float3(0,0,0)),
count(0)
{
}

void CPlayerAvoidance::IniData(INIReader ini)
{
	max_speed = ini.get<float>(L"Avoidance.max_speed");
	limit_count = ini.get<int>(L"Avoidance.limit_count");
}

void CPlayerAvoidance::OnEvent()
{
	if (player->IsBossFiledNowEvent()) return;
	if (player->IsNowDamage()) return;
	if (state == State::Live) return;

	if (CharacterController::AvoidKey())
	{
		state = State::Live;
		player->OnAnimation(CPlayer::AnimationType::Avoidance);
		CResource::GetInstance().PlaySE(CResource::SE::PlayerAvoid);
		velocity.x = player->GetDirection() * MaxSpeed();
	}
}

void CPlayerAvoidance::Move()
{
	if (state == State::None) return;
	count++;
	if (count >= LimitCount())
	{
		Finish();
	}

	PushBack();
	player->transform.Translate(velocity);
}

void CPlayerAvoidance::PushBack()
{
	if (!player->IsFrontCollision()) return;
	
	player->transform.Translate(-velocity);
	Finish();
}

void CPlayerAvoidance::Finish()
{
	player->OnAnimation(CPlayer::AnimationType::Move);
	state = State::None;
	count = 0;
	velocity.x = 0;
}

void CPlayerAvoidance::Update()
{
	OnEvent();
	Move();
}