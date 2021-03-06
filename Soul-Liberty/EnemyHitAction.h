/**
*
*	@author	yamada masamitsu
*	@date	2014.11.06
*
*/
#pragma once
#include <memory>
#include <siv3D.hpp>
#include "Noncopyable.h"

class CPlayer;
class CEnemyActor;

class CEnemyHitAction :private Noncopyable
{
public:
	CEnemyHitAction(const float mass, const float force, const float knock_back);

	void Init();
	void Update(CEnemyActor *actor);

	//	ヒット時処理
	void OnHit(std::shared_ptr<CPlayer> player);

	//	死亡時の移動速度量
	void OnDeathVelocity();

	Float3 GetVelocity()const{ return velocity; }

	const float GetForce()const{ return force; }
	const float GetMass()const{ return mass; }
	const float GetKnockBack()const{ return knock_back; }

private:
	Float3 velocity;
	const float mass;
	const float force;
	const float knock_back;

};

