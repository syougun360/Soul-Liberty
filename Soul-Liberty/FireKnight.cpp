#include "FireKnight.h"
#include "Resource.h"
#include "CharacterController.h"
#include "FPS.h"
#include "Player.h"
#include "Utility.h"
#include "Collision.h"
#include "EnemyActor.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"
#include "FireEffect.h"

CFireKnight::CFireKnight(std::shared_ptr<CTask> task) :
CMonsterActor(task, MonsterUI(Point(0,0), Point(0, 0), CResource::MonsterUIType::FireKnight), "FireKnight")
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(1, 1, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(2, 2, 0));
	animation->Append(AnimationType::Hit, AnimationFrame(3, 3, 0));
	OnAnimation(AnimationType::Stop);
	
	Init(CFPS::FPS * ini.get<int>(L"FireKnight.hp"), MonsterSoul(ini.get<int>(L"FireKnight.soul"), Palette::Red));
}

//	UŒ‚‚Ìî•ñ
void CFireKnight::OnAttackInfo()
{
	state = State::Attack;
	OnAnimation(AnimationType::Attack);
}

//	UŒ‚I—¹ˆ—
void CFireKnight::AttackFinish()
{
	if (isCombine) return;
	OnAnimation(AnimationType::Move);
	state = State::Return;
	SetOriginalPos();
	effects.push_back(std::make_unique<CFireEffect>(transform.GetPos(), direction));
}

//	“G‚É‹ß‚Ã‚­ˆ—
void CFireKnight::ApproacheToEnemy()
{
	Float3 velocity = utility::MoveBy(transform.GetPos(),near_enemy->transform.GetPos() + Float3(0,50,0),10);
	transform.Translate(velocity);

	CollisionSphereToEnemy(transform);

}

//	UŒ‚ˆ—
void CFireKnight::Attack()
{
	if (state != State::Attack) return;
	ApproacheToEnemy();

	if (!IsNearToEnemy())
	{
		AttackFinish();
		return;
	}
	if (utility::Distance(near_enemy->transform.GetPos(), transform.GetPos()) <= 100)
	{
		CResource::GetInstance().PlaySE(CResource::SE::FireKnightAttack);
		OnAnimation(AnimationType::Hit);
	}
}

///	‡‘Ì‚µ‚½‚ÌUŒ‚
void CFireKnight::CombineAttack()
{
	if (CanCombineAttack())
	{
		effects.push_back(std::make_unique<CFireEffect>(player->GetAttackCollisionPos(), player->GetDirection(),1.0f));
	}

	for (auto& effect : effects)
	{
		if (CollisionSphereToEnemy(effect->transform) || 
			CollisionStaticObject(effect->transform))
		{
			effect->Finish();
		}
	}

	EffectDraw();
}

void CFireKnight::Update()
{
	PositionCorrection();
	Appearance();
	AttackStartTiming();
	LimitTime();
	Move();
	Death();
	Attack();
	ReturnUpdate();
	animation->Update();
	
	CombineUpdate();

	for (auto& effect : effects)
	{
		effect->Update();
	}

	Erase_if(effects, [](std::unique_ptr<CFireEffect>& effect)
	{
		return effect->IsNone();
	});
}

void CFireKnight::Draw()
{
	if (state == State::Death || state == State::None) return;

	CharaterDraw(*CResource::GetInstance().GetFireKnightBackTexture(animation->GetId()), Palette::Red);
	CharaterDraw(TextureAsset(CResource::GetInstance().GetFireKnight(animation->GetId())));
	EffectDraw();
	HpGageDraw();
}

void CFireKnight::EffectDraw()
{
	for (auto& effect : effects)
	{
		effect->Draw();
	}
}