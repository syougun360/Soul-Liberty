/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "Actor.h"
#include "GraphicAnimation.h"

//	�{�X�̃A�N�^�[
class CBossActor:public CActor
{
public:
	CBossActor(std::shared_ptr<CTask> task, Transform transform, int hp);

	//	�_���[�W
	virtual void Damage(const int power) = 0;

	//	�U��
	virtual void Attack() {};

	//	�U�������ɖ߂�
	virtual void ReturnAttackPreparation();

	//	�v���C���[�Ƃ̂����蔻��
	bool CollisionToPlayer(const Transform& transform);

	//	�ÓI�I�u�W�F�N�g�Ƃ̂����蔻��
	bool CollisionStaticObject(const std::string& name, const Transform& transform);

	bool IsDeath()const{ return (state == State::Death || state == State::None); }

	//	�_���[�W��傫���A�N�V��������
	void PlayerDamageLargeAction();


protected:
	//	�U���I������
	virtual void AttackFinish(){}

	//	�v���C���[�̍U�������蔻��
	void CollisionToPlayerAttack();

	//	������������
	virtual void Hit();

	//	�A�j���[�V�����̎��
	enum class AnimationType
	{
		Stop,
		Move,
		Attack,
		Damage,
		Death,
	};
	const int max_hp;

	Direction direction;	//	����
	Color color;		//	�F
	int hp;				//	�̗�
	int power;			//	�U����
	int attack_count;	//	�U���J�E���g
	int hit_count;		//	�q�b�g�J�E���g
	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
	Mesh left;	//	���b�V����
	Mesh right;	//	���b�V���E

};

