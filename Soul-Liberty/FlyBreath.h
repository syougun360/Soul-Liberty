/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossAttackState.h"
#include "Particle.h"

//	��s�u���X
class CFlyBreath :public CBossAttackState
{
public:
	CFlyBreath();

	void Start(std::shared_ptr<CBossActor> dragon);
	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();


private:
	//	��s�i�㏸�j
	void Fly();
	
	//	�h���S�������~
	void DragonDescent();

	//	�q�b�g��
	void OnHit();

	//	�`���[�W
	void Charge();

	//	�ړ�
	void Move();

	//	�p�[�e�B�N���A�b�v�f�[�g
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;
	Float3 player_pos;
	int count;
	float force;
};

