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

	//	ボスからスライムを生成
	void CreateSlimeToBoss(Float3 pos);

	//	スライムのインスタンス取得
	std::shared_ptr<CSlimeActor> SlimeGetInstance(const int id)const;

	//	魔法敵のインスタンス取得
	std::shared_ptr<CMagicSoldier> MagicGetInstance(const int id)const;

	//	武器敵のインスタンス取得
	std::shared_ptr<CWeaponSoldier> WeaponGetInstance(const int id)const;
	
	int SlimeGetSize()const;
	int MagicGetSize()const;
	int WeaponGetSize()const;
	static const std::string SlimeName;
	static const std::string WeaponName;
	static const std::string MagicName;
private:
	//	スライムをタスクに追加
	void SlimeBlackAppandElement(const int x, const int y);

	//	スライムをタスクに追加
	void SlimeRedAppandElement(const int x, const int y);

	//	スライムをタスクに追加
	void SlimeBlueAppandElement(const int x, const int y);

	//	武器敵をタスクに追加
	void WeaponAppandElement(const int x, const int y);

	//	魔法敵をタスクに追加
	void MagicAppandElement(const int x, const int y);

	//	削除用タスクに名前を追加
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

