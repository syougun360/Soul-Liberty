#include "WaterShark.h"
#include "Resource.h"
#include "CharacterController.h"
#include "FPS.h"
#include "WaterGun.h"
#include "EnemyActor.h"
#include "Collision.h"
#include "Task.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"
#include "Player.h"


CWaterShark::CWaterShark(std::shared_ptr<CTask> task) :
CMonsterActor(task, MonsterUI(Point(CMonsterManager::UI_Space.x, 0), Point(0, 0),
CResource::MonsterUIType::WaterShark), "WaterShark")
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(1, 3, 10));
	animation->Append(AnimationType::Attack, AnimationFrame(4, 4, 0));
	OnAnimation(AnimationType::Stop);

	Init(CFPS::FPS * ini.get<int>(L"WaterShark.hp"), MonsterSoul(ini.get<int>(L"WaterShark.soul"), Palette::Aquamarine));
}


//	UŒ‚‚Ìî•ñ
void CWaterShark::OnAttackInfo()
{
	CResource::GetInstance().PlaySE(CResource::SE::WatarSharkAttack);
	state = State::Attack;
	OnAnimation(AnimationType::Attack);
	watar_gun.push_back(std::make_unique<CWaterGun>(transform.GetPos() + Float3(transform.GetScale().x / 2, -30, 0),
		near_enemy->transform.GetPos()));
}

//	UŒ‚I—¹ˆ—
void CWaterShark::AttackFinish()
{
	if (isCombine) return;
	OnAnimation(AnimationType::Move);
	state = State::Live;

}

//	UŒ‚ˆ—
void CWaterShark::Attack()
{
	if (state != State::Attack) return;

	for (auto& watar : watar_gun)
	{
		if (!watar->IsCollision()) continue;
		if (CollisionSphereToEnemy(watar->transform) || 
			CollisionStaticObject(watar->transform))
		{
			watar->Finish();
		}
	}
}

///	‡‘Ì‚µ‚½‚ÌUŒ‚
void CWaterShark::CombineAttack()
{
	if (CanCombineAttack())
	{
		watar_gun.push_back(std::make_unique<CWaterGun>(player->GetAttackCollisionPos(), player->GetDirection()));
	}

	for (auto& watar : watar_gun)
	{
		watar->Draw();

		if (!watar->IsCollision()) continue;
		if (CollisionSphereToEnemy(watar->transform) || 
			CollisionStaticObject(watar->transform))
		{
			watar->Finish();
		}
	}
}

void CWaterShark::Update()
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

	for (auto& watar : watar_gun)
	{
		watar->Update();
	}

	Erase_if(watar_gun, [](std::unique_ptr<CWaterGun>& watar)
	{
		return watar->IsDelete();
	});
}

void CWaterShark::Draw()
{
	if (state == State::Death || state == State::None) return;

	for (auto& watar : watar_gun)
	{
		watar->Draw();
	}
	CharaterDraw(*CResource::GetInstance().GetWaterSharkBackTexture(animation->GetId()), Palette::Aqua);
	CharaterDraw(TextureAsset(CResource::GetInstance().GetWaterShark(animation->GetId())));

	HpGageDraw();
}
