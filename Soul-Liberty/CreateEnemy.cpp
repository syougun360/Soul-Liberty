#include "CreateEnemy.h"
#include "Devil.h"

CCreateEnemy::CCreateEnemy():
CBossAttackState(Float3(0, 0, 0), 0),
count(0)
{
}

//	�G�𐶐�
void CCreateEnemy::Create(Float3 pos, Float3 player_pos)
{
	if (state != State::Create) return;

	pos = Float3(0, 0, 0);
	player_pos = Float3(0, 0, 0);

	std::dynamic_pointer_cast<CDevil>(actor)->CreateEnemy();

	state = State::Live;

}

//	�A�b�v�f�[�g
void CCreateEnemy::Update()
{
	if (state != State::Live) return;

	count++;
	if (count >= 60)
	{
		state = State::Create;
		count = 0;
		actor->ReturnAttackPreparation();
	}
}

//	�`��
void CCreateEnemy::Draw()
{
	
}