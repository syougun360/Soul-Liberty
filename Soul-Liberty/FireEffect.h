/**
*
*	@author	yamada masamitsu
*	@date	2014.10.16
*
*/
#pragma once
#include "Transform.h"

class CFireEffect
{
public:
	CFireEffect(Float3 pos, int direction);
	CFireEffect(Float3 pos, int direction,float speed);

	void Update();
	void Draw();
	void Finish();
	bool IsNone()const{ return (state == State::None); }

	Transform transform;

private:

	enum class State
	{
		None,
		Live,
	};

	Float3 velocity;
	State state;
	float speed;
};

