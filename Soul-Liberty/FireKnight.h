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

	///	���̂������̍U��
	void CombineAttack();

	//	�U�����̏��
	void OnAttackInfo();

	//	�U������
	void Attack();

	//	�U���I������
	void AttackFinish();

	//	�G�ɋ߂Â�
	void ApproacheToEnemy();

	//	�G�t�F�N�g�`��
	void EffectDraw();

	std::vector<std::unique_ptr<CFireEffect>> effects;

};

