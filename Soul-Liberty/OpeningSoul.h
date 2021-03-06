
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.22
*
*/
#pragma once
#include "Transform.h"

class COpeningSoul:public Transform
{
public:
	COpeningSoul(Float3 destination);

	void Update();
	void Draw();

	bool IsHit()const{ return (state == State::Hit); }
private:
	//	準備
	void Preparation();
	
	//	移動処理
	void Move();

	enum class State
	{
		Stop,
		Move,
		Hit
	};

	int count;
	State state;
	Float3 destination;
	Float3 velocity;
};

