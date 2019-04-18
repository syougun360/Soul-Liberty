/**
*
*	@author	yamada masamitsu
*	@date	2014.11.06
*
*/
#pragma once

#include "Actor.h"

class CSlimeActor;
class CMapRead;
class CMagicSoldier;
class CWeaponSoldier;
class CObjectDelete;

class CEnemyManager:public CActor
{
public:
	CEnemyManager(std::shared_ptr<CTask> task, std::shared_ptr<CMapRead> map);

	void Start();
	void Update();
	void Draw();
	void Create();

	//	�{�X����X���C���𐶐�
	void CreateSlimeToBoss(Float3 pos);

	//	�X���C���̃C���X�^���X�擾
	std::shared_ptr<CSlimeActor> SlimeGetInstance(const int id)const;

	//	���@�G�̃C���X�^���X�擾
	std::shared_ptr<CMagicSoldier> MagicGetInstance(const int id)const;

	//	����G�̃C���X�^���X�擾
	std::shared_ptr<CWeaponSoldier> WeaponGetInstance(const int id)const;
	
	int SlimeGetSize()const;
	int MagicGetSize()const;
	int WeaponGetSize()const;
	static const std::string SlimeName;
	static const std::string WeaponName;
	static const std::string MagicName;
private:
	//	�X���C�����^�X�N�ɒǉ�
	void SlimeBlackAppandElement(const int x, const int y);

	//	�X���C�����^�X�N�ɒǉ�
	void SlimeRedAppandElement(const int x, const int y);

	//	�X���C�����^�X�N�ɒǉ�
	void SlimeBlueAppandElement(const int x, const int y);

	//	����G���^�X�N�ɒǉ�
	void WeaponAppandElement(const int x, const int y);

	//	���@�G���^�X�N�ɒǉ�
	void MagicAppandElement(const int x, const int y);

	//	�폜�p�^�X�N�ɖ��O��ǉ�
	void AppendDeleteName();

	template<class T,class FLOAT3>
	void SlimeCreate(FLOAT3 pos);

	std::shared_ptr<CTask> enemy_task;
	std::shared_ptr<CMapRead> map;
	std::shared_ptr<CActor> enemy;
	std::shared_ptr<CActor> weapon_enemy;
	std::shared_ptr<CActor> magic_enemy;
	std::vector<std::string> delete_table;
	std::unique_ptr<CObjectDelete> object_delete;
};

