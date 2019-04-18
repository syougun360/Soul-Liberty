
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/

#pragma once
#include <memory>
#include <vector>
#include <string>

class CTask;
class CPlayer;
class CActor;

//	自動的にいらなくなったオブジェクトを削除する
class CObjectDelete
{
public:
	CObjectDelete(std::shared_ptr<CTask> task, std::shared_ptr<CPlayer> player, std::vector<std::string> name_table);

	void Update();
private:
	///	削除する範囲に含まれていたら削除する
	void IncludeDelete(std::shared_ptr<CActor> actor);
	std::shared_ptr<CTask> task;
	std::vector<std::string> name_table;
	std::shared_ptr<CPlayer> player;
};

