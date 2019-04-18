/**
*
*	@author	yamada masamitsu
*	@date	2014.11.17
*
*/
#pragma once
#include "EnemyAttack.h"
#include "Particle.h"

class CMagicAttack :public CEnemyAttack
{
public:
	CMagicAttack(const int power, const float jumpforce, const float mass, const float speed);
	
	void Update(CEnemyActor *enemy);
	void Init(CEnemyActor *enemy);
	void Draw();

private:
	//	�����蔻��A�b�v�f�[�g
	void CollisionUpdate(CEnemyActor *enemy);

	//	���E�̋���
	void LimitDistance(CEnemyActor *enemy);

	//	�I������
	void Finish(CEnemyActor *enemy);

	//	�U������
	void Attack(CEnemyActor *enemy);

	//	�ړ�����
	void Move(CEnemyActor *enemy);

	//	����
	void Appearance(CEnemyActor *enemy);

	//	�`���[�W
	void Charge(CEnemyActor *enemy);

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;

	Float3 destination;
};

