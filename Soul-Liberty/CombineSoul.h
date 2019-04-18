#pragma once
#include "Actor.h"

class CCombineSoul:public CActor
{
public:
	CCombineSoul();

	void Update();
	void Draw();
	void Create(const Float3& pos, const Float3& camera_pos, Color color);

private:
	float speed;
	int alpha;
	Color color;
	Mesh mesh;
	Float3 camera_pos;
};

