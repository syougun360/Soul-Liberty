#include "SlimeRed.h"
#include "Resource.h"
#include "Player.h"
#include "GameManager.h"
#include "SlimeAttack.h"

//const int MaxHp = 5;
//const float JumpPower = 10.0f;
//const float Mass = 0.8f;
//const float Speed = 2.0f;
//const int AttackPower = 2;
//const int SoulPoint = 10;

int CSlimeRed::max_hp;
int CSlimeRed::attack_power;
int CSlimeRed::soul_point;
float CSlimeRed::jump_power;
float CSlimeRed::mass;
float CSlimeRed::speed;

CSlimeRed::CSlimeRed(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type,CResource::MonsterUIType soul_type) :
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
void CSlimeRed::IniDataList()
{
	max_hp = ini.get<int>(L"SlimeRed.max_hp");
	attack_power = ini.get<int>(L"SlimeRed.attack_power");
	soul_point = ini.get<int>(L"SlimeRed.soul_point");
	jump_power = ini.get<float>(L"SlimeRed.jump_power");
	mass = ini.get<float>(L"SlimeRed.mass");
	speed = ini.get<float>(L"SlimeRed.speed");
}

void CSlimeRed::InitAttack()
{
	attack->Init(this);
}

void CSlimeRed::Start()
{
	GetComponentObject();
	ChangeDirection();

}
void CSlimeRed::Attack()
{
	if (state != State::Attack) return;

	attack->Update(this);
	CollisionFloor();
	CollisionPlayerBody();
}

void CSlimeRed::Update()
{
	ChangeAttackState();
	CollisionPlayerAttack();
	Attack();
	Hit();
	Death();
	TurnUpdate();
}
void CSlimeRed::Draw()
{
	CharacterDraw(CResource::SlimeType::Red);

	HpGageDraw();

}