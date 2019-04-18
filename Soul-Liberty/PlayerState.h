
/**
*
*	@author	yamada masamitsu
*	@date	2014.10.01
*
*/

#pragma once
#include <memory>
#include <siv3D.hpp>
#include "Player.h"

///	プレイヤ状態クラス
class CPlayerState
{
public:
	CPlayerState() :
		state(State::None){};

	virtual void Start(std::shared_ptr<CPlayer> player)
	{
		this->player = player;
	}

	virtual void Update() = 0;

	enum class State
	{
		None,
		Start,
		Live,
		Stop,
		BossInFiled,
	};

	State GetState()const{ return state; }
protected:
	std::shared_ptr<CPlayer> player;
	State state;
};
