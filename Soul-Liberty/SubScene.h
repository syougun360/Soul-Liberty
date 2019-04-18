
/**
*
*	@author	yamada masamitsu
*	@date	2014.12.03
*
*/
#pragma once
#include "Noncopyable.h"
#include "FPS.h"

template<class SCENE>
class CSubScene:private Noncopyable
{
public:
	CSubScene(SCENE next_scene) :
		next_scene(next_scene), state(State::Start), count(0){}
	virtual ~CSubScene() = default;

	virtual void Update() = 0;
	virtual void Draw() = 0;

	enum class State
	{
		Start,
		Update,
		End,
	};

	virtual void NextScene(const int seconds)
	{
		count++;
		state = (count >= CFPS::FPS * seconds) ? State::End : State::Update;
	}

	SCENE GetNextScene()const{ return next_scene; }
	bool IsEnd()const{ return (state == State::End); }
protected:
	State state;
	SCENE next_scene;
	int count;

private:
};

