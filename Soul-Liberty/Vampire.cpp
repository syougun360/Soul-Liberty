#include "Vampire.h"
#include "Resource.h"
#include "CharacterController.h"
#include "FPS.h"
#include "Player.h"
#include "Utility.h"
#include "Collision.h"
#include "EnemyActor.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"
#include "DarknessSword.h"

CVampire::CVampire(std::shared_ptr<CTask> task) :
CMonsterActor(task,MonsterUI(Point(CMonsterManager::UI_Space.x * 4, 0),
Point(0, 0), CResource::MonsterUIType::Vampire),"Vampire",50)
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(1, 2, 2, 10));
	animation->OnAnimation(AnimationType::Stop);
	state = State::None;

	Init(CFPS::FPS * ini.get<int>(L"Vampire.hp"), MonsterSoul(ini.get<int>(L"Vampire.soul"), Palette::Purple));
}

//	UŒ‚‚Ìî•ñ
void CVampire::OnAttackInfo()
{
	animation->OnAnimation(AnimationType::Attack);
	state = State::AttackPreparation;
}

//	UŒ‚‚ÌI—¹ˆ—
void CVampire::AttackFinish()
{
	if (isCombine) return;

	state = State::Live;
	original_pos = player->transform.GetPos() + Float3(Random(-200, -100), Random(100, 200), 0);

}

//	UŒ‚‚Ì€”õˆ—
void CVampire::AttackPreparation()
{
	if (state != State::AttackPreparation) return;

	attack_count++;
	if (attack_count >= 100)
	{
		if (!IsNearToEnemy()) return;
		state = State::Attack;
		attack_count = 0;
	}
}
//	Œ“‚ÆƒIƒuƒWƒFƒNƒg‚Æ‚Ì‚ ‚½‚è”»’è
void CVampire::CollisionSwordToObject()
{
	for (auto& sword : swords)
	{
		if (!sword->IsCollision()) continue;
		if (CollisionSphereToEnemy(sword->transform) ||
			CollisionStaticObject(sword->transform))
		{
			sword->Death();
		}
	}
}

//	UŒ‚ˆ—
void CVampire::Attack()
{
	if (state != State::Attack) return;

	for (int i = 0; i < 5; i++)
	{
		swords.push_back(std::make_unique<CDarknessSword>(transform.GetPos() + Float3(0, Random(-100.0f, 100.0f), 0),
			near_enemy->transform.GetPos()));
	}
	animation->OnAnimation(AnimationType::Stop);
	AttackFinish();
}

///	‡‘Ì‚µ‚½‚ÌUŒ‚
void CVampire::CombineAttack()
{
	if (CanCombineAttack())
	{
		swords.push_back(std::make_unique<CDarknessSword>(player->GetAttackCollisionPos(), player->GetDirection()));
	}
	SwordDraw();
	CollisionSwordToObject();
}

void CVampire::Update()
{
	PositionCorrection();
	Appearance();
	AttackStartTiming();
	LimitTime();
	Move();
	Death();
	AttackPreparation();
	Attack();
	ReturnUpdate();
	animation->Update();
	CollisionSwordToObject();
	CombineUpdate();

	for (auto& sword : swords)
	{
		sword->Update();
	}
	Erase_if(swords, [](std::unique_ptr<CDarknessSword>& magic)
	{
		return magic->IsDelete();
	});
}

void CVampire::Draw()
{
	if (state == State::Death || state == State::None) return;

	CharaterDraw(*CResource::GetInstance().GetVampireBackTexture(animation->GetId()), Palette::Purple);
	CharaterDraw(TextureAsset(CResource::GetInstance().GetVampire(animation->GetId())));
	SwordDraw();
	HpGageDraw();
}

void CVampire::SwordDraw()
{
	for (auto& sword : swords)
	{
		sword->Draw();
	}

}
