/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "Transform.h"
class CBossActor;

//	�{�X�̍U����ԁi���N���X�j
class CBossAttackState
{
public:
	CBossAttackState(Float3 pos, Float3 scale, Float3 player_pos, int power);
	CBossAttackState(Float3 scale, int power);
	CBossAttackState(Float3 scale, int power, float angleZ);

	virtual void Start(std::shared_ptr<CBossActor> actor);
	virtual void Create(Float3 pos, Float3 player_pos) { pos = Float3(0, 0, 0); player_pos = Float3(0, 0, 0); }
	virtual void Update() = 0;
	virtual void Draw() = 0;

	enum class State
	{
		None,
		Create,
		Charge,
		Live,
		Effect,
	};

	int GetPower()const{ return power; }
	bool IsDelete()const{ return isDelete; }
	bool IsCollision()const{ return (state == State::Live); }
	Transform transform;

protected:
	//	�q�b�g������
	virtual void OnHit();

	//	�v���C���[�Ƃ̂����蔻��
	virtual void CollisionPlayer();

	//	�ÓI�I�u�W�F�N�g�Ƃ̂����蔻��
	virtual void CollisionStaticObject();

	Mesh graph;
	Float3 velocity;
	State state;
	int power;
	bool isDelete;
	std::shared_ptr<CBossActor> actor;
};

