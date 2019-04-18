#include "PlayerAttack.h"
#include "CharacterController.h"
#include "Player.h"
#include "GameManager.h"
#include "PlayerAttackStep.h"
#include "PlayerSpecialAttack.h"
#include "Utility.h"
#include "MonsterManager.h"

const int MaxStep = 3;

int CPlayerAttack::limit_collision_count;
int CPlayerAttack::limit_time;

CPlayerAttack::CPlayerAttack():
CPlayerState(),
transform(Transform(Float3(0, 0, 0), Float3(80, 80, 1), Float3(0, 0, 0))),
collision_count(0),
limit_count(0),
special(std::make_unique<CPlayerSpecialAttack>())
{
	step_list.insert(std::make_pair(0, std::make_shared<AttackStep>(5)));
	step_list.insert(std::make_pair(1, std::make_shared<AttackStep>(5)));
	step_list.insert(std::make_pair(2, std::make_shared<AttackStep>(5)));
	step_list.insert(std::make_pair(MaxStep, std::make_shared<AttackStep>(30)));
}

void CPlayerAttack::IniData(INIReader ini)
{
	limit_collision_count = ini.get<int>(L"Attack.collision_count");
	limit_time = ini.get<int>(L"Attack.limit_time");
}

void CPlayerAttack::Start(std::shared_ptr<CPlayer> player)
{
	this->player = player;
	special->Start(player);
}
int CPlayerAttack::GetPower()const
{
	if (!isCollision) return 0;
	return step->power;
}

void CPlayerAttack::ChangeStep()
{
	limit_count = 0;
	collision_count = 0;
	state = State::Live;
	isCollision = true;
	player->OnAnimation(static_cast<CPlayer::AnimationType>(static_cast<int>(CPlayer::AnimationType::Attack_1) + now_step));
	step = step_list.find(now_step++)->second;
}

void CPlayerAttack::Create()
{
	if (player->IsBossFiledNowEvent()) return;
	if (special->GetState() != CPlayerSpecialAttack::State::None) return;
	if (now_step >= MaxStep) return;

	if (CharacterController::AttackKey() )
	{
		ChangeStep();
	}

	SpecialCreate();

}

void CPlayerAttack::SpecialCreate()
{
	if (now_step == MaxStep)
	{
		now_step++;
		special->Create();
	}
}

void CPlayerAttack::OnCollisionStart()
{
	isCollision = true;
	collision_count = 0;
	limit_count = 0;
	step = step_list.find(MaxStep)->second;
}

void CPlayerAttack::CollisionLimitTime()
{
	collision_count++;
	if (collision_count >= LimitCollisionCount())
	{
		isCollision = false;
	}
}

void CPlayerAttack::LimitTimeUpdate()
{
	if (now_step == 0) return;
	if (special->GetState() != CPlayerSpecialAttack::State::None) return;

	limit_count++;
	if (limit_count >= LimitTime())
	{
		Finish();
	}
}

void CPlayerAttack::Exist()
{
	if (!isCollision) return;

	const auto createposX = transform.GetScale().x / 2 + player->transform.GetScale().x / 4;
	transform.TransformPoint(player->transform.GetPos() + Float3(createposX * player->GetDirection(), 0, 0));
	CollisionLimitTime();
	
}

void CPlayerAttack::Update()
{
	Create();
	Exist();
	LimitTimeUpdate();
	special->Update(this);
}

void CPlayerAttack::Finish()
{
	player->OnAnimation(CPlayer::AnimationType::Move);
	state = State::None;
	now_step = 0;
	limit_count = 0;
}

void CPlayerAttack::Draw()
{
	
}