
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.22
*
*/
#pragma once
#include "Camera.h"

class COpeningCamera
{
public:
	COpeningCamera();
	
	void Update();
	bool IsStop()const{ return (state == State::Stop); }
	float GetPosZ()const;
private:
	//	ÉYÅ[ÉÄ
	void Zoom();

	//	à¯Ç≠
	void Pull();

	enum class State
	{
		Zoom,
		Pull,
		Stop,
	};

	State state;
	int count;
	std::unique_ptr<CCamera> camera;
};

