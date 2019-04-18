#include "BossActor.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "Utility.h"
#include "Resource.h"

CBossActor::CBossActor(std::shared_ptr<CTask> task, Transform transform, int hp) :
CActor(task, transform,State::Start,L"engine/data/database/boss.ini"),
animation(std::make_unique<CGraphicAnimation<AnimationType>>()),
left(utility::CreateMirroredBox(transform.GetScale(), 1)),
right(utility::CreateMirroredBox(transform.GetScale(), -1)),
direction(Direction::Left),
hp(hp),
max_hp(hp), 
hit_count(0),
attack_count(0),
power(1),
color(Palette::White)
{
}

//	プレイヤー攻撃とのあたり判定
void CBossActor::CollisionToPlayerAttack()
{
	if (state == State::Hit || state == State::Death) return;

	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	if (!player->IsNowCollisionAttack()) return;

	if (collision::AABBToAABB(transform.GetPos() + Float3(transform.GetScale().x / 3, 0, 0), transform.GetScale(),
		player->GetAttackCollisionPos(), player->transform.GetScale()))
	{
		CResource::GetInstance().PlaySE(CResource::SE::Hit);
		AttackFinish();
		Damage(player->GetAttacPower());
		player->AttackNonCollision();
	}
}

///	静的なオブジェクトのあたり判定
bool CBossActor::CollisionStaticObject(const std::string& name, const Transform& transform)
{
	for (auto& it : task->GetActor(name))
	{
		if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
			it->transform.GetPos(), it->transform.GetScale()))
		{
			AttackFinish();
			return true;
		}
	}
	return false;
}

//	プレイヤーとのあたり判定
bool CBossActor::CollisionToPlayer(const Transform& transform)
{
	if (state == State::Hit || state == State::Death) return false;

	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	if (collision::SphereToSphere(transform.GetPos(), player->transform.GetPos(),
		transform.GetScale().x / 2, player->transform.GetScale().x / 2))
	{
		player->Damage(power);
		AttackFinish();
		return true;
	}

	return false;
}

//	ヒット処理
void CBossActor::Hit()
{
	if (color != Palette::Red) return;

	hit_count++;
	if (hit_count >= 20)
	{
		color = Palette::White;
		hit_count = 0;
	}
}


//	攻撃準備に戻す
void CBossActor::ReturnAttackPreparation()
{
	animation->OnAnimation(AnimationType::Stop);
	state = State::AttackPreparation;
	attack_count = 0;
}

//	ダメージを大きくアクションする
void CBossActor::PlayerDamageLargeAction()
{
	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);
	player->DamageLargeAction();
}