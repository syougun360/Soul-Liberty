#include "PlayerSpecialAttack.h"
#include "CharacterController.h"
#include "PlayerAttack.h"
#include "Resource.h"
CPlayerSpecialAttack::CPlayerSpecialAttack() :
special_count(0),
state(State::None)
{
}
void CPlayerSpecialAttack::Start(std::shared_ptr<CPlayer> player)
{
	this->player = player;
}

void CPlayerSpecialAttack::Create()
{
	if (state != State::None) return;

	special_count = 0;
	state = State::Live;
	player->OnAnimation(CPlayer::AnimationType::Attack_4);
	CResource::GetInstance().PlaySE(CResource::SE::PlayerSpecialAttack);

}

void CPlayerSpecialAttack::Update(CPlayerAttack *attack)
{
	if (state != State::Live) return;

	const int SpecialInvocationCount = 30;
	special_count++;
	if (special_count == SpecialInvocationCount-5)
	{
		player->OnSpecialAttackMove();
		attack->OnCollisionStart();
	}
	if (special_count >= SpecialInvocationCount)
	{
		state = State::None;
	}
}