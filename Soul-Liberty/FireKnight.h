/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include "MonsterActor.h"

class CFireEffect;

class CFireKnight :public CMonsterActor
{
public:
	CFireKnight(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:

	///	‡‘Ì‚µ‚½‚ÌUŒ‚
	void CombineAttack();

	//	UŒ‚‚Ìî•ñ
	void OnAttackInfo();

	//	UŒ‚ˆ—
	void Attack();

	//	UŒ‚I—¹ˆ—
	void AttackFinish();

	//	“G‚É‹ß‚Ã‚­
	void ApproacheToEnemy();

	//	ƒGƒtƒFƒNƒg•`‰æ
	void EffectDraw();

	std::vector<std::unique_ptr<CFireEffect>> effects;

};

