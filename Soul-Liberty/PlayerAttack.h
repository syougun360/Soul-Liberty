/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/
#pragma once
#include "PlayerState.h"
#include "Transform.h"
#include <map>
#include "PlayerSpecialAttack.h"

struct AttackStep;

class CPlayerAttack:public CPlayerState
{
public:
	CPlayerAttack();

	void IniData(INIReader ini);
	void Start(std::shared_ptr<CPlayer> player);
	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();
	Transform transform;	///<	座標、サイズ、回転

	void OnHit(){ isCollision = false; }
	int GetPower()const;
	bool IsCollision()const{ return isCollision; }

	static int LimitCollisionCount(){ return limit_collision_count; };
	static int LimitTime(){ return limit_time; }
private:
	///	生成
	void Create();

	///	特殊攻撃生成
	void SpecialCreate();

	///	段階切替
	void ChangeStep();

	///	制限時間
	void LimitTimeUpdate();

	///	あたり判定の制限時間
	void CollisionLimitTime();

	///	存在する場合の処理
	void Exist();

	std::map<int, std::shared_ptr<AttackStep>> step_list;	///<	コンボリスト
	std::shared_ptr<AttackStep> step;	///<	コンボ処理
	std::unique_ptr<CPlayerSpecialAttack> special;	///<	特殊攻撃

	int now_step;			///<	現在の段階攻撃
	int collision_count;	///<	あたり判定のカウント
	int limit_count;	///<	制限時間のカウント
	bool isCollision;	///<	あたり判定がおこっているかどうか

	static int limit_collision_count;
	static int limit_time;
};

