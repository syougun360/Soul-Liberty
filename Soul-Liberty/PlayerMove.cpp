#include "PlayerMove.h"
#include "CharacterController.h"
#include "Utility.h"
#include "Player.h"
#include "GameManager.h"
#include "FPS.h"
#include "Resource.h"

float CPlayerMove::max_speed;
float CPlayerMove::acceleration_speed;
float CPlayerMove::limit_speed;

CPlayerMove::CPlayerMove() :
CPlayerState(),
velocity(Float3(0, 0, 0)),
acceleration(),
foot_smoke(std::make_unique<CFootSmokeSystem>()),
speed(2.0f),
count(0),
isSpeedDown(false)
{
}

void CPlayerMove::IniData(INIReader ini)
{
	max_speed = ini.get<float>(L"Move.max_speed");
	limit_speed = ini.get<float>(L"Move.limit_speed");
	acceleration_speed = ini.get<float>(L"Move.acceleration_speed");
}

void CPlayerMove::Acceleration::LeftUpdate()
{
	if (left > -LimitSpeed())
	{
		left -= AccelerationSpeed();
	}
	right = 0;
}

void CPlayerMove::Acceleration::RightUpdate()
{
	if (right < LimitSpeed())
	{
		right += AccelerationSpeed();
	}
	left = 0;
}

void CPlayerMove::Acceleration::OnStop()
{
	right = 0;
	left = 0;
}

bool CPlayerMove::CanFootSmoke()const
{
	if (player->IsNowJump()) return false;
	if (player->IsNowAttack()) return false;
	if (player->IsNowDamage()) return false;

	return true;
}

void CPlayerMove::SpeedDown()
{
	if (isSpeedDown) return;

	speed = MaxSpeed()/2;
	isSpeedDown = true;

}

void CPlayerMove::SpeedDownUpdate()
{
	if (!isSpeedDown) return;

	count++;
	if (count >= CFPS::FPS)
	{
		count = 0;
		speed = MaxSpeed();
		isSpeedDown = false;
	}
}


void CPlayerMove::VelocitySpeed(const float speed)
{
	velocity.x = speed;

}

void CPlayerMove::ChangeStateLive()
{
	if (state == State::None && 
		!player->IsNowJump() && 
		!player->IsNowAttack() && 
		!player->IsNowDamage() && 
		!player->IsNowAvoid() &&
		!player->IsSummonsCallAnimation())
	{
		player->OnAnimation(CPlayer::AnimationType::Move);
	}
	state = State::Live;

}

void CPlayerMove::Left()
{
	if (!CharacterController::LeftMoveKey()) return;

	player->DirectionLeft();
	VelocitySpeed(-speed + acceleration.left);
	acceleration.LeftUpdate();
	ChangeStateLive();

}

void CPlayerMove::Right()
{
	if (!CharacterController::RightMoveKey()) return;

	player->DirectionRight();
	VelocitySpeed(speed + acceleration.right);
	acceleration.RightUpdate();
	ChangeStateLive();

}

void CPlayerMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey() ||
		CharacterController::RightMoveKey() && CharacterController::LeftMoveKey())
	{
		if (player->IsNowCollisionAttack()) return;
			Finish();
	}
}

void CPlayerMove::OnSpecialAttack()
{
	Finish();
	VelocitySpeed(player->GetDirection() * speed * 10);
	state = State::Live;
}

void CPlayerMove::CollisionList()
{
	if (state != State::Live) return;

	if (player->IsFrontCollision())
	{
		player->transform.Translate(-velocity);
		Finish();
		return;
	}
}

void CPlayerMove::Finish()
{
	acceleration.OnStop();
	VelocitySpeed(0);
	state = State::None;

	if (player->IsNowJump() || player->IsNowAttack() || player->IsNowAvoid()
		|| player->IsNowDamage() || player->IsSummonsCallAnimation()) return;
	player->OnAnimation(CPlayer::AnimationType::Standing);
}

void CPlayerMove::Normal()
{
}


void CPlayerMove::Update()
{
	foot_smoke->Update(this, player->transform.GetPos() -
		Float3(player->GetDirection() * 10, player->transform.GetScale().y / 2 - 20, 10));

	if (player->IsBossFiledNowEvent()) return;
	CollisionList();

	Right();
	Left();
	Stop();
	SpeedDownUpdate();

	if (player->IsLargeAction()) return;
	player->transform.Translate(velocity);
}

void CPlayerMove::NextStageEvent()
{
	player->DirectionRight();
	VelocitySpeed(speed/2 + acceleration.right);
	acceleration.RightUpdate();
	player->transform.Translate(velocity);

	foot_smoke->Update(this, player->transform.GetPos() -
		Float3(player->GetDirection() * 10, player->transform.GetScale().y / 2 - 20, 10));

}

void CPlayerMove::Draw()
{
	foot_smoke->Draw();
}