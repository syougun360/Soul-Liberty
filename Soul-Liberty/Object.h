
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>
#include "Noncopyable.h"
#include "Transform.h"


class Object :private Noncopyable
{
public:
	enum class State;
	Object() :transform(Float3(0, 0, 0), Float3(0, 0, 0), Float3(0, 0, 0)){}
	Object(Transform transform,State state) :
		transform(transform), state(state){}
	virtual ~Object() = default;

	// Update�̑O�ɌĂ΂�����
	virtual void Start(){};

	// �A�b�v�f�[�g
	virtual void Update(){};

	//�@�`��
	virtual void Draw() {};

	//�@�`��
	virtual void Finish() {};


	enum class State
	{
		None,		//�@���݂��Ȃ�
		Start,		//	�X�^�[�g
		Live,		//�@���݂���
		Appearance,	//	�o��
		Move,		//�@�ړ�
		AttackPreparation,	//	�U������
		Attack,		//�@�U������
		Hit,		//�@�q�b�g
		Death,		//	���S
		Return,		//	�߂�
		BossInFiled,	//	�{�X�̃t�B�[���h�ɓ�����
		Call,	//	����
	};

	///	����
	enum Direction
	{
		Left = -1,	///	������
		Right = 1,	///	�E����
	};

	State GetState()const{ return state; }

	Transform transform;

protected:
	State state;	///<	���
	
};