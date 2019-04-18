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
class CEnemyActor;

class CEnemyAttack:private Noncopyable
{
public:
	CEnemyAttack(const int power, const float jumpforce, const float mass, const float speed);

	virtual void Update(CEnemyActor *actor) = 0;
	virtual void Init(CEnemyActor *actor) = 0;
	virtual void Draw(){}

	enum class State
	{
		Move,
		Appearance,
		Attack,
	};

	const float GetJumpForce()const{ return jumpforce; };
	const int GetPower()const{ return power; };
	const float GetMass()const{ return mass; };
	const float GetSpeed()const{ return speed; };

	bool IsAttack()const{ return state == State::Attack; }
protected:
	const int power;
	const float jumpforce;
	const float mass;
	const float speed;
	float force;
	int count;
	State state;
	std::shared_ptr<CEnemyActor> enemy;

};

