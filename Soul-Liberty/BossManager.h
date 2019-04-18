/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "Actor.h"
#include <map>
class CBossActor;

//	ボスの管理
class CBossManager:public CActor
{
public:
	CBossManager(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();

	bool IsDeath()const;

	//	Dragonに変更
	void ChangeDragon();

	//	倒れた王様に変更
	void ChangeLyingKing();

	//	ボスのインスタンスを取得
	std::shared_ptr<CBossActor> GetBoss()const;
private:
	//	ボスの種類
	enum class Type
	{
		Devil,
		Dragon,
		King,
	};


	void SmokeUpdate();
	std::map<Type, std::shared_ptr<CBossActor>> boss_table;
	std::shared_ptr<CBossActor> boss;
	Type type;
};

