/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include "MonsterActor.h"
class CWaterGun;

class CWaterShark :public CMonsterActor
{
public:
	CWaterShark(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:
	///	‡‘Ì‚µ‚½‚ÌUŒ‚
	void CombineAttack() ;

	//	UŒ‚‚Ìî•ñ
	void OnAttackInfo();
	void Attack();
	void AttackFinish();
	std::vector<std::unique_ptr<CWaterGun>> watar_gun;

};

