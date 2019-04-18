#include "Dragon.h"
#include "Resource.h"
#include "Utility.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "Flame.h"
#include "Breath.h"
#include "BossManager.h"
#include "FlyBreath.h"
#include "MonsterManager.h"
#include "King.h"

const int MaxHp = 300;
const Float3 GraphicSize = Float3(700, 700, 0.00001f);

CDragon::CDragon(std::shared_ptr<CTask> task, Float3 pos) :
CBossActor(task, Transform(pos + Float3(0, GraphicSize.y / 2.5f, 0), GraphicSize, Float3(0, 0, 0)), MaxHp),
attack_type(AttackType::Breath),
death_count(0),
king(std::make_unique<CKing>(task,pos))
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 3, 20));
	animation->Append(AnimationType::Move, AnimationFrame(3, 4, 10));
	animation->Append(AnimationType::Attack, AnimationFrame(4, 4, 0));
	animation->Append(AnimationType::Damage, AnimationFrame(5, 5, 0));
	animation->OnAnimation(AnimationType::Stop);

	state = State::AttackPreparation;

	attack_table.insert(std::make_pair(AttackType::Breath, std::make_shared<CBreath>()));
	attack_table.insert(std::make_pair(AttackType::Flame, std::make_shared<CFlameManager>()));
	attack_table.insert(std::make_pair(AttackType::FlyBreath, std::make_shared<CFlyBreath>()));
}

//	攻撃の終了処理
void CDragon::AttackFinish()
{
	attack_count = 0;
}

//	攻撃準備
void CDragon::AttackPreparation()
{
	if (state != State::AttackPreparation) return;

	attack_count++;
	if (attack_count >= 60)
	{
		attack_count = 0;
		animation->OnAnimation(AnimationType::Attack);
		state = State::Attack;
		SetAttackType();
	}

}

//	攻撃の種類を設定する
void CDragon::SetAttackType()
{
	attack_type = static_cast<AttackType>(Random(0, static_cast<int>(AttackType::MaxType) - 1));
	attack = attack_table.find(attack_type)->second;

	auto boss = task->GetComponent<CBossManager>(CGameObjectHousing::BossName, 0)->GetBoss();
	attack->Start(std::dynamic_pointer_cast<CDragon>(boss));
	power = attack->GetPower();
}

//	攻撃処理
void CDragon::Attack()
{
	if (state != State::Attack) return;

	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	attack->Create(transform.GetPos() - Float3(transform.GetScale().x / 2.5f, transform.GetScale().y / 5, 0),
		player->transform.GetPos());

	attack->Update();

}


//	ダメージ処理
void CDragon::Damage(const int power)
{
	HitPoint(power);

	if (color != Palette::White) return;

	hit_count = 0;
	color = Palette::Red;
}

//	HP処理
void CDragon::HitPoint(const int power)
{
	hp -= power;
	if ((hp % 30) == 0 && attack_type != AttackType::FlyBreath)
	{
		animation->OnAnimation(AnimationType::Damage);
		state = State::AttackPreparation;
	}
	if (hp <= 0)
	{
		animation->OnAnimation(AnimationType::Damage);
		state = State::Death;
		CResource::GetInstance().FadeStartBGM();
	}
}

//	死亡処理
void CDragon::Death()
{
	if (state != State::Death) return;

	death_count++;
	
	if (death_count >= 200)
	{
		state = State::None;
		CResource::GetInstance().StopBGM();
	}
}

//	アップデート
void CDragon::Update()
{
	AttackPreparation();
	Attack();
	CollisionToPlayerAttack();
	Death();
	Hit();

	animation->Update();

	auto monster = task->GetComponent<CMonsterManager>(CGameObjectHousing::MonsterManagerName, 0);
	monster->AutoSoulAbsorption();
}

//	キャラクター描画
void CDragon::CharacterDraw()
{
	if (state == State::Death || state == State::None) return;
	auto texture = TextureAsset(CResource::GetInstance().GetBossDragon(animation->GetId()));

	if (direction == Direction::Left)
		left.rotate(transform.GetRotation()).translate(transform.GetPos()).draw(texture, color, *CResource::GetInstance().GetAlphaRenderer());

	if (direction == Direction::Right)
		right.rotate(transform.GetRotation()).translate(transform.GetPos()).draw(texture, color, *CResource::GetInstance().GetAlphaRenderer());

	if (state != State::Attack) return;

	attack->Draw();

}

//	描画
void CDragon::Draw()
{
	CharacterDraw();
	
	if (state == State::Death || state == State::None)
	{
		king->CharacterDraw();
	}
}

