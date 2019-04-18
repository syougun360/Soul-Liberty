
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/
#pragma once
#include "BossAttackState.h"
#include "Particle.h"

//	���i�A���j
class CFlame:public CBossAttackState
{
public:
	CFlame(Float3 pos, Float3 player_pos);

	void Update();
	void Draw();

	//	�q�b�g��
	void OnHit();
	
private:
	//	�ړ�
	void Move();

	//	�p�[�e�B�N���A�b�v�f�[�g
	void ParticleUpdate();

	std::unique_ptr<CParticleSystem> particles;
};

//	���Ǘ�
class CFlameManager :public CBossAttackState
{
public:
	CFlameManager();

	void Create(Float3 pos, Float3 player_pos);
	void Update();
	void Draw();

private:
	//	�I������
	void Finish();

	//	�����蔻��A�b�v�f�[�g
	void CollisionUpdate();

	//	�ÓI�I�u�W�F�N�g�����蔻��
	void CollisionStaticObject(std::unique_ptr<CFlame>& flame);
	
	//	�v���C���[�����蔻��
	void CollisionPlayer(std::unique_ptr<CFlame>& flame);

	int count;
	std::vector<std::unique_ptr<CFlame>> flames;

};