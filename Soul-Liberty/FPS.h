
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	フレームレート
class CFPS
{
public:
	CFPS();

	void Update();
	void Wait();
	
	static const int FPS = 60;	//設定したFPS
	static const int N = FPS;//平均を取るサンプル数
private:
	//1フレーム目なら時刻を記憶
	void FirstSetFPS();

	//設定したフレーム目なら平均を計算する
	void CalcAverage();
	
	int start_time;         //測定開始時刻
	int count;             //カウンタ
	float fps;             //fps

	TimerMillisec time;
};

