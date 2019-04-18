/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossActor.h"

class CBossAttackState;
class CKing;

//	�h���S��
class CDragon:public CBossActor
{
public:
	CDragon(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();

private:

	//	�U�����
	enum class AttackType
	{
		Flame,
		Breath,
		FlyBreath,
		MaxType,
	};

	//	Character�`��
	void CharacterDraw();

	//	�̗͏���
	void HitPoint(const int power);

	//	�U������
	void AttackPreparation();

	//	�U���I������
	void AttackFinish();

	//	�U����ނ�ݒ�
	void SetAttackType();

	//	�_���[�W����
	void Damage(const int power);

	//	�U��
	void Attack();

	//	���S����
	void Death();

	std::map<AttackType, std::shared_ptr<CBossAttackState>> attack_table;
	std::shared_ptr<CBossAttackState> attack;
	AttackType attack_type;
	std::unique_ptr<CKing> king;
	int death_count;
};

