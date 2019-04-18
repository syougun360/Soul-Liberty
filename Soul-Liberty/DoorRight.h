
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include "Transform.h"

class CDoorRight
{
public:
	CDoorRight(Float3 pos);

	void Update();
	void Draw();
	void Rotation();
	Transform transform;

private:
};

