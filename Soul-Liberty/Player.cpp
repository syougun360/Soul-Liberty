#include "Player.h"
#include "PlayerMove.h"
#include "PlayerCamera.h"
#include "PlayerJump.h"
#include "PlayerAttack.h"
#include "PlayerAvoidance.h"
#include "Resource.h"
#include "Utility.h"
#include "PlayerDamage.h"
#include "Collision.h"
#include "GameObjectHousing.h"
#include "PlayerGravity.h"
#include "GraphicAnimation.h"
#include "PlayerHpGauge.h"
#include "EnemyManager.h"
#include "Combine.h"
#include "MonsterManager.h"
#include "MonsterActor.h"
#include "DoorManager.h"
#include "GameManager.h"

const Float3 GraphicScale = Float3(256, 256, 0.00001f);
const float CPlayer::Mass = 1.0f;

CPlayer::CPlayer(std::shared_ptr<CTask> task, Float3 pos) :
CActor(task, Transform(pos, Float3(80, 100, 0.01f), Float3(0, 0, 0)),
State::Live,L"engine/data/database/player.ini"),
move(std::make_unique<CPlayerMove>()),
camera(std::make_unique<CPlayerCamera>()),
jump(std::make_unique<CPlayerJump>()),
attack(std::make_unique<CPlayerAttack>()),
avoidance(std::make_unique<CPlayerAvoidance>()),
damage(std::make_unique<CPlayerDamage>()),
hp_gauge(std::make_unique<CPlayerHpGauge>()),
gravity(std::make_unique<CPlayerGravity>()),
combine(std::make_unique<CCombine>(GraphicScale)),
direction(Direction::Right),
left(utility::CreateMirroredBox(GraphicScale, -1)),
right(utility::CreateMirroredBox(GraphicScale, 1)),
animation(std::make_unique<CGraphicAnimation<AnimationType>>())
{
	SignUpAnimation();
}

void CPlayer::SignUpAnimation()
{
	const int move_start_anim = 1;
	const int move_end_anim = move_start_anim + 4;
	const int jump_step1_anim = move_end_anim;
	const int jump_step2_anim = jump_step1_anim + 1;

	const int attack1_anim = jump_step2_anim + 2;
	const int attack1_end = attack1_anim + 1;
	const int attack2_anim = attack1_end + 1;
	const int attack2_end = attack2_anim + 1;
	const int attack3_anim = attack2_end + 1;
	const int attack3_end = attack3_anim + 1;

	const int attack4_start_anim = attack3_end;
	const int attack4_end_anim = attack4_start_anim + 4;

	const int damage_anim = attack4_end_anim;
	const int calll_anim = damage_anim + 1;
	const int avoidance_anim = calll_anim + 1;

	animation->Append(AnimationType::Standing, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(move_start_anim, move_end_anim, 8));
	animation->Append(AnimationType::JumpStep1, AnimationFrame(jump_step1_anim, jump_step1_anim, 0));
	animation->Append(AnimationType::JumpStep2, AnimationFrame(jump_step2_anim, jump_step2_anim, 0));

	animation->Append(AnimationType::Attack_1, AnimationFrame(attack1_anim, attack1_end, attack1_end, 5));
	animation->Append(AnimationType::Attack_2, AnimationFrame(attack2_anim, attack2_end + 1, attack2_end, 5));
	animation->Append(AnimationType::Attack_3, AnimationFrame(attack3_anim, attack3_end, attack3_end, 5));
	animation->Append(AnimationType::Attack_4, AnimationFrame(attack4_start_anim, attack4_end_anim, attack4_end_anim, 15));

	animation->Append(AnimationType::Damage, AnimationFrame(damage_anim, damage_anim, 0));
	animation->Append(AnimationType::Call, AnimationFrame(calll_anim, calll_anim, 0));
	animation->Append(AnimationType::Avoidance, AnimationFrame(avoidance_anim, avoidance_anim, 0));

}

void CPlayer::IniDataList()
{
	move->IniData(ini);
	hp_gauge->IniData(ini);
	jump->IniData(ini);
	avoidance->IniData(ini);
	attack->IniData(ini);
	damage->IniData(ini);
}

void CPlayer::Start()
{
	auto player = task->GetComponent<CPlayer>(CGameObjectHousing::PlayerName, 0);

	camera->Start(player);
	combine->Start(player);
	move->Start(player);
	jump->Start(player);
	attack->Start(player);
	avoidance->Start(player);
	gravity->Start(player);
	damage->Start(player);
	hp_gauge->Start(player);
	player->OnAnimation(CPlayer::AnimationType::Standing);
}

void CPlayer::MonsterCall()
{
	OnAnimation(AnimationType::Call);
	state = State::Call;
}

//	ダメージを大きくアクションする
void CPlayer::DamageLargeAction()
{
	Damage(5);
	damage->LargeAction();
	jump->Finish();
	move->Finish();
}

//	立ちモーションのアニメーションに設定
void CPlayer::SetStandingAnimation()
{
	OnAnimation(AnimationType::Standing);
	state = State::Live;
}

void CPlayer::OnAnimation(AnimationType type)
{
	animation->OnAnimation(type);
}

Float3 CPlayer::GetCameraPos()const
{
	return camera->GetPos();
}
Float3 CPlayer::GetAttackCollisionPos()
{
	return attack->transform.GetPos();
}
float CPlayer::GetAttackCollisionRadius()
{
	return attack->transform.GetScale().x / 2;
}

///	攻撃力
int CPlayer::GetAttacPower()const
{
	return attack->GetPower();
}

bool CPlayer::IsNowAvoid()const
{
	return (avoidance->GetState() == CPlayerState::State::Live);
}

///	攻撃してるかどうか
bool CPlayer::IsNowAttack()const
{
	return (attack->GetState() == CPlayerState::State::Live);
}

///	現在、攻撃あたり判定があるかどうか
bool CPlayer::IsNowCollisionAttack()const
{
	return attack->IsCollision();
}
///	ダメージを受けているかどうか
bool CPlayer::IsNowDamage()const
{
	return (damage->GetState() == CPlayerState::State::Live);
}

bool CPlayer::IsNowJump()const
{
	return !(jump->GetStep() == CPlayerJump::Step::None);
}

///	大ダメージを受けているかどうか
bool CPlayer::IsLargeAction()const
{
	return damage->GetIsLargeAction();
}

void CPlayer::BossInField()
{
	if (state == State::BossInFiled) return;

	CResource::GetInstance().FadeStartBGM();
	move->Finish();
	avoidance->Finish();
	camera->BossInField();
	OnAnimation(CPlayer::AnimationType::Standing);
	state = State::BossInFiled;
}

void CPlayer::AttackHit()
{
	attack->OnHit();
}

void CPlayer::OnHitDoor()
{
	auto door = task->GetComponent<CDoorManager>(CGameObjectHousing::DoorName, 0);
	if (door == nullptr) return;

	if (utility::Distance(transform.GetPos().x,door->transform.GetPos().x) < 100)
	{
		door->OnHit();
	}
}

///	前に移動できるかどうか
bool CPlayer::IsForwardMove()const
{
	if (transform.GetPos().x >= camera->GetPos().x)
		return true;

	return false;
}

///	移動しているかどうか
bool CPlayer::IsNowMove()const
{
	if (move->GetState() == CPlayerState::State::Live)
		return true;

	return false;
}

//	攻撃のあたり判定をなくす
void CPlayer::AttackNonCollision()
{
	attack->OnHit();
}

void CPlayer::SpeedDown()
{
	move->SpeedDown();
}

void CPlayer::OnSpecialAttackMove()
{
	move->OnSpecialAttack();
}

bool CPlayer::IsGravity()
{
	for (auto& name : CGameObjectHousing::collision_gravity_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (collision::AABBToAABB(transform.GetPos() - Float3(0, transform.GetScale().y / 2, 0),
				Float3(transform.GetScale().x + Abs(-move->GetVelocity().x), 10, 10),
				it->transform.GetPos(), it->transform.GetScale()))
			{
				return true;
			}
		}
	}
	return false;
}

bool CPlayer::IsFrontCollision()
{
	for (auto& name : CGameObjectHousing::collision_side_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (it->GetState() == State::None) continue;
			if (collision::AABBToAABB(transform.GetPos() + Float3(direction*transform.GetScale().x/2,0,0),
				Float3(10,transform.GetScale().y/2,transform.GetScale().z) + Float3(Abs(-move->GetVelocity().x), 0, 0),
				it->transform.GetPos(), it->transform.GetScale()))
			{
				return true;
			}
		}
	}
	return false;
}

bool CPlayer::IsBackCollision()
{
	for (auto& name : CGameObjectHousing::collision_side_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (it->GetState() == State::None) continue;
			if (collision::AABBToAABB(transform.GetPos() + Float3(-direction*transform.GetScale().x / 2, 0, 0),
				Float3(10, transform.GetScale().y/2, transform.GetScale().z) + Float3(Abs(-move->GetVelocity().x),0, 0),
				it->transform.GetPos(), it->transform.GetScale()))
			{
				return true;
			}
		}
	}
	return false;
}


void CPlayer::FenceCollision()
{
	for (auto& it : task->GetActor(CGameObjectHousing::FenceName))
	{
		if (collision::AABBToAABB(transform.GetPos() - Float3(0, transform.GetScale().y/2,0),
			Float3(transform.GetScale().x,20,10),
			it->transform.GetPos() + Float3(0,it->transform.GetScale().y / 2, 0), 
			Float3(it->transform.GetScale().x, 10, 10)))
		{
			DamageLargeAction();
		}
	}
}

bool CPlayer::IsJumpCollision()
{
	for (auto& name : CGameObjectHousing::collision_floor_table)
	{
		for (auto& it : task->GetActor(name))
		{
			if (collision::AABBToAABB(transform.GetPos() - Float3(0, transform.GetScale().y / 2 - CGameManager::Gravity, 0),
				Float3(transform.GetScale().x - 10, -CGameManager::Gravity, 10),
				it->transform.GetPos(), it->transform.GetScale()))
			{
				OnAnimation(AnimationType::Move);
				transform.TransformPoint(Float3(transform.GetPos().x,
					it->transform.GetPos().y + it->transform.GetScale().y / 2 + transform.GetScale().y / 2, 0));
				return true;
			}
		}
	}

	return false;
}

void CPlayer::Combine()
{
	if (combine->GetState() != CPlayerState::State::None) return;
	auto monster = task->GetComponent<CMonsterManager>(CGameObjectHousing::MonsterManagerName, 0)->GetMonsterActor();

	for (auto& actor : monster)
	{
		if (!actor->IsCombineable()) continue;
		if (collision::SphereToSphere(transform.GetPos(), actor->transform.GetPos(), 
			transform.GetScale().x / 4, actor->transform.GetScale().x/4))
		{
			combine->OnCombine(actor);
			jump->Finish();
			return;
		}
	}
}

///	ダメージ処理
void CPlayer::Damage(const int power)
{
	if (IsNowDamage()) return;
	hp_gauge->Damage(power);
	damage->StartAction();
	OnAnimation(AnimationType::Damage);
}

//	死亡処理
void CPlayer::Death()
{
	state = State::Death;
	OnAnimation(AnimationType::Damage);
}

///	移動量を取得
Float3 CPlayer::GetVelocity()const
{
	return move->GetVelocity();
}
void CPlayer::DirectionRight()
{
	if (IsNowJump()) return;

	direction = Direction::Right;
}

void CPlayer::DirectionLeft()
{
	if (IsNowJump()) return;

	direction = Direction::Left;
}

void CPlayer::NextStageEventUpdate()
{
	if (state == State::Live)
	{
		state = State::Move;
		OnAnimation(AnimationType::Move);
	}

	move->NextStageEvent();
	combine->Update();
	animation->Update();
}

void CPlayer::MoveRange()
{
	if (utility::Distance(camera->GetPos().x, transform.GetPos().x) < 450) return;

	if (IsNowAvoid())
	{
		transform.Translate(-avoidance->GetVelocity()*1.2f);
		avoidance->Finish();
		return;
	}
	if (IsNowDamage())
	{
		transform.Translate(-damage->GetVelocity()*1.2f);
		return;
	}
	transform.Translate(-move->GetVelocity());
	move->Stop();
}
void CPlayer::Move()
{
	if (combine->IsStart()) return;
	transform.Translate(Float3(0, gravity->GetGravity(), 0));

	MoveRange();

	avoidance->Update();
	jump->Update();
	attack->Update();

	if (avoidance->GetState() != CPlayerState::State::None)return;
	move->Update();

}

void CPlayer::BossFieldEvent()
{
	if (camera->GetState() != CPlayerState::State::Stop) return;
	if (state != State::BossInFiled) return;
	state = State::Live;
	CResource::GetInstance().PlayBGM(CBGMData::BGM::Boss);
}

void CPlayer::Update()
{
	Combine();
	Move();
	camera->Update();
	damage->Update();
	gravity->Update();
	hp_gauge->Update();
	combine->Update();
	animation->Update();

	BossFieldEvent();
	OnHitDoor();
}

void CPlayer::GraphicDraw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetPlayer(animation->GetId()));
	auto graphic_pos = transform.GetPos() + Float3(0, GraphicScale.y / 5, 0);

	if (direction == Direction::Left)
	{
		left.translate(graphic_pos).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
		damage->Draw(left, graphic_pos, texture);
	}
	else if (direction == Direction::Right)
	{
		right.translate(graphic_pos).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
		damage->Draw(right, graphic_pos, texture);
	}
}

void CPlayer::Draw()
{

	combine->CharacterDraw(animation->GetId());
	hp_gauge->Draw();
	combine->Draw();
	move->Draw();
	GraphicDraw();
	attack->Draw();
	combine->SoulDraw();

}