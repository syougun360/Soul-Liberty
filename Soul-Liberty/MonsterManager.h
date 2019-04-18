/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include "Actor.h"
#include "Resource.h"

class CMonsterActor;
class CMonsterCall;
class CPlayer;

class CMonsterManager:public CActor
{
public:
	CMonsterManager(std::shared_ptr<CTask> task);
	
	void Start();
	void Update();
	void Draw();
	void Finish();
	void EnableToCall();
	void SoulClear();

	///	�����o
	void CreateSoulRelease(CResource::MonsterUIType type, Float3 create_pos, const int point);

	//	�����ō����z������
	void AutoSoulAbsorption();


	static const Point UI_Pos;
	static const Point UI_Size;
	static const Point UI_Space;
	std::vector<std::shared_ptr<CMonsterActor>> GetMonsterActor()const;
	
private:

	///	�����X�^�[���Ă�
	void Call();
	void CallLimitCount();

	std::shared_ptr<CTask> monster;
	std::shared_ptr<CPlayer> player;
	std::vector<std::shared_ptr<CMonsterActor>> actor;
	static std::array<double,5> soul_point;

	struct UIBackGround
	{
		UIBackGround(Point pos, Point size) :
			pos(pos), size(size){}
		Point pos;	///<	���W
		Point size;	///<	�T�C�Y
	};
	UIBackGround ui;

	int count;
};

