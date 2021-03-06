
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.16
*
*/

#pragma once
#include <siv3D.hpp>
#include <memory>
#include "Transform.h"
#include "MonsterCall.h"
#include "MonsterUI.h"

class CPlayerEvent;

class CMonsterEvent
{
public:
	CMonsterEvent(std::shared_ptr<CPlayerEvent> player, Float3 pos,
		MonsterUI ui, Texture texture, Texture back_texture,ColorF color);

	void Update();
	void Draw();

	static const Point UI_Pos;
	static const Point UI_Space;
	bool IsAbsorption()const{ return (state == State::Absorption); }
private:
	//	移動処理
	void Appearance();

	//	魂に変身する
	void TransformSoul();

	//	吸収される処理
	void AbsorptionMove();

	enum class State
	{
		Stop,
		Appearance,
		Soul,
		Move,
		Absorption,
	};

	///	Characterのみ描画
	void CharaterDraw();

	///	魂のみ描画
	void SoulDraw();

	void UIDraw();

	State state;
	int alpha;
	float speed;
	Point ui_pos;
	Float3 destination;
	Float3 velocity;
	std::shared_ptr<CPlayerEvent> player;
	std::unique_ptr<CMonsterCall> call;
	Texture texture;
	Texture back_texture;
	Color color;
	Transform transform;
};

