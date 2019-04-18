/**
*
*	@author	yamada masamitsu
*	@date	2014.12.01
*
*/

#pragma once
#include "BossAttackState.h"
#include "Particle.h"

class CMagicSoul :public CBossAttackState
{
public:
	CMagicSoul();

	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();


private:
	//	�q�b�g������
	void OnHit();

	//	�`���[�W����
	void Charge();

	//	�ړ�����
	void Move();

	//	�p�[�e�B�N���̃A�b�v�f�[�g
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
	std::unique_ptr<CParticleSystem> charge;
	int count;
};

