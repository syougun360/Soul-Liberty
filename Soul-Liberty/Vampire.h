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
	///	���̂������̍U��
	void CombineAttack();

	//	�U�����̏��
	void OnAttackInfo();

	//	�U������
	void AttackPreparation();

	//	�U������
	void Attack();

	//	�U���I������
	void AttackFinish();

	//	�����蔻��
	void CollisionSwordToObject();

	//	���̕`��
	void SwordDraw();

	std::vector<std::unique_ptr<CDarknessSword>> swords;
};

