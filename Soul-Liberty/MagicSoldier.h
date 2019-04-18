/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyActor.h"
#include "GraphicAnimation.h"

class CMagicSoldier :public CEnemyActor
{
public:

	CMagicSoldier(std::shared_ptr<CTask> task, Float3 pos,CResource::MonsterUIType soul_type);

	void Start();
	void Update();
	void Draw();
	void OnAttackFinish();

	//	静的オブジェクトと衝突したかどうか（List）
	bool IsCollisionStaticObjectList(const Transform &transform);


	static int MaxHp(){ return max_hp; }
	static int AttackPower(){ return attack_power; };
	static int SoulPoint(){ return soul_point; };
	static float JumpPower(){ return jump_power; };
	static float Mass(){ return mass; };
	static float Speed(){ return speed; };
private:
	enum class AnimationType
	{
		Move,
		Attack,
	};
	void IniDataList();

	//	静的オブジェクトと衝突したかどうか
	bool IsCollisionStaticObject(const std::string &name, const Transform &transform);

	//	方向を変更
	void ChangeDirection();

	//	攻撃
	void Attack();

	//	攻撃初期化
	void InitAttack();

	static int max_hp;
	static int attack_power;
	static int soul_point;
	static float jump_power;
	static float mass;
	static float speed;

	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
};

