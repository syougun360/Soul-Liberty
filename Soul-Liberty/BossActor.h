/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "Actor.h"
#include "GraphicAnimation.h"

//	ボスのアクター
class CBossActor:public CActor
{
public:
	CBossActor(std::shared_ptr<CTask> task, Transform transform, int hp);

	//	ダメージ
	virtual void Damage(const int power) = 0;

	//	攻撃
	virtual void Attack() {};

	//	攻撃準備に戻す
	virtual void ReturnAttackPreparation();

	//	プレイヤーとのあたり判定
	bool CollisionToPlayer(const Transform& transform);

	//	静的オブジェクトとのあたり判定
	bool CollisionStaticObject(const std::string& name, const Transform& transform);

	bool IsDeath()const{ return (state == State::Death || state == State::None); }

	//	ダメージを大きくアクションする
	void PlayerDamageLargeAction();


protected:
	//	攻撃終了処理
	virtual void AttackFinish(){}

	//	プレイヤーの攻撃あたり判定
	void CollisionToPlayerAttack();

	//	当たった処理
	virtual void Hit();

	//	アニメーションの種類
	enum class AnimationType
	{
		Stop,
		Move,
		Attack,
		Damage,
		Death,
	};
	const int max_hp;

	Direction direction;	//	方向
	Color color;		//	色
	int hp;				//	体力
	int power;			//	攻撃力
	int attack_count;	//	攻撃カウント
	int hit_count;		//	ヒットカウント
	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
	Mesh left;	//	メッシュ左
	Mesh right;	//	メッシュ右

};

