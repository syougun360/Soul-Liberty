#include "SlimeBlack.h"
#include "Resource.h"
#include "Player.h"
#include "GameManager.h"
#include "SlimeAttack.h"
/*
int MaxHp = 3;
int AttackPower = 1;
int SoulPoint = 10;

float JumpPower = 7.0f;
float Mass = 0.5f;
float Speed = 2.0f;
*/

int CSlimeBlack::max_hp;
int CSlimeBlack::attack_power;
int CSlimeBlack::soul_point;
float CSlimeBlack::jump_power;
float CSlimeBlack::mass;
float CSlimeBlack::speed;

CSlimeBlack::CSlimeBlack(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type,CResource::MonsterUIType soul_type) :
CSlimeActor(task, Transform(pos + Float3(0, (100 * (static_cast<int>(scale_type) - 0)) / 2, 0),
Float3(100.0f, 100.0f, 0.0001f) * static_cast<float>(scale_type), Float3(0, 0, 0)), scale_type,soul_type)
{
	IniDataList();
	auto scale = static_cast<int>(scale_type);
	Init(max_hp * scale, soul_point * scale, 
		CEnemyHitAction(mass, jump_power/4 * scale, speed), 
		std::make_shared<CSlimeAttack>(attack_power * scale, jump_power, mass, speed));
}

//	iniÉfÅ[É^List
void CSlimeBlack::IniDataList()
{
	max_hp = ini.get<int>(L"SlimeBlack.max_hp");
	attack_power = ini.get<int>(L"SlimeBlack.attack_power");
	soul_point = ini.get<int>(L"SlimeBlack.soul_point");
	jump_power = ini.get<float>(L"SlimeBlack.jump_power");
	mass = ini.get<float>(L"SlimeBlack.mass");
	speed = ini.get<float>(L"SlimeBlack.speed");
}

void CSlimeBlack::Start()
{
	GetComponentObject();
	ChangeDirection();
}

void CSlimeBlack::InitAttack()
{
	attack->Init(this);
}

void CSlimeBlack::Attack()
{
	if (state != State::Attack) return;

	attack->Update(this);
	CollisionFloor();
	CollisionPlayerBody();
}

void CSlimeBlack::Update()
{
	ChangeAttackState();
	CollisionPlayerAttack();
	Hit();
	Attack();
	Death();
	TurnUpdate();
}

void CSlimeBlack::Draw()
{
	CharacterDraw(CResource::SlimeType::Black);

	HpGageDraw();

}