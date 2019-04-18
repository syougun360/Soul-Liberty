#include "MagicAttack.h"
#include "EnemyActor.h"
#include "Utility.h"
#include "Collision.h"
#include "MagicSoldier.h"

const float EnemyToStickPos = 50;

CMagicAttack::CMagicAttack(const int power, const float jumpforce, const float mass, const float speed) :
CEnemyAttack(power, mass, jumpforce, speed),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Color_Individual,Float3(0,0,0),30.0f,
CParticleScale(7,15),CParticleVelocity(Float3(-1,-1,-1),Float3(1,1,1)),CParticleDuration(30,60),1)),
charge(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Color_Individual, Float3(0, 0, 0), 50.0f, CParticleScale(2.0f, 10.0f),
CParticleVelocity(Float3(0, 0, 0), Float3(0, 0, 0)), CParticleDuration(30, 60), 2))
{
	particles->SetCreate(false);
}


//	初期化
void CMagicAttack::Init(CEnemyActor *enemy)
{
	particles->SetCreate(false);
	state = State::Appearance;
	charge->TransformPoint(enemy->transform.GetPos() + Float3(enemy->GetDirection() * EnemyToStickPos, 0, 0));
}

//	チャージ
void CMagicAttack::Charge(CEnemyActor *enemy)
{
	if (count <= 60) return;
	charge->MoveTo(enemy->transform.GetPos() + Float3(enemy->GetDirection() * EnemyToStickPos, 0, 0), 2);
	charge->Update();
}

//	アップデート
void CMagicAttack::Update(CEnemyActor *enemy)
{
	Attack(enemy);
	Move(enemy);
	Appearance(enemy);
	particles->Update();
}

//	終了処理
void CMagicAttack::Finish(CEnemyActor *enemy)
{	
	Init(enemy);
}

//	魔法弾と敵との距離が限界に来た時の処理
void CMagicAttack::LimitDistance(CEnemyActor *enemy)
{
	const float LimitDist = 600;

	if (utility::Distance(particles->GetPos().x, enemy->transform.GetPos().x) >= LimitDist)
	{
		particles->SetCreate(false);
	}

	if (utility::Distance(particles->GetPos().x, enemy->transform.GetPos().x) >= LimitDist+50)
	{
		dynamic_cast<CMagicSoldier*>(enemy)->OnAttackFinish();
	}

}

//	あたり判定のアップデート
void CMagicAttack::CollisionUpdate(CEnemyActor *enemy)
{
	if (collision::SphereToSphere(particles->GetPos(), enemy->GetPlayerPos(), 50, 50))
	{
		enemy->DamageToThePlayer();
		Finish(enemy);
	}
	if (dynamic_cast<CMagicSoldier*>(enemy)->IsCollisionStaticObjectList(
		Transform(particles->GetPos(), Float3(50, 50, 50), Float3(0, 0, 0))))
	{
		Finish(enemy);
	}
}

//	登場処理
void CMagicAttack::Appearance(CEnemyActor *enemy)
{
	if (state != State::Appearance) return;

	Charge(enemy);
	count++;
	if (count >= 120)
	{
		count = 0;
		state = State::Attack;
		particles->SetCreate(true);
		particles->TransformPoint(enemy->transform.GetPos() +
			Float3(enemy->GetDirection() * enemy->transform.GetScale().x / 2, 0, 0));
		destination = utility::MoveBy(enemy->transform.GetPos(), enemy->GetPlayerPos(), 10);
		CResource::GetInstance().PlaySE(CResource::SE::EnemyMagicAttack);

	}
}

//	攻撃処理
void CMagicAttack::Attack(CEnemyActor *enemy)
{
	if (state != State::Attack) return;

	particles->Update();
	particles->Transformlate(destination);
	LimitDistance(enemy);
	CollisionUpdate(enemy);

	charge->ChildrenUpdate();
	charge->Remove();
}

//	移動処理
void CMagicAttack::Move(CEnemyActor *enemy)
{
	if (state != State::Move) return;

	const float stop_pos = enemy->GetPlayerPos().x + 500;
	if (utility::IsInclude<float>(enemy->transform.GetPos().x, stop_pos, 50))
	{
		Init(enemy);
		state = State::Attack;
	}
}

//	描画
void CMagicAttack::Draw()
{
	particles->Draw();
	charge->Draw();
}