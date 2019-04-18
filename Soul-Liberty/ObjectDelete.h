
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

//	�����I�ɂ���Ȃ��Ȃ����I�u�W�F�N�g���폜����
class CObjectDelete
{
public:
	CObjectDelete(std::shared_ptr<CTask> task, std::shared_ptr<CPlayer> player, std::vector<std::string> name_table);

	void Update();
private:
	///	�폜����͈͂Ɋ܂܂�Ă�����폜����
	void IncludeDelete(std::shared_ptr<CActor> actor);
	std::shared_ptr<CTask> task;
	std::vector<std::string> name_table;
	std::shared_ptr<CPlayer> player;
};

