
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	�t���[�����[�g
class CFPS
{
public:
	CFPS();

	void Update();
	void Wait();
	
	static const int FPS = 60;	//�ݒ肵��FPS
	static const int N = FPS;//���ς����T���v����
private:
	//1�t���[���ڂȂ玞�����L��
	void FirstSetFPS();

	//�ݒ肵���t���[���ڂȂ畽�ς��v�Z����
	void CalcAverage();
	
	int start_time;         //����J�n����
	int count;             //�J�E���^
	float fps;             //fps

	TimerMillisec time;
};

