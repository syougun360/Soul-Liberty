#include "SlimeBlue.h"
#include "Resource.h"
#include "Player.h"
#include "GameManager.h"
#include "SlimeAttack.h"

//const int MaxHp = 5;
//const float JumpPower = 6.0f;
//const float Mass = 0.5f;
//const float Speed = 2.0f;
//const int AttackPower = 1;
//const int SoulPoint = 10;

int CSlimeBlue::max_hp;
int CSlimeBlue::attack_power;
int CSlimeBlue::soul_point;
float CSlimeBlue::jump_power;
float CSlimeBlue::mass;
float CSlimeBlue::speed;

CSlimeBlue::CSlimeBlue(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type, CResource::MonsterUIType soul_type) :
CSlimeActor(task, Transform(pos + Float3(0, (100 * (static_cast<int>(scale_type) - 0)) / 2, 0),
Float3(100.0f, 100.0f, 0.0001f) * static_cast<float>(scale_type), Float3(0, 0, 0)), scale_type,soul_type)
{
	IniDataList();
	auto scale = static_cast<int>(scale_type);
	Init(max_hp * scale, soul_point * scale,
		CEnemyHitAction(mass, jump_power / 4 * scale, speed),
		std::make_shared<CSlimeAttack>(attack_power * scale, jump_power, mass, speed));
}

//	iniÉfÅ[É^List
void CSlimeBlue::IniDataList()
{
	max_hp = ini.get<int>(L"SlimeBlue.max_hp");
	attack_power = ini.get<int>(L"SlimeBlue.attack_power");
	soul_point = ini.get<int>(L"SlimeBlue.soul_point");
	jump_power = ini.get<float>(L"SlimeBlue.jump_power");
	mass = ini.get<float>(L"SlimeBlue.mass");
	speed = ini.get<float>(L"SlimeBlue.speed");
}
void CSlimeBlue::Start()
{
	GetComponentObject();
	ChangeDirection();
}

void CSlimeBlue::InitAttack()
{
	attack->Init(this);
}

void CSlimeBlue::Attack()
{
	if (state != State::Attack) return;
	
	attack->Update(this);
	CollisionFloor();

	if (CollisionPlayerBody())
	{
		player->SpeedDown();
	}
}

void CSlimeBlue::Update()
{
	ChangeAttackState();
	CollisionPlayerAttack();
	Hit();
	Attack();
	Death();

	TurnUpdate();
}

void CSlimeBlue::Draw()
{
	CharacterDraw(CResource::SlimeType::Blue);

	HpGageDraw();

}