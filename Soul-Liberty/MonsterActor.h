/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include <map>
#include "Actor.h"
#include "GraphicAnimation.h"
#include "Soul.h"
#include "MonsterCall.h"
#include "MonsterUI.h"

class CPlayer;
class CEnemyActor;

struct MonsterSoul
{
	MonsterSoul(int point, Palette color) :
	point(point), color(color){}
	int point;
	Palette color;
};

///	Monster
class CMonsterActor :public CActor
{
public:
	CMonsterActor(std::shared_ptr<CTask> task,MonsterUI ui, std::string name, int call_alpha = 255);
	CMonsterActor();
	virtual void Init();
	virtual void Start(std::shared_ptr<CPlayer> player);

	void Init(int hp, MonsterSoul soul);

	///	���̂������̍U��
	virtual void CombineAttack() = 0;

	//	UI�`��
	void UIDraw();

	//	�������Ƃ��̐���
	void CreateRelease(Float3 create_pos, Float2 monster_ui_pos, const int point);
	
	//	���̎�����
	void OnCombine();

	//	���̂̃A�b�v�f�[�g
	void CombineUpdate();

	//	�Ăяo���\�ɂ���
	void EnableToCall();

	///	�O��̍����p�������邽�߂̐ݒ�
	void ContinuationSoul(double point);
	
	//	�����ō����z��
	void AutoSoulAbsorption();

	//	�����G�t�F�N�g�A�j���[�V����
	void SummonsEffectAnimation();

	//	�����A�j���[�V������ݒ�
	void OnAnimationSummons();

	//	���̏�����
	void OnInitSoul();

	bool IsExistence();
	bool IsCall();
	bool IsCombine()const{ return isCombine; }
	bool IsCombineable()const;
	bool IsCombineLittle()const;
	double GetSoulPoint()const;
	Palette GetSoulColor()const;
	Float2 GetCallUIPos()const;
	std::string GetName()const{return name; }
	static const float Size;

protected:

	enum class AnimationType
	{
		Move,
		Stop,
		Attack,
		Hit
	};

	//	�U�����̏��
	virtual void OnAttackInfo() = 0;

	///	�U������
	virtual void Attack() = 0;

	///	�U���I������
	virtual void AttackFinish() = 0;

	//	�o�ꏈ��
	virtual void Appearance();

	///	���S����
	virtual void Death();

	///	�_���[�W����
	virtual void Damage();

	///	�ړ�����
	virtual void Move();

	///	���̈ʒu��ݒ�
	void SetOriginalPos();

	///	�����蔻��
	bool CollisionSphereToEnemy(const Transform& transform);
	bool CollisionAABBToEnemy(const Transform& transform);

	//	�����G�t�F�N�g
	void SummonsEffectDraw();

	//	�ʒu���C������
	void PositionCorrection();

	///	�U���X�^�[�g����^�C�~���O
	void AttackStartTiming();

	///	�̗̓Q�[�W�`��
	void HpGageDraw();

	///	��������
	void LimitTime();

	///	Character�̂ݕ`��
	void CharaterDraw(Texture textire, Color color);
	void CharaterDraw(Texture textire);

	///	�߂�A�b�v�f�[�g����
	void ReturnUpdate();

	void OnAnimation(const AnimationType type);

	///	�ÓI�ȃI�u�W�F�N�g�̂����蔻��
	bool CollisionStaticObject(const Transform& transform);

	//	���̍U���\���ǂ���
	bool CanCombineAttack()const;

	bool IsNearToEnemy();

	int max_hp;	///<	�ő�̗�
	int hp;		///<	�̗�
	int alpha;	///<	�A���t�@�l
	int attack_count;	//	�U������J�E���g
	int call_point;	///<	�Ăׂ�|�C���g
	bool isCombine;	//	���̂��Ă��邩�ǂ���

	std::shared_ptr<CActor> near_enemy;
	Float3 original_pos;
	Direction direction;	///<	����
	std::shared_ptr<CPlayer> player;

	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
	std::unique_ptr<CGraphicAnimation<CResource::MonsterUIType>> summons_anim;

	std::unique_ptr<CSoul> soul;
	std::unique_ptr<CMonsterCall> call;

private:
	///	�ʏ�Q�[�W�̕`��
	void NormalGaugeDraw();

	///	�ő�Q�[�W�̕`��
	void MaxGaugeDraw();

	///	Gauss����������UI
	void GaussUI();

	///	�A���t�@�l����
	void AlphaUpdate();

	///	������ύX����
	void ChangeDirection();

	//	�Q�[�W�T�[�N���`��
	void GaugeCircleDraw();

	bool IsNearToWeaponEnemy();
	bool IsNearToMagicEnemy();
	bool IsNearToSlimeEnemy();
	bool IsNearToBoss();

	//	�G�Ƃ̏Փ˔���
	bool CollisionSphereToSlimeEnemy(const Transform &transform);
	bool CollisionAABBToSlimeEnemy(const Transform &transform);
	bool CollisionSphereToWeaponEnemy(const Transform &transform);
	bool CollisionAABBToWeaponEnemy(const Transform &transform);
	bool CollisionSphereToMagicEnemy(const Transform &transform);
	bool CollisionAABBToMagicEnemy(const Transform &transform);
	bool CollisionSphereToBoss(const Transform &transform);
	bool CollisionAABBToBoss(const Transform &transform);

	float acceleration;
	std::string name;
	Point ui_pos;
	Mesh left;
	Mesh right;
	Mesh left_back;
	Mesh right_back;
	struct UI_CircleAngle
	{
		UI_CircleAngle() :left(0), right(0){}
		double left, right;
	};
	UI_CircleAngle gauge_angle;
};
