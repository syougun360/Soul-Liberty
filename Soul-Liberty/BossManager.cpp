#include "BossManager.h"
#include "BossActor.h"
#include "Devil.h"
#include "Dragon.h"
#include "King.h"

CBossManager::CBossManager(std::shared_ptr<CTask> task, Float3 pos) :
CActor(task),
type(Type::Devil)
{
	boss_table.insert(std::make_pair(Type::Devil, std::make_shared<CDevil>(task, pos)));
	boss_table.insert(std::make_pair(Type::Dragon, std::make_shared<CDragon>(task, pos)));
	boss_table.insert(std::make_pair(Type::King, std::make_shared<CKing>(task, pos)));

	boss = boss_table.find(Type::Devil)->second;
}

//	�{�X�A�N�^�[���擾
std::shared_ptr<CBossActor> CBossManager::GetBoss()const
{
	return boss;
}

//	���S�������ǂ������擾
bool CBossManager::IsDeath()const
{
	return (boss->GetState() == State::None);
}

//	�h���S���ɐ؂�ւ���
void CBossManager::ChangeDragon()
{
	if (type != Type::King) return;
	if (boss->GetState() != State::Death) return;
	type = Type::Dragon;
	boss = boss_table.find(type)->second;
}

//	���l�ɐ؂�ւ���
void CBossManager::ChangeLyingKing()
{
	if (type != Type::Devil) return;
	if (boss->GetState() != State::Death) return;
	type = Type::King;
	boss = boss_table.find(type)->second;
}

//	�A�b�v�f�[�g
void CBossManager::Update()
{
	boss->Update();
	ChangeDragon();
	ChangeLyingKing();
	SmokeUpdate();

}

//	�X���[�N�̃A�b�v�f�[�g
void CBossManager::SmokeUpdate()
{
	if (type != Type::Dragon) return;
	auto king = boss_table.find(Type::King)->second;
	std::dynamic_pointer_cast<CKing>(king)->SmokeUpdate();
}

//	�`��
void CBossManager::Draw()
{
	boss->Draw();

}