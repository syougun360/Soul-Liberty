
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.16
*
*/
#pragma once
#include "GraphicAnimation.h"
#include "Transform.h"

class CPlayerEvent:public Transform
{
public:
	CPlayerEvent();

	void Update();
	void Draw();

private:
	enum class AnimationType
	{
		Stop,
		Move,
	};
	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
};

