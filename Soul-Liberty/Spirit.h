/**
*
*	@author	yamada masamitsu
*	@date	2014.11.14
*
*/

#pragma once
#include "MonsterActor.h"

class CMagicBullet;

class CSpirit :public CMonsterActor
{
public:
	CSpirit(std::shared_ptr<CTask> task);

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

	//	���@�ƃI�u�W�F�N�g�̂����蔻��
	void CollisionMagicToObject();

	//�@���@�e�̕`��
	void MagicBulletDraw();

	std::vector<std::unique_ptr<CMagicBullet>> magics;
};

