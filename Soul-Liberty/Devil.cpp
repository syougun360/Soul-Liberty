#include "Devil.h"
#include "Resource.h"
#include "Utility.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "CreateEnemy.h"
#include "MagicSoul.h"
#include "BossManager.h"
#include "Barrier.h"

const int MaxHp = 50;
const Float3 GraphicSize = Float3(450, 450, 0.00001f);

CDevil::CDevil(std::shared_ptr<CTask> task,Float3 pos):
CBossActor(task, Transform(pos + Float3(0, GraphicSize.y / 4, 0), GraphicSize, Float3(0, 0, 0)), MaxHp),
barrier(std::make_unique<CBarrier>())
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 2, 20));
	animation->Append(AnimationType::Attack, AnimationFrame(2, 2, 0));
	animation->Append(AnimationType::Death, AnimationFrame(3, 3, 0));
	animation->OnAnimation(AnimationType::Stop);

	attack_table.insert(std::make_pair(AttackType::CreateEnemy, std::make_shared<CCreateEnemy>()));
	attack_table.insert(std::make_pair(AttackType::Magic, std::make_shared<CMagicSoul>()));

}

//	ボスフィールドに入った処理
void CDevil::InField()
{
	if (state != State::Start) return;

	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	if (utility::Distance(player->transform.GetPos().x, transform.GetPos().x) <= 700)
	{
		player->BossInField();
		state = State::AttackPreparation;
	}
}

//	攻撃の準備処理
void CDevil::AttackPreparation()
{
	if (state != State::AttackPreparation) return;

	attack_count++;
	if (attack_count >= 60)
	{
		animation->OnAnimation(AnimationType::Attack);
		state = State::Attack;
		SetAttackType();
	}

}

//	攻撃の種類を設定する
void CDevil::SetAttackType()
{
	auto attack_type = static_cast<AttackType>(Random(0, static_cast<int>(AttackType::MaxType) -1));
	attack = attack_table.find(attack_type)->second;

	auto boss = task->GetComponent<CBossManager>(CGameObjectHousing::BossName, 0)->GetBoss();
	attack->Start(std::dynamic_pointer_cast<CDevil>(boss));
	power = attack->GetPower();
}

//	攻撃
void CDevil::Attack()
{
	if (state != State::Attack) return;

	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);
	attack->Create(transform.GetPos() - Float3(transform.GetScale().x / 2, 0, 0),
		player->transform.GetPos());

	attack->Update();
}

//	敵を生成
void CDevil::CreateEnemy()
{
	animation->OnAnimation(AnimationType::Attack);
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	enemy_manager->CreateSlimeToBoss(transform.GetPos() - Float3(200, 0, 0));
}

//	ダメージ処理
void CDevil::Damage(const int power)
{
	if (color != Palette::White) return;

	hit_count = 0;
	color = Palette::Red;
	hp -= power;
	if (hp <= 0)
	{
		state = State::Death;
	}
}


//	バリアアップデート
void CDevil::BarrierUpdate()
{
	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	if (collision::AABBToAABB(transform.GetPos() - Float3(0, transform.GetScale().y / 4, 0), Float3(transform.GetScale().x/2,50,50),
		player->transform.GetPos(), player->transform.GetScale()))
	{
		barrier->Create(transform.GetPos(), this);
	}

	barrier->Update(this);

}

//	アップデート
void CDevil::Update()
{
	AttackPreparation();
	animation->Update();
	InField();
	Attack();
	CollisionToPlayerAttack();
	Hit();
	BarrierUpdate();
}

//	描画
void CDevil::Draw()
{
	if (state == State::Death) return;
	auto texture = TextureAsset(CResource::GetInstance().GetBossDevil(animation->GetId()));

	if(direction == Direction::Left)
		left.translate(transform.GetPos()).draw(texture, color, *CResource::GetInstance().GetAlphaRenderer());

	if (direction == Direction::Right)
		right.translate(transform.GetPos()).draw(texture, color, *CResource::GetInstance().GetAlphaRenderer());


	barrier->Draw();

	if (state != State::Attack) return;
	attack->Draw();
}

