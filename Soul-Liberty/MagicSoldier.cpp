#include "MagicSoldier.h"
#include "Resource.h"
#include "Player.h"
#include "GameObjectHousing.h"
#include "EnemyHitAction.h"
#include "MagicAttack.h"
#include "Collision.h"
#include "Utility.h"


int CMagicSoldier::max_hp;
int CMagicSoldier::attack_power;
int CMagicSoldier::soul_point;
float CMagicSoldier::jump_power;
float CMagicSoldier::mass;
float CMagicSoldier::speed;


CMagicSoldier::CMagicSoldier(std::shared_ptr<CTask> task, Float3 pos,CResource::MonsterUIType soul_type) :
CEnemyActor(task, Transform(pos + Float3(0, 100.0f / 4.0f, 0),
Float3(100.0f, 100.0f, 0.0001f), Float3(0, 0, 0)),soul_type),
animation(std::make_unique<CGraphicAnimation<AnimationType>>())
{
	animation->Append(AnimationType::Move, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(1, 1, 0));

	IniDataList();
	Init(max_hp, soul_point ,
		CEnemyHitAction(mass, jump_power / 4, speed),
		std::make_shared<CMagicAttack>(attack_power, jump_power, mass, speed));
}

//	ini�f�[�^List
void CMagicSoldier::IniDataList()
{
	max_hp = ini.get<int>(L"MagicSoldier.max_hp");
	attack_power = ini.get<int>(L"MagicSoldier.attack_power");
	soul_point = ini.get<int>(L"MagicSoldier.soul_point");
	jump_power = ini.get<float>(L"MagicSoldier.jump_power");
	mass = ini.get<float>(L"MagicSoldier.mass");
	speed = ini.get<float>(L"MagicSoldier.speed");
}

//	Update�̑O�Ɏ��s����鏈��
void CMagicSoldier::Start()
{
	GetComponentObject();	
	animation->OnAnimation(AnimationType::Move);
}

//	�ÓI�ȃI�u�W�F�N�g�Ɠ����������ǂ����̎擾
//	�����蔻��̃��X�g
bool CMagicSoldier::IsCollisionStaticObjectList(const Transform &transform)
{
	if (IsCollisionStaticObject(CGameObjectHousing::FloorName, transform)) return true;
	if (IsCollisionStaticObject(CGameObjectHousing::FenceName, transform)) return true;
	if (IsCollisionStaticObject(CGameObjectHousing::TombstoneName, transform)) return true;
	return false;
}


//	�ÓI�ȃI�u�W�F�N�g�Ɠ����������ǂ����̎擾
bool CMagicSoldier::IsCollisionStaticObject(const std::string &name,const Transform &transform)
{
	for (auto& it : task->GetActor(name))
	{
		if (collision::AABBToAABB(transform.GetPos(),transform.GetScale(),
			it->transform.GetPos(),it->transform.GetScale()))
		{
			return true;
		}
	}
	return false;
}

//	�U���̏�����
void CMagicSoldier::InitAttack()
{
	attack->Init(this);
	animation->OnAnimation(AnimationType::Attack);

}

//	�U������
void CMagicSoldier::Attack()
{
	if (state != State::Attack) return;

	attack->Update(this);
	
}

//	�U���I�����̏���
void CMagicSoldier::OnAttackFinish()
{
	state = State::Live;
}

//	������؂�ւ���
void CMagicSoldier::ChangeDirection()
{
	if (utility::IsInclude<float>(transform.GetPos().x, player->transform.GetPos().x, 50)) return;
	if (transform.GetPos().x < player->transform.GetPos().x)
	{
		direction = Direction::Right;
	}
	if (transform.GetPos().x > player->transform.GetPos().x)
	{
		direction = Direction::Left;
	}
}

//	�A�b�v�f�[�g
void CMagicSoldier::Update()
{
	ChangeAttackState();
	CollisionPlayerAttack();
	ChangeDirection();
	Hit();
	Attack();
	Death();
	TurnUpdate();
	animation->Update();

}

//	�`��
void CMagicSoldier::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetMagicEnemy(animation->GetId()));

	if (direction == Direction::Left)
		left.translate(transform.GetPos()).draw(texture, hit_color, *CResource::GetInstance().GetAlphaRenderer());

	if (direction == Direction::Right)
		right.translate(transform.GetPos()).draw(texture, hit_color, *CResource::GetInstance().GetAlphaRenderer());

	HpGageDraw();
	attack->Draw();

}