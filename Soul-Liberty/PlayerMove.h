
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "PlayerState.h"
#include "FootSmoke.h"

class CPlayerMove:public CPlayerState
{
public:
	CPlayerMove();

	void IniData(INIReader ini);

	void Update();
	void Draw();
	void Finish();
	void OnSpecialAttack();

	//	次のステージに行くイベント
	void NextStageEvent();

	///	停止
	void Stop();

	///	移動量を取得
	Float3 GetVelocity()const{ return velocity; }

	void SpeedDown();

	bool CanFootSmoke()const;

	static float LimitSpeed(){ return limit_speed; }
	static float AccelerationSpeed(){ return acceleration_speed; }
	static float MaxSpeed(){ return max_speed; }
private:
	void Normal();

	//	状態をLIVE変える処理
	void ChangeStateLive();

	///	右移動
	void Right();	

	///	左移動
	void Left();	

	///	移動量設定
	void VelocitySpeed(const float speed);	

	///	衝突判定リスト
	void CollisionList();
	
	///	速度減少アップデート
	void SpeedDownUpdate();

	///	加速度
	struct Acceleration
	{
		Acceleration() :left(0), right(0){}
		float left, right;	///<	左右

		///	止まった時の処理
		void OnStop();

		///	左アップデート
		void LeftUpdate();

		///	右アップデート
		void RightUpdate();
	};

	static float limit_speed;			///<	制限速度
	static float acceleration_speed;	///<	加速度設定
	static float max_speed;

	bool isSpeedDown;
	int count;
	float speed;	///<	速度
	Float3 velocity;			///<	移動量
	Acceleration acceleration;	///<	加速度
	std::unique_ptr<CFootSmokeSystem> foot_smoke;	///<	足煙
};