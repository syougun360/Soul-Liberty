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

//	�{�X�̊Ǘ�
class CBossManager:public CActor
{
public:
	CBossManager(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();

	bool IsDeath()const;

	//	Dragon�ɕύX
	void ChangeDragon();

	//	�|�ꂽ���l�ɕύX
	void ChangeLyingKing();

	//	�{�X�̃C���X�^���X���擾
	std::shared_ptr<CBossActor> GetBoss()const;
private:
	//	�{�X�̎��
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

