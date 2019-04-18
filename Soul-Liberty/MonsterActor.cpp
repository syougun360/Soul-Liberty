#include "MonsterActor.h"
#include "MonsterManager.h"
#include "GameObjectHousing.h"
#include "Player.h"
#include "FPS.h"
#include "Utility.h"
#include "Resource.h"
#include "GameApplication.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "SlimeActor.h"
#include "WeaponSoldier.h"
#include "MagicSoldier.h"
#include "BossManager.h"
#include "BossActor.h"
#include "CharacterController.h"

const float CMonsterActor::Size = 200.0f;

CMonsterActor::CMonsterActor(std::shared_ptr<CTask> task, MonsterUI ui, std::string name, int call_alpha) :
CActor(task, Transform(Float3(0, 0, 0), Float3(Size, Size, 0.000001f), 
Float3(0, 0, 0)), State::Live, L"engine/data/database/monster.ini"),
name(name),
left(utility::CreateMirroredBox(transform.GetScale(), 1)),
right(utility::CreateMirroredBox(transform.GetScale(), -1)),
left_back(utility::CreateMirroredBox(transform.GetScale()*1.1f, 1)),
right_back(utility::CreateMirroredBox(transform.GetScale()*1.1f, -1)),
call(std::make_unique<CMonsterCall>(CMonsterManager::UI_Pos + ui.pos, ui.pos_adjustment, ui.type, call_alpha)),
ui_pos(ui.pos),
isCombine(false),
animation(std::make_unique<CGraphicAnimation<AnimationType>>()),
summons_anim(std::make_unique<CGraphicAnimation<CResource::MonsterUIType>>())
{
	summons_anim->Append(ui.type, AnimationFrame(0, 5, 5, 5));
	summons_anim->OnAnimation(ui.type);
}

CMonsterActor::CMonsterActor() :
CActor(), max_hp(0)
{

}

void CMonsterActor::Init(int hp, MonsterSoul soul)
{
	max_hp = hp;
	this->soul = std::make_unique<CSoul>(soul.point, soul.color);
}

Palette CMonsterActor::GetSoulColor()const
{
	return soul->GetColor();
}

Float2 CMonsterActor::GetCallUIPos()const
{
	return call->GetPos();
}

void CMonsterActor::Start(std::shared_ptr<CPlayer> player)
{
	this->player = player;
	soul->Start(player);
}

///	前回の魂を継続させるための設定
void CMonsterActor::ContinuationSoul(double point)
{
	soul->Continuation(point);
}

double CMonsterActor::GetSoulPoint()const
{
	return soul->GetPoint();
}

//	召喚アニメーションを設定
void CMonsterActor::OnAnimationSummons()
{
	summons_anim->OnAnimation(call->GetId());
}

void CMonsterActor::Init()
{
	if (isCombine) return;
	hp = max_hp;
	alpha = 255;
	direction = Direction::Right;

	if (IsExistence()) return;
	OnAnimation(AnimationType::Move);
	transform.TransformPoint(Float3(player->GetCameraPos().x - 700, Random(100, 200), 0));
	state = State::Appearance;
	attack_count = 0;
	SetOriginalPos();

}

void CMonsterActor::SetOriginalPos()
{
	original_pos = Float3(Random(-200, -100) + player->GetCameraPos().x, 
					Random(-100, 100) + player->GetCameraPos().y, 0);
}

bool CMonsterActor::IsCall()
{
	if (state == State::None) return false;
	if (soul->IsMaxGauge())
	{
		soul->Use();
		return true;
	}

	return false;
}

//	合体攻撃可能かどうか
bool CMonsterActor::CanCombineAttack()const
{
	if (player->IsNowCollisionAttack() && CharacterController::AttackKey())
	{
		return true;
	}
	return false;
}

bool CMonsterActor::IsCombineLittle()const
{
	if (soul->GetState() != CSoul::State::None) return false;
	return (soul->GetPoint() <= 5);
}

bool CMonsterActor::IsExistence()
{
	if (state == State::Live) return false;
	if (state == State::Death) return false;

	return true;
}

void CMonsterActor::CreateRelease(Float3 create_pos, Float2 monster_ui_pos ,const int point)
{
	soul->CreateRelease(create_pos, monster_ui_pos ,point);
}

void CMonsterActor::OnAnimation(const AnimationType type)
{
	animation->OnAnimation(type);
}

void CMonsterActor::EnableToCall()
{
	call->MaxAlpha();
	state = State::Live;
}

//	自動で魂を吸収
void CMonsterActor::AutoSoulAbsorption()
{
	if (isCombine) return;
	if (soul->GetState() == CSoul::State::Use) return;

	soul->AutoAbsorption();
}

//	登場処理
void CMonsterActor::Appearance()
{
	if (state != State::Appearance) return;
	acceleration += 0.5f;
	auto velocity = utility::MoveBy(transform.GetPos(), original_pos, acceleration);
	transform.Translate(velocity);
	if (utility::IsInclude<float>(transform.GetPos().x, original_pos.x, 100))
	{
		acceleration = 0;
		state = State::Live;
		OnAnimation(AnimationType::Stop);
	}
}

//	死亡処理
void CMonsterActor::Death()
{
	if (state != State::Death) return;
	alpha = 0;
}

//	移動処理
void CMonsterActor::Move()
{
	if (!player->IsForwardMove()) return;
	transform.Translate(player->GetVelocity());
}

//	ダメージ処理
void CMonsterActor::Damage()
{
	if (state == State::Hit) return;

	hp--;
	state = State::Hit;
}

//	魂の初期化
void CMonsterActor::OnInitSoul()
{
	if (!isCombine || state != State::Live) return;
	soul->Init();
}

//	合体時処理
void CMonsterActor::OnCombine()
{
	state = State::Live;
	hp = 0;
	isCombine = true;
	soul->MaxAbsorption();
}

//	合体可能かどうか
bool CMonsterActor::IsCombineable()const
{
	if (state == State::Return) return false;
	if (state == State::Live) return true;
	return false;
}

//	合体処理
void CMonsterActor::CombineUpdate()
{
	if (!isCombine) return;

	CombineAttack();
	if (soul->GetPoint() <= 0)
	{
		isCombine = false;
	}
}

//	限界時間
//	時間をHPにしている
void CMonsterActor::LimitTime()
{
	if (state == State::Death) return;
	if (hp < 0)
	{
		state = State::Death;
		return;
	}
	hp--;
	AlphaUpdate();
}

///	敵の近くにいるかどうか
bool CMonsterActor::IsNearToEnemy()
{
	if (IsNearToSlimeEnemy()) return true;
	if (IsNearToWeaponEnemy()) return true;
	if (IsNearToMagicEnemy()) return true;
	if (IsNearToBoss()) return true;

	return false;
}

///	敵の近くにいるかどうか
bool CMonsterActor::IsNearToSlimeEnemy()
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->SlimeGetSize(); i++)
	{
		auto enemy = enemy_manager->SlimeGetInstance(i);
		if (utility::IsInclude<float>(player->GetCameraPos().x, enemy->transform.GetPos().x, 500.0f))
		{
			near_enemy = enemy;
			return true;
		}
	}
	return false;
}
///	敵の近くにいるかどうか
bool CMonsterActor::IsNearToWeaponEnemy()
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->WeaponGetSize(); i++)
	{
		auto enemy = enemy_manager->WeaponGetInstance(i);
		if (utility::IsInclude<float>(player->GetCameraPos().x, enemy->transform.GetPos().x, 500.0f))
		{
			near_enemy = enemy;
			return true;
		}
	}
	return false;
}
///	敵の近くにいるかどうか
bool CMonsterActor::IsNearToMagicEnemy()
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->MagicGetSize(); i++)
	{
		auto enemy = enemy_manager->MagicGetInstance(i);
		if (utility::IsInclude<float>(player->GetCameraPos().x, enemy->transform.GetPos().x, 500.0f))
		{
			near_enemy = enemy;
			return true;
		}
	}
	return false;
}

///	敵の近くにいるかどうか
bool CMonsterActor::IsNearToBoss()
{
	auto boss_manager = task->GetComponent<CBossManager>(CGameObjectHousing::BossName, 0);
	if (boss_manager == nullptr) return false;

	auto boss = boss_manager->GetBoss();
	
	if (boss->IsDeath()) return false;

	if (utility::IsInclude<float>(player->GetCameraPos().x, boss->transform.GetPos().x, 800.0f))
	{
		near_enemy = boss;
		return true;
	}
	return false;
}


///	あたり判定
bool CMonsterActor::CollisionSphereToEnemy(const Transform& transform)
{
	if (CollisionSphereToSlimeEnemy(transform)) return true;
	if (CollisionSphereToWeaponEnemy(transform)) return true;
	if (CollisionSphereToMagicEnemy(transform)) return true;
	if (CollisionSphereToBoss(transform)) return true;
	
	return false;
}

bool CMonsterActor::CollisionAABBToEnemy(const Transform& transform)
{
	if (CollisionAABBToSlimeEnemy(transform)) return true;
	if (CollisionAABBToWeaponEnemy(transform)) return true;
	if (CollisionAABBToMagicEnemy(transform)) return true;
	if (CollisionAABBToBoss(transform)) return true;

	return false;
}

bool CMonsterActor::CollisionSphereToSlimeEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->SlimeGetSize(); i++)
	{
		auto enemy = enemy_manager->SlimeGetInstance(i);
		
		if (collision::SphereToSphere(transform.GetPos(), enemy->transform.GetPos(),
			transform.GetScale().x / 2, enemy->transform.GetScale().x / 4))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}
	return false;

}

bool CMonsterActor::CollisionAABBToSlimeEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->SlimeGetSize(); i++)
	{
		auto enemy = enemy_manager->SlimeGetInstance(i);

		if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
			enemy->transform.GetPos(),enemy->transform.GetScale()))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}
	return false;
}
bool CMonsterActor::CollisionSphereToWeaponEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->WeaponGetSize(); i++)
	{
		auto enemy = enemy_manager->WeaponGetInstance(i);

		if (collision::SphereToSphere(transform.GetPos(), enemy->transform.GetPos(),
			transform.GetScale().x / 2, enemy->transform.GetScale().x / 4))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}
	return false;
}

bool CMonsterActor::CollisionAABBToWeaponEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->WeaponGetSize(); i++)
	{
		auto enemy = enemy_manager->WeaponGetInstance(i);

		if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
			enemy->transform.GetPos(), enemy->transform.GetScale()))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}
	return false;
}
bool CMonsterActor::CollisionSphereToMagicEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->MagicGetSize(); i++)
	{
		auto enemy = enemy_manager->MagicGetInstance(i);

		if (collision::SphereToSphere(transform.GetPos(), enemy->transform.GetPos(),
			transform.GetScale().x / 2, enemy->transform.GetScale().x / 4))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}
	return false;
}

bool CMonsterActor::CollisionAABBToMagicEnemy(const Transform &transform)
{
	auto enemy_manager = task->GetComponent<CEnemyManager>(CGameObjectHousing::EnemyManagerName, 0);
	for (int i = 0; i < enemy_manager->MagicGetSize(); i++)
	{
		auto enemy = enemy_manager->MagicGetInstance(i);

		if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
			enemy->transform.GetPos(), enemy->transform.GetScale()))
		{
			enemy->Damage();
			AttackFinish();
			return true;
		}
	}

	return false;
}

bool CMonsterActor::CollisionSphereToBoss(const Transform &transform)
{
	auto boss_manager = task->GetComponent<CBossManager>(CGameObjectHousing::BossName, 0);
	if (boss_manager == nullptr) return false;

	auto boss = boss_manager->GetBoss();

	if (boss->IsDeath()) return false;

	if (collision::SphereToSphere(transform.GetPos(), boss->transform.GetPos(),
		transform.GetScale().x / 2, boss->transform.GetScale().x / 4))
	{
		boss->Damage(3);
		AttackFinish();
		return true;
	}
	return false;
}

bool CMonsterActor::CollisionAABBToBoss(const Transform &transform)
{
	auto boss_manager = task->GetComponent<CBossManager>(CGameObjectHousing::BossName, 0);
	if (boss_manager == nullptr) return false;

	auto boss = boss_manager->GetBoss();
	if (boss->IsDeath()) return false;

	if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
		boss->transform.GetPos(), boss->transform.GetScale() - Float3(200,0,0)))
	{
		boss->Damage(3);
		AttackFinish();
		return true;
	}
	return false;
}

///	静的なオブジェクトのあたり判定
bool CMonsterActor::CollisionStaticObject(const Transform& transform)
{
	for (auto& name : CGameObjectHousing::collision_table)
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
	}
	return false;
}

//	方向を切り替える
void CMonsterActor::ChangeDirection()
{
	if (original_pos.x > transform.GetPos().x)
	{
		direction = Direction::Right;
	}
	else
	{
		direction = Direction::Left;
	}
}

//	攻撃スタートタイミング
void CMonsterActor::AttackStartTiming()
{
	if (state != State::Live) return;
	if (!IsNearToEnemy()) return;
	if (transform.GetPos().x >= near_enemy->transform.GetPos().x) return;

	attack_count++;
	if (attack_count >= 30)
	{
		attack_count = 0;
		OnAttackInfo();
	}
}

//	位置を修正する
void CMonsterActor::PositionCorrection()
{
	if (state != State::Live) return;

	if (!utility::IsInclude<float>(transform.GetPos().x, original_pos.x, 100))
	{
		SetOriginalPos();
		ChangeDirection();
		OnAnimation(AnimationType::Move);
		state = State::Return;
	}
}

///	戻るアップデート処理
void CMonsterActor::ReturnUpdate()
{
	if (state != State::Return) return;

	Float3 velocity = utility::MoveBy(transform.GetPos(), original_pos, 7);
	transform.Translate(velocity);

	if (utility::IsInclude<float>(transform.GetPos().x, original_pos.x, 50))
	{
		OnAnimation(AnimationType::Stop);
		state = State::Live;
		direction = Direction::Right;
	}
}

void CMonsterActor::AlphaUpdate()
{
	if (hp > 255 / 10) return;
	if (alpha <= 0) return;
	
	alpha -= 9;
}

//	HPゲージ描画
void CMonsterActor::HpGageDraw()
{
	const float GageSize = 80.0f;
	Billboard(Float3(GageSize + 6.0f, 12.0f, 1.0f), transform.GetPos() + Float3(0, transform.GetScale().y/2, 0)).draw(Color(100,100,250,alpha));
	Billboard(Float3(GageSize * hp / max_hp, 7.0f, 1.0f), 
		transform.GetPos() + Float3(-GageSize / 2 + GageSize / 2 * hp / max_hp, transform.GetScale().y/2, 0)).draw(Color(255, 0, 0, alpha));

}

//	キャラクター描画
void CMonsterActor::CharaterDraw(Texture textire, Color color)
{
	if (direction == Direction::Left)
	{
		left_back.translate(transform.GetPos()).scale(
			transform.GetScale() / Size).draw(textire, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	}
	if (direction == Direction::Right)
	{
		right_back.translate(transform.GetPos()).scale(
			transform.GetScale() / Size).draw(textire, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	}
}

//	キャラクター描画
void CMonsterActor::CharaterDraw(Texture textire)
{
	if (direction == Direction::Left)
	{
		left.translate(transform.GetPos()).scale(
			transform.GetScale() / Size).draw(
			textire, *CResource::GetInstance().GetAlphaRenderer());
	}
	if (direction == Direction::Right)
	{
		right.translate(transform.GetPos()).scale(
			transform.GetScale() / Size).draw(
			textire, *CResource::GetInstance().GetAlphaRenderer());
	}
}

//	ガウス処理がかかったUI
void CMonsterActor::GaussUI()
{
	TextureAsset(CResource::GetInstance().GetMonsterAbsorptionUI(call->GetId())).resize(
		call->GetSize()*1.13f).drawAt(call->GetPos() + call->GetAbsorptionPos(), soul->GetColor());
}

//	UI描画
void CMonsterActor::UIDraw()
{
	if (soul->IsMaxGauge())
	{
		MaxGaugeDraw();
		GaussUI();
	}
	else
	{
		NormalGaugeDraw();
	}
	
	if (soul->GetState() == CSoul::State::Absorption)
	{
		GaussUI();
	}

	TextureAsset(CResource::GetInstance().GetMonsterUI(call->GetId())).resize(
		call->GetSize()).drawAt(call->GetPos(),Alpha(call->GetAlpha()));

	soul->Update();
	soul->Draw();

}

//	最大ゲージ描画
void CMonsterActor::MaxGaugeDraw()
{
	TextureAsset(CResource::GetInstance().GetUI(
		CResource::UIType::Monster_MaxCircle)).resize(call->GetSize()).drawAt(call->GetPos(), Alpha(call->GetAlpha()));
}

//	ゲージサークル描画
void CMonsterActor::GaugeCircleDraw()
{
	if (state == State::None) return;

	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Monster_RightCircle)).resize(
		call->GetSize()).rotate(gauge_angle.left).drawAt(call->GetPos(), Alpha(call->GetAlpha()));

}

//	通常ゲージ描画
void CMonsterActor::NormalGaugeDraw()
{
	if (soul->GetPoint() <= soul->GetMaxPoint() / 2)
	{
		gauge_angle.left = -Pi / 180.0 * 180.0 * soul->GetPoint() / (soul->GetMaxPoint() / 2);
	}
	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Monster_LeftCircleBack)).resize(
		call->GetSize()).drawAt(call->GetPos(), Alpha(call->GetAlpha()));
	
	GaugeCircleDraw();

	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Monster_RightCircleBack)).resize(
		call->GetSize()).drawAt(call->GetPos(), Alpha(call->GetAlpha()));

	if (soul->GetPoint() >= soul->GetMaxPoint() / 2)
	{
		gauge_angle.right = -Pi / 180.0 * 180.0 * soul->GetPoint() / (soul->GetMaxPoint() / 2);
		TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Monster_RightCircle)).resize(
			call->GetSize()).rotate(gauge_angle.right).drawAt(call->GetPos(), Alpha(call->GetAlpha()));
	}
}

//	召喚エフェクトアニメーション
void CMonsterActor::SummonsEffectAnimation()
{
	summons_anim->Update();
	SummonsEffectDraw();
}

//	召喚エフェクト
void CMonsterActor::SummonsEffectDraw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetSummonsEffect(call->GetId(),summons_anim->GetId()));
	Billboard(Float3(60, 60, 0.0001f), player->transform.GetPos() + Float3(0,100,0)).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
}