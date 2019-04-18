/**
*
*	@author	yamada masamitsu
*	@date	2014.11.14
*
*/

#pragma once
#include "MonsterActor.h"
class CDarknessSword;

class CVampire :public CMonsterActor
{
public:
	CVampire(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:
	///	‡‘Ì‚µ‚½‚ÌUŒ‚
	void CombineAttack();

	//	UŒ‚‚Ìî•ñ
	void OnAttackInfo();

	//	UŒ‚€”õ
	void AttackPreparation();

	//	UŒ‚ˆ—
	void Attack();

	//	UŒ‚I—¹ˆ—
	void AttackFinish();

	//	‚ ‚½‚è”»’è
	void CollisionSwordToObject();

	//	Œ•‚Ì•`‰æ
	void SwordDraw();

	std::vector<std::unique_ptr<CDarknessSword>> swords;
};

