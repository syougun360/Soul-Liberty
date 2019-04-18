// -------------------------------------------
//			フレームレート設定
//					code by yamada masamitsu
// -------------------------------------------

#include "FPS.h"
#include <windows.h>

CFPS::CFPS() :
start_time(0),
count(0), 
fps(0)
{
	time.start();
}

//1フレーム目なら時刻を記憶
void CFPS::FirstSetFPS()
{
	if (count == 0)
	{
		start_time = time.elapsed();
	}
}

void CFPS::Update()
{

	FirstSetFPS();
	CalcAverage();
	count++;

}


void CFPS::Wait()
{
	const int TookTime = time.elapsed() - start_time;	//かかった時間
	const int WaitTime = count * 1000 / FPS - TookTime;	//待つべき時間
	if (WaitTime > 0)
	{
		//待機
		Sleep(WaitTime);
	}
}


//設定したフレーム目なら平均を計算する
void CFPS::CalcAverage()
{
	if (count == N)
	{
		int t = time.elapsed();
		fps = 1000.f / ((t - start_time) / (float)N);
		count = 0;
		start_time = t;
	}
}