
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <map>
#include "Actor.h"
#include "GraphicAnimation.h"

class CPlayerMove;
class CPlayerCamera;
class CPlayerJump;
class CPlayerAttack;
class CPlayerAvoidance;
class CPlayerDamage;
class CPlayerGravity;
class CPlayerHpGauge;
class CCombine;
struct MagicBackGraphic;

///	プレイヤー本体
class CPlayer:public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task,Float3 pos);

	enum class AnimationType
	{
		Standing,
		Move,
		JumpStep1,
		JumpStep2,
		Attack_1,
		Attack_2,
		Attack_3,
		Attack_4,
		Damage,
		Death,
		Call,
		Avoidance,
	};

	void Start();
	void Update();
	void Draw();

	void DirectionRight();
	void DirectionLeft();

	///	次のステージに行くためのイベント
	void NextStageEventUpdate();

	///	アニメーション設定
	void OnAnimation(AnimationType type);

	///	味方モンスターを召喚
	void MonsterCall();

	///	ため攻撃移動処理
	void OnSpecialAttackMove();

	//	攻撃のあたり判定をなくす
	void AttackNonCollision();

	///	合体処理
	void Combine();

	///	速度減少
	void SpeedDown();

	///	攻撃が当たった処理
	void AttackHit();

	///	ボスのFieldに入る処理
	void BossInField();

	//	死亡処理
	void Death();

	///	ダメージ処理
	void Damage(const int power);

	//	ダメージを大きくアクションする
	void DamageLargeAction();

	//	立ちモーションのアニメーションに設定
	void SetStandingAnimation();

	///	フェンスの衝突処理
	void FenceCollision();

	Direction GetDirection()const{ return direction; }

	Float3 GetCameraPos()const;

	///	攻撃のあたり判定座標
	Float3 GetAttackCollisionPos();

	///	移動量を取得
	Float3 GetVelocity()const;

	///	攻撃のあたり判定範囲
	float GetAttackCollisionRadius();

	///	攻撃力
	int GetAttacPower()const;

	///	攻撃してるかどうか
	bool IsNowAttack()const;

	///	前に移動できるかどうか
	bool IsForwardMove()const;

	///	回避しているかどうか
	bool IsNowAvoid()const;

	///	重力
	bool IsGravity();

	///	ジャンプの衝突処理
	bool IsJumpCollision();

	///	横の衝突処理
	bool IsFrontCollision();
	bool IsBackCollision();

	///	ジャンプしているかどうか
	bool IsNowJump()const;

	///	ダメージを受けているかどうか
	bool IsNowDamage()const;

	///	大ダメージを受けているかどうか
	bool IsLargeAction()const;

	///	移動しているかどうか
	bool IsNowMove()const;

	///	現在、攻撃あたり判定があるかどうか
	bool IsNowCollisionAttack()const;

	bool IsBossFiledNowEvent()const{ return (state == State::BossInFiled); }

	///	召喚アニメーションしているかどうか
	bool IsSummonsCallAnimation()const{ return (state == State::Call); }

	static const float Mass;
private:
	//	iniデータのList
	void IniDataList();

	//	Animationを登録
	void SignUpAnimation();
	
	///	移動処理
	void Move();

	///	画像を描画
	void GraphicDraw();

	//	ボスフィールドのイベント
	void BossFieldEvent();

	//	移動できる範囲
	void MoveRange();
	
	//	ドアの当たった時
	void OnHitDoor();

	std::unique_ptr<CPlayerMove> move;		///<	移動処理
	std::unique_ptr<CPlayerCamera> camera;	///<	カメラ処理
	std::unique_ptr<CPlayerJump> jump;		///<	ジャンプ処理
	std::unique_ptr<CPlayerAttack> attack;	///<	攻撃処理
	std::unique_ptr<CPlayerGravity> gravity;	///<	重力処理
	std::unique_ptr<CPlayerAvoidance> avoidance;	///<	回避処理
	std::unique_ptr<CPlayerDamage> damage;			///<	ダメージ処理
	std::unique_ptr<CPlayerHpGauge> hp_gauge;		///<	体力ゲージ
	std::unique_ptr<CCombine> combine;				///<	合体

	std::shared_ptr<CGraphicAnimation<AnimationType>> animation;
	Mesh left;
	Mesh right;
	Direction direction;
};

