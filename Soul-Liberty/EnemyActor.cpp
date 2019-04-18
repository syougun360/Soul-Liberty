#include "EnemyActor.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "Collision.h"
#include "Floor.h"
#include "MonsterManager.h"
#include "Utility.h"
#include "EnemyHitAction.h"
#include "EnemyAttack.h"

CEnemyActor::CEnemyActor(std::shared_ptr<CTask> task, Transform transform,CResource::MonsterUIType soul_type) :
CActor(task, transform, State::Live, L"engine/data/database/enemy.ini"),
left(utility::CreateMirroredBox(transform.GetScale(), 1)),
right(utility::CreateMirroredBox(transform.GetScale(), -1)),
direction(Direction::Left),
soul_type(soul_type),
hit_color(Palette::White)
{
}

void CEnemyActor::Init(int hp, int soul_point, CEnemyHitAction hit_action, std::shared_ptr<CEnemyAttack> attack)
{
	max_hp = hp;
	this->hp = hp;
	this->soul_point = soul_point;
	this->hit_action = std::make_unique<CEnemyHitAction>(hit_action.GetMass(), hit_action.GetForce(), hit_action.GetKnockBack());
	this->attack = attack;
}
	
///	オブジェクトデータを取得
void CEnemyActor::GetComponentObject()
{
	player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);
}

Float3 CEnemyActor::GetPlayerPos()const
{
	return player->transform.GetPos();
}

//	床と当たったかどうかを取得
bool CEnemyActor::IsCollisionFloor()
{
	for (auto& name : CGameObjectHousing::collision_floor_table)
	{
		for (auto& floor : task->GetActor(name))
		{
			if (collision::AABBToAABB(transform.GetPos() - Float3(0, transform.GetScale().y / 2, 0),
				Float3(transform.GetScale().x, 10, transform.GetScale().z),
				floor->transform.GetPos(), floor->transform.GetScale()))
			{
				return true;
			}
		}
	}
	return false;
}

//	死亡処理
void CEnemyActor::Death()
{
	if (state != State::Death) return;

	auto monster = task->GetComponent<CMonsterManager>(CGameObjectHousing::MonsterManagerName, 0);

	hit_action->Update(this);

	if (hit_action->GetVelocity().y > 0) return;

	if (IsCollisionFloor())
	{
		monster->CreateSoulRelease(soul_type, transform.GetPos(), soul_point);
		isDelete = true;
	}
}

//	当たった処理
void CEnemyActor::Hit()
{
	if (state != State::Hit) return;

	hit_action->Update(this);

	if (IsCollisionFloor())
	{
		hit_action->Init();
		hit_color = Palette::White;
		state = State::Live;
	}
}

///	攻撃状態にする
void CEnemyActor::ChangeAttackState()
{
	if (state != State::Live) return;

	if (utility::Distance(transform.GetPos().x, player->transform.GetPos().x) <= 600)
	{
		InitAttack();
		state = State::Attack;
	}
}


///	当たった時
void CEnemyActor::OnHit()
{
	hit_action->OnHit(player);
}

//	プレイヤー攻撃とのあたり判定
void CEnemyActor::CollisionPlayerAttack()
{
	if (!player->IsNowCollisionAttack()) return;

	if (collision::SphereToSphere(transform.GetPos(), player->GetAttackCollisionPos(),
		transform.GetScale().x / 2, player->GetAttackCollisionRadius() / 2))
	{
		OnHit();
		Damage();
		player->AttackHit();
	}
}

//	プレイヤーにダメージ処理
void CEnemyActor::DamageToThePlayer()
{
	player->Damage(attack->GetPower());
}

///	プレイヤーの体と当った処理
bool CEnemyActor::CollisionPlayerBody()
{
	if (state == State::Hit) return false;
	if (player->IsNowAvoid()) return false;
	if (player->IsNowAttack()) return false;

	if (collision::SphereToSphere(transform.GetPos(), player->transform.GetPos(),
		transform.GetScale().x / 4, player->transform.GetScale().x / 4))
	{
		InitAttack();
		OnHit();
		DamageToThePlayer();
		state = State::Hit;
		return true;
	}
	return false;
}

//	方向の切り替わる処理
void CEnemyActor::TurnUpdate()
{
	for (auto& name : CGameObjectHousing::collision_side_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (collision::AABBToAABB(transform.GetPos(), transform.GetScale() - Float3(0, 30, 0),
				it->transform.GetPos(), it->transform.GetScale()))
			{
				PushBack();
				return;
			}
		}
	}
}

//	押し戻す
void CEnemyActor::PushBack()
{
	direction *= -1;
	transform.Translate(Float3(direction * attack->GetSpeed() * hit_action->GetVelocity().x*1.5f, 0, 0));
	hit_action->Init();
	state = State::Live;
}

//	ダメージ処理
void CEnemyActor::Damage()
{
	if (state == State::Hit || state == State::Death) return;

	hp--;
	if (hp <= 0)
	{
		CResource::GetInstance().PlaySE(CResource::SE::EnemyDeath);
		hit_action->OnDeathVelocity();
		state = State::Death;
		return;
	}

	CResource::GetInstance().PlaySE(CResource::SE::Hit);
	state = State::Hit;
	hit_count = 0;
	hit_color = Palette::Red;

}

//	HPゲージの描画
void CEnemyActor::HpGageDraw()
{
	const float GageSize = 80.0f;
	Billboard(Float3(GageSize + 6.0f, 12.0f, 1.0f), transform.GetPos() + Float3(0, transform.GetScale().y / 2, 0)).draw(Color(50, 50, 50, 30));
	Billboard(Float3(GageSize * hp / max_hp, 7.0f, 1.0f), transform.GetPos() + Float3(-GageSize / 2 + GageSize / 2 * hp / max_hp, transform.GetScale().y / 2, 0)).draw(Palette::Red);
}