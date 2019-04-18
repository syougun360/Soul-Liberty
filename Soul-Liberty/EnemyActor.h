/**
*
*	@author	yamada masamitsu
*	@date	2014.11.00
*
*/
#pragma once
#include "Actor.h"
#include "Resource.h"

class CEnemyHitAction;
class CEnemyAttack;
class CPlayer;

class CEnemyActor:public CActor
{
public:
	CEnemyActor(std::shared_ptr<CTask> task, Transform transform,CResource::MonsterUIType soul_type);

	void Init(int hp, int soul_point, CEnemyHitAction hit_action, std::shared_ptr<CEnemyAttack> attack);
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	
	int GetDirection()const{ return direction; }
	Float3 GetPlayerPos()const;

	///	��Ұ�ޏ���
	virtual void Damage();

	///	�v���C���[�ւ̃_���[�W����
	void DamageToThePlayer();

	
protected:

	virtual void InitAttack() = 0;

	///	���S����
	virtual void Death();

	///	�v���C���[�U�������蔻��
	virtual void CollisionPlayerAttack();

	///	�̗̓Q�[�W�`��
	virtual void HpGageDraw();

	///	�q�b�g����
	virtual void Hit();

	///	�v���C���[�̑̂Ɠ���������
	bool CollisionPlayerBody();

	///	���̂����蔻��
	bool IsCollisionFloor();

	///	�U����Ԃɂ���
	void ChangeAttackState();

	///	�I�u�W�F�N�g�f�[�^���擾
	void GetComponentObject();
	
	///	�����������̈ړ��ʂƃm�b�N�o�b�N��
	void OnHit();

	///	���]����
	void TurnUpdate();

	std::shared_ptr<CPlayer> player;
	std::shared_ptr<CEnemyAttack> attack;

	int soul_point;		///<	���|�C���g
	int direction;		///<	����
	Mesh left;
	Mesh right;
	Palette hit_color;

private:

	void PushBack();
	CResource::MonsterUIType soul_type;
	std::unique_ptr<CEnemyHitAction> hit_action;

	int max_hp;	///<	�ő�̗�
	int hp;				///<	�̗�
	int hit_count;

};

