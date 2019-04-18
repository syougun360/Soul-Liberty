/**
*
*	@author	yamada masamitsu
*	@date	2014.11.00
*
*/
#pragma once
#include "Actor.h"
#include "Resource.h"

class CEnemyHitAction;
class CEnemyAttack;
class CPlayer;

class CEnemyActor:public CActor
{
public:
	CEnemyActor(std::shared_ptr<CTask> task, Transform transform,CResource::MonsterUIType soul_type);

	void Init(int hp, int soul_point, CEnemyHitAction hit_action, std::shared_ptr<CEnemyAttack> attack);
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	
	int GetDirection()const{ return direction; }
	Float3 GetPlayerPos()const;

	///	ﾀﾞﾒｰｼﾞ処理
	virtual void Damage();

	///	プレイヤーへのダメージ処理
	void DamageToThePlayer();

	
protected:

	virtual void InitAttack() = 0;

	///	死亡処理
	virtual void Death();

	///	プレイヤー攻撃あたり判定
	virtual void CollisionPlayerAttack();

	///	体力ゲージ描画
	virtual void HpGageDraw();

	///	ヒット処理
	virtual void Hit();

	///	プレイヤーの体と当った処理
	bool CollisionPlayerBody();

	///	床のあたり判定
	bool IsCollisionFloor();

	///	攻撃状態にする
	void ChangeAttackState();

	///	オブジェクトデータを取得
	void GetComponentObject();
	
	///	当たった時の移動量とノックバック量
	void OnHit();

	///	反転処理
	void TurnUpdate();

	std::shared_ptr<CPlayer> player;
	std::shared_ptr<CEnemyAttack> attack;

	int soul_point;		///<	魂ポイント
	int direction;		///<	方向
	Mesh left;
	Mesh right;
	Palette hit_color;

private:

	void PushBack();
	CResource::MonsterUIType soul_type;
	std::unique_ptr<CEnemyHitAction> hit_action;

	int max_hp;	///<	最大体力
	int hp;				///<	体力
	int hit_count;

};

