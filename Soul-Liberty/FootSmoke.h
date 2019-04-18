/**
*
*	@author	yamada masamitsu
*	@date	2014.11.05
*
*/

#pragma once
#include "ParticleMath.h"
#include "Noncopyable.h"

class CPlayerMove;


class CFootSmoke:private Noncopyable
{
public:
	CFootSmoke(Float3 pos, Float3 velocity);

	void Update();
	void Draw();

	bool GetDelete()const{ return isDelete; }
private:
	Float3 pos;
	Float3 velocity;
	float size;
	int id;
	int alpha;
	bool isDelete;

};


class CFootSmokeSystem :private Noncopyable
{
public:
	CFootSmokeSystem();

	void Update(CPlayerMove *instance, const Float3 &player_pos);
	void Draw();
private:
	void FootSE();

	std::vector<std::unique_ptr<CFootSmoke>> particles;
	int count;
};
