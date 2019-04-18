// -------------------------------------------
//			�t���[�����[�g�ݒ�
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

//1�t���[���ڂȂ玞�����L��
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
	const int TookTime = time.elapsed() - start_time;	//������������
	const int WaitTime = count * 1000 / FPS - TookTime;	//�҂ׂ�����
	if (WaitTime > 0)
	{
		//�ҋ@
		Sleep(WaitTime);
	}
}


//�ݒ肵���t���[���ڂȂ畽�ς��v�Z����
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