/**
*
*	@author	yamada masamitsu
*	@date	2014.10.8
*
*/
#pragma once
#include "PlayerState.h"

class CPlayerDamage :public CPlayerState
{
public:
	CPlayerDamage();

	void IniData(INIReader ini);
	void Update();
	void StartAction();
	void LargeAction();
	void Draw(const Mesh& mesh, const Float3& graphic_pos, const Texture texture);

	bool GetIsLargeAction(){ return isLargeAction; }
	Float3 GetVelocity()const{ return velocity; }

	static Float3 ActionSpeed(){ return action_speed; };

private:
	void Finish();
	void LargeUpdate();
	void NormalUpdate();
	void CollisionUpdate();
	Float3 velocity;
	int count,finish_count;
	bool isLargeAction;

	static Float3 action_speed;

};

