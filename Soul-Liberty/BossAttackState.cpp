#include "BossAttackState.h"
#include "Utility.h"
#include "GameObjectHousing.h"
#include "BossActor.h"

CBossAttackState::CBossAttackState(Float3 pos, Float3 scale, Float3 player_pos, int power) :
transform(pos, scale / 2, Float3(0, 0, PiF / 180 * 10)),
state(State::Live),
isDelete(false),
graph(utility::CreateMirroredBox(scale, -1)),
velocity(utility::MoveBy(transform.GetPos(), player_pos, 10)),
power(power)
{
}

CBossAttackState::CBossAttackState(Float3 scale, int power,float angleZ) :
transform(Float3(0, 0, 0), scale / 2, Float3(0, 0, PiF / 180 * angleZ)),
graph(utility::CreateMirroredBox(scale, -1)),
state(State::Create),
isDelete(false),
power(power)
{
}


CBossAttackState::CBossAttackState(Float3 scale, int power) :
transform(Float3(0, 0, 0), scale / 2, Float3(0, 0, 0)),
graph(utility::CreateMirroredBox(scale, -1)),
state(State::Create),
isDelete(false),
power(power)
{
}


void CBossAttackState::Start(std::shared_ptr<CBossActor> actor)
{
	this->actor = actor;
}



//	�ÓI�I�u�W�F�N�g�̂����蔻��
void CBossAttackState::CollisionStaticObject()
{
	for (auto& name : CGameObjectHousing::collision_table)
	{
		if (actor->CollisionStaticObject(name, transform))
		{
			OnHit();
			return;
		}
	}
}

//	�v���C���[�Ƃ̂����蔻��
void CBossAttackState::CollisionPlayer()
{
	if (actor->CollisionToPlayer(transform))
	{
		OnHit();
	}
}


//	���������u��
void CBossAttackState::OnHit()
{
	state = State::Effect;
}
