#include "PlayerJump.h"
#include "Player.h"
#include "CharacterController.h"
#include "GameManager.h"
#include "Floor.h"
#include "Collision.h"

float CPlayerJump::max_power;

CPlayerJump::CPlayerJump():
CPlayerState(),
step(Step::None),
force(0)
{
}

void CPlayerJump::IniData(INIReader ini)
{
	max_power = ini.get<float>(L"Jump.max_power");
}

void CPlayerJump::Finish()
{
	force = 0;
	step = Step::None;
}

void CPlayerJump::OnKeyEvent(Step next_step, float jump_power, CPlayer::AnimationType step, CResource::SE jump_se)
{
	if (player->IsBossFiledNowEvent()) return;
	if (player->IsLargeAction()) return;

	if (CharacterController::JumpKey())
	{
		player->OnAnimation(step);
		this->step = next_step;
		force = jump_power;
		CResource::GetInstance().PlaySE(jump_se);
	}
	
}

void CPlayerJump::CollisionList()
{
	if (step == Step::None) return;
	if (force >= 0) return;

	player->FenceCollision();

	if (player->IsJumpCollision())
	{
		Finish();
		return;
	}
}


void CPlayerJump::Move()
{
	force -= CPlayer::Mass;
	player->transform.Translate(Float3(0, force, 0));
}

void CPlayerJump::StateNoneOnEvent()
{
	if (step != Step::None) return;
		
	OnKeyEvent(Step::First, MaxPower(), CPlayer::AnimationType::JumpStep1, CResource::SE::FirstJump);
}

void CPlayerJump::FirstStep()
{
	if (step != Step::First) return;

	Move();
	OnKeyEvent(Step::Second, MaxPower() * 1.1f, CPlayer::AnimationType::JumpStep2, CResource::SE::SecondJump);
}

void CPlayerJump::SecondStep()
{
	if (step != Step::Second) return;
	Move();
}

void CPlayerJump::Update()
{
	FirstStep();
	SecondStep();
	CollisionList();
	StateNoneOnEvent();
}

