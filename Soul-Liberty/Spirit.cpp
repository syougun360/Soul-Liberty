#include "Spirit.h"
#include "Resource.h"
#include "CharacterController.h"
#include "FPS.h"
#include "Player.h"
#include "Utility.h"
#include "Collision.h"
#include "EnemyActor.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"
#include "MagicBullet.h"

CSpirit::CSpirit(std::shared_ptr<CTask> task) :
CMonsterActor(task, MonsterUI(Point(CMonsterManager::UI_Space.x*3, 0), 
Point(0, 0), CResource::MonsterUIType::Spirit), "Spirit", 50)
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(1, 2, 2,20));
	animation->OnAnimation(AnimationType::Stop);
	state = State::None;
	
	Init(CFPS::FPS * ini.get<int>(L"Spirit.hp"), MonsterSoul(ini.get<int>(L"Spirit.soul"), Palette::Lightyellow));
}


//	çUåÇéûÇÃèÓïÒ
void CSpirit::OnAttackInfo()
{
	animation->OnAnimation(AnimationType::Attack);
	attack_count = 0;
	state = State::Attack;
}

void CSpirit::AttackFinish()
{
	if (isCombine) return;
	state = State::Live;
	SetOriginalPos();
}

//	ñÇñ@íeÇ∆ÉIÉuÉWÉFÉNÉgÇÃÇ†ÇΩÇËîªíË
void CSpirit::CollisionMagicToObject()
{
	for (auto& magic : magics)
	{
		if (!magic->IsCollision()) continue;
		if (CollisionSphereToEnemy(magic->transform) ||
			CollisionStaticObject(magic->transform))
		{
			magic->Death();
		}
	}
}

//	çUåÇèàóù
void CSpirit::Attack()
{
	if (state != State::Attack) return;

	attack_count++;
	if (attack_count >= 60)
	{
		for (int i = 0; i < 10; i++)
		{
			magics.push_back(std::make_unique<CMagicBullet>(transform.GetPos(), near_enemy->transform.GetPos()));
		}
		attack_count = 0;
		animation->OnAnimation(AnimationType::Stop);
		CResource::GetInstance().PlaySE(CResource::SE::SpiritAttack);
	}
}


///	çáëÃÇµÇΩéûÇÃçUåÇ
void CSpirit::CombineAttack()
{
	if (CanCombineAttack())
	{
		for (int i = 0; i < 3;i++)
		magics.push_back(std::make_unique<CMagicBullet>(player->GetAttackCollisionPos(), player->GetDirection()));

		CResource::GetInstance().PlaySE(CResource::SE::SpiritAttack);
	}
	MagicBulletDraw();
}

void CSpirit::Update()
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
	CollisionMagicToObject();

	for (auto& magic : magics)
	{
		magic->Update();
	}
	Erase_if(magics, [](std::unique_ptr<CMagicBullet>& magic)
	{	
		return magic->IsDelete();
	});
}

void CSpirit::Draw()
{
	if (state == State::Death || state == State::None) return;

	CharaterDraw(*CResource::GetInstance().GetSpiritBackTexture(animation->GetId()), Palette::Lightyellow);
	CharaterDraw(TextureAsset(CResource::GetInstance().GetSpirit(animation->GetId())));

	MagicBulletDraw();
	HpGageDraw();
}

void CSpirit::MagicBulletDraw()
{
	for (auto& magic : magics)
	{
		magic->Draw();
	}
}