/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyAttack.h"
#include "FootSmoke.h"

class CWeaponAttack :public CEnemyAttack
{
public:
	CWeaponAttack(const int power, const float jumpforce, const float mass, const float speed);
	
	void Update(CEnemyActor *enemy);
	void Init(CEnemyActor *enemy);

private:
	void Appearance(CEnemyActor *enemy);
	void Move(CEnemyActor *enemy);
	Float3 velocity;
	std::vector<std::unique_ptr<CFootSmoke>> smokes;
};

