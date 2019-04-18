#include "Golem.h"
#include "Resource.h"
#include "CharacterController.h"
#include "FPS.h"
#include "Tree.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "MonsterManager.h"

CGolem::CGolem(std::shared_ptr<CTask> task) :
CMonsterActor(task, MonsterUI(Point(CMonsterManager::UI_Space.x*2, 0), Point(0, 0),
CResource::MonsterUIType::Golem), "Golem"),
velocity(Float3(0,0,0))
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(1, 1, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(2, 3, 3, 60));
	OnAnimation(AnimationType::Stop);

	Init(CFPS::FPS * ini.get<int>(L"Golem.hp"), MonsterSoul(ini.get<int>(L"Golem.soul"), Palette::Green));
}

//	攻撃時の情報
void CGolem::OnAttackInfo()
{
	trees.clear();
	state = State::AttackPreparation;
	velocity.y = -5.0f;
	CResource::GetInstance().PlaySE(CResource::SE::GolemAttack);
}

//	攻撃終了処理
void CGolem::AttackFinish()
{
	if (isCombine) return;

	state = State::Return;
	OnAnimation(AnimationType::Move);
}

//	攻撃の準備
void CGolem::AttackPreparation()
{
	if (state != State::AttackPreparation) return;

	transform.Translate(velocity);
	if (CollisionStaticObject(transform))
	{
		AttackStart();
	}
}

//	攻撃スタート
void CGolem::AttackStart()
{
	OnAnimation(AnimationType::Attack);
	velocity.y = 0;
	count = 0;
	state = State::Attack;
}

//	攻撃
void CGolem::Attack()
{
	if (state != State::Attack) return;

	const int CreateTreeCount = 50;
	count++;
	if (count == CreateTreeCount)
	{
		for (int i = 0; i < 6; i++)
		{
			trees.push_back(std::make_unique<CTree>(player->transform.GetPos() + Float3(Random(-500, 500), 100, 0)));
		}
	}
	else if (count >= CreateTreeCount * 2)
	{
		AttackFinish();
	}
}

//	木々のアップデート
void CGolem::TreesUpdate()
{
	for (auto& tree : trees)
	{
		tree->Update(task);
		if (!tree->CanCollision()) continue;
		CollisionAABBToEnemy(tree->transform);
	}
}

///	合体した時の攻撃
void CGolem::CombineAttack()
{
	if (CanCombineAttack())
	{
		trees.push_back(std::make_unique<CTree>(player->GetAttackCollisionPos(), player->GetDirection()));
	}

	for (auto& tree : trees)
	{
		tree->Draw();

		if (CollisionStaticObject(tree->transform) ||
			CollisionAABBToEnemy(tree->transform))
		{
			tree->Finish();
		}
	}
}

void CGolem::Update()
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
	TreesUpdate();
	CombineUpdate();

	Erase_if(trees, [](std::unique_ptr<CTree>& tree)
	{
		return tree->IsDelete();
	});
}

void CGolem::Draw()
{
	if (state == State::Death || state == State::None) return;

	for (auto& tree : trees)
	{
		tree->Draw();
	}

	CharaterDraw(*CResource::GetInstance().GetGolemBackTexture(animation->GetId()), Palette::Green);
	CharaterDraw(TextureAsset(CResource::GetInstance().GetGolem(animation->GetId())));

	HpGageDraw();
}
