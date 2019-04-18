/**
*
*	@author	yamada masamitsu
*	@date	2014.10.10
*
*/
#pragma once
#include "PlayerState.h"

class CPlayerAvoidance:public CPlayerState
{
public:
	CPlayerAvoidance();

	void IniData(INIReader ini);

	void Update();

	///	終了処理
	void Finish();

	///	移動量を取得
	Float3 GetVelocity()const{ return velocity; }

	static float MaxSpeed(){ return max_speed; }
	static int LimitCount(){ return limit_count; }

private:
	///	イベント時
	void OnEvent();

	///	移動
	void Move();
	
	///	押し戻す
	void PushBack();

	Float3 velocity;			///<	移動量
	int count;


	static float max_speed;
	static int limit_count;

};

