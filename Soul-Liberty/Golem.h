/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include "MonsterActor.h"
class CTree;

class CGolem :public CMonsterActor
{
public:
	CGolem(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:
	///	‡‘Ì‚µ‚½‚ÌUŒ‚
	void CombineAttack();

	void Attack();
	void AttackPreparation();
	void OnAttackInfo();
	void AttackFinish();
	void TreesUpdate();
	void AttackStart();
	std::vector<std::unique_ptr<CTree>> trees;
	Float3 velocity;
	int count;
};

