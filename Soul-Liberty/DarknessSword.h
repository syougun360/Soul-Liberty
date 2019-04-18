/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/

#pragma once
#include "Transform.h"

class CDarknessSword
{
public:
	CDarknessSword(Float3 pos, Float3 destination);
	CDarknessSword(Float3 pos, int direction);

	void Update();
	void Draw();
	void Death();
	bool IsDelete()const{ return isDelete; }
	bool IsCollision()const{ return !isFadeout; }

	Transform transform;

private:
	bool isDelete;
	bool isFadeout;
	int alpha;
	Float3 velocity;
	Mesh sword;
};

