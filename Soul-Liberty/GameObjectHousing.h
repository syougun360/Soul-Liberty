
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.22
*
*/

#pragma once
#include "Task.h"
#include "ObjectDelete.h"
#include "GameManager.h"

class CMapRead;
class CBackGround;

class CGameObjectHousing
{
public:
	CGameObjectHousing();

	void Init(std::shared_ptr<CMapRead> stage,CGameManager::Stage now_stage);
	void Update();
	void Remove();
	void Draw();
	void StageFinish();
	void GameFinish();
	void EventUpdate();
	bool IsStageFinish()const;
	bool IsGameFinish()const;
	bool IsPlayerDeath()const;

	static const std::string PlayerName;
	static const std::string FloorName;
	static const std::string MonsterManagerName;
	static const std::string EnemyManagerName;
	static const std::string TombstoneName;
	static const std::string FenceName;
	static const std::string DoorName;
	static const std::string BossName;

	static std::vector<std::string> collision_table;
	static std::vector<std::string> collision_side_table;
	static std::vector<std::string> collision_gravity_table;
	static std::vector<std::string> collision_floor_table;

	std::shared_ptr<CTask> task;		///<	ƒ^ƒXƒN
private:
	void Start();

	//	‚ ‚½‚è”»’è‚ÌTable‚ðÝ’è‚·‚é
	void SetCollisionTable();

	std::unique_ptr<CObjectDelete> object_delete;
	std::vector<std::string> object_delete_table;

};

