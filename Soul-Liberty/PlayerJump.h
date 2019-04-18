/**
*
*	@author	yamada masamitsu
*	@date	2014.10.05
*
*/
#pragma once
#include "PlayerState.h"
#include "Resource.h"
class CPlayer;

class CPlayerJump :public CPlayerState
{
public:
	CPlayerJump();

	void IniData(INIReader ini);

	///	アップデート
	void Update();

	void Finish();

	enum class Step
	{
		None,
		First,
		Second,
	};

	Step GetStep()const{ return step; }

	static float MaxPower(){ return max_power; }

private:
	///	キーイベント
	void OnKeyEvent(Step next_state, float jump_power, CPlayer::AnimationType step, CResource::SE jump_se);

	///	状態がない時に押せるイベント
	void StateNoneOnEvent();

	///	1段ジャンプ
	void FirstStep();

	///	2段ジャンプ
	void SecondStep();

	///	あたり判定リスト
	void CollisionList();

	///	移動処理
	void Move();

	static float max_power;

	Step step;
	float force;
};

