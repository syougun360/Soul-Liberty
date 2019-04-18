#include "GraphicAnimation.h"

AnimationFrame::AnimationFrame():
start(0), end(0), id(0), count(0), switch_frame(0), finish(0)
{
}

AnimationFrame::AnimationFrame(int start, int end, int switchframe) :
start(start), end(end), id(0), count(0), switch_frame(switchframe), finish(start)
{
}

AnimationFrame::AnimationFrame(int start, int end, int finish, int switchframe) :
start(start), end(end), id(0), count(0), switch_frame(switchframe), finish(finish)
{
}

void AnimationFrame::Start()
{
	id = start;
	count = 0;
}
void AnimationFrame::Update()
{
	count++;
	if (count >= switch_frame)
	{
		count = 0;
		IdCount();
	}
}

void AnimationFrame::IdCount()
{
	id++;
	if (id >= end)
	{
		id = finish;
	}
}
