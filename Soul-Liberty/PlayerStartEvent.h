
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include "Transform.h"
#include "GraphicAnimation.h"

//	プレイヤーイベント
class CPlayerStartEvent :public Transform
{
public:
	CPlayerStartEvent();

	void Init();
	void Update();
	void Draw();

	//	モーション変更
	void ChangeMontion();

	bool IsFinish()const{ return (state == State::Finish); }
private:
	void CountFinish();

	enum class State
	{
		Normal,
		Motion,
		Finish,
	};
	enum class AnimationType
	{
		Stop,
		Attack,
	};
	int count;
	State state;
	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
};

