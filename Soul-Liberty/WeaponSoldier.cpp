#include "WeaponSoldier.h"
#include "Resource.h"
#include "Player.h"
#include "GameManager.h"
#include "EnemyHitAction.h"
#include "WeaponAttack.h"
#include "Utility.h"
#include "GameObjectHousing.h"
#include "Collision.h"

//const int MaxHp = 3;
//const int AttackPower = 1;
//const int SoulPoint = 15;
//
//const float JumpPower = 7.0f;
//const float Mass = 0.5f;
//const float Speed = 2.0f;

const float Size = 130.0f;

int CWeaponSoldier::max_hp;
int CWeaponSoldier::attack_power;
int CWeaponSoldier::soul_point;
float CWeaponSoldier::jump_power;
float CWeaponSoldier::mass;
float CWeaponSoldier::speed;

CWeaponSoldier::CWeaponSoldier(std::shared_ptr<CTask> task, Float3 pos, CResource::MonsterUIType soul_type) :
CEnemyActor(task, Transform(pos + Float3(0, Size/4, 0),
Float3(Size, Size, 0.0001f), Float3(0, 0, 0)),soul_type),
animation(std::make_unique<CGraphicAnimation<AnimationType>>())
{
	animation->Append(AnimationType::Move, AnimationFrame(0, 2, 15));
	animation->Append(AnimationType::Attack, AnimationFrame(2, 4, 5));

	IniDataList();
	Init(max_hp, soul_point,
		CEnemyHitAction(mass, jump_power / 4, speed),
		std::make_shared<CWeaponAttack>(attack_power, jump_power, mass, speed));
}

//	iniÉfÅ[É^List
void CWeaponSoldier::IniDataList()
{
	max_hp = ini.get<int>(L"WeaponSoldier.max_hp");
	attack_power = ini.get<int>(L"WeaponSoldier.attack_power");
	soul_point = ini.get<int>(L"WeaponSoldier.soul_point");
	jump_power = ini.get<float>(L"WeaponSoldier.jump_power");
	mass = ini.get<float>(L"WeaponSoldier.mass");
	speed = ini.get<float>(L"WeaponSoldier.speed");
}

void CWeaponSoldier::Start()
{
	GetComponentObject();
	ChangeDirection();
	animation->OnAnimation(AnimationType::Move);
}

void CWeaponSoldier::StartAttack()
{
	animation->OnAnimation(AnimationType::Attack);
}

void CWeaponSoldier::InitAttack()
{
	attack->Init(this);
}

bool CWeaponSoldier::IsGravity()
{
	for (auto& name : CGameObjectHousing::collision_gravity_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (collision::AABBToAABB(transform.GetPos(),transform.GetScale(),it->transform.GetPos(), it->transform.GetScale()))
			{
				return true;
			}
		}
	}
	return false;
}

void CWeaponSoldier::Attack()
{
	if (state != State::Attack) return;
	
	attack->Update(this);

	CollisionPlayerBody();
}

void CWeaponSoldier::ChangeDirection()
{
	if (utility::IsInclude<float>(transform.GetPos().x,player->transform.GetPos().x,100)) return;
	if (transform.GetPos().x < player->transform.GetPos().x)
	{
		direction = Direction::Right;
	}
	if (transform.GetPos().x > player->transform.GetPos().x)
	{
		direction = Direction::Left;
	}
}

void CWeaponSoldier::Update()
{
	ChangeAttackState();
	CollisionPlayerAttack();
	Hit();
	Attack();
	Death();
	TurnUpdate();
	ChangeDirection();
	animation->Update();


	if (IsGravity())
	{
		gravity = 0;
		return;
	}

	if (!IsGravity())
	{
		gravity = CGameManager::Gravity;
	}

	transform.Translate(Float3(0, gravity, 0));
}

void CWeaponSoldier::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetWeaponEnemy(animation->GetId()));

	if (direction == Direction::Left)
		left.translate(transform.GetPos()).draw(texture, hit_color,*CResource::GetInstance().GetAlphaRenderer());

	if (direction == Direction::Right)
		right.translate(transform.GetPos()).draw(texture, hit_color,*CResource::GetInstance().GetAlphaRenderer());

	HpGageDraw();

}