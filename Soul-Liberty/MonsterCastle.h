#pragma once
#include "Transform.h"

class CMonsterCastle
{
public:
	CMonsterCastle(Float3 pos, Float3 destination, Float3 absorption_pos, Texture texture, Texture back_texture, ColorF color);

	void Update();
	void Draw();

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

	State state;
	int alpha;
	float speed;
	Float3 destination;
	Float3 absorption_pos;
	Float3 velocity;
	Texture texture;
	Texture back_texture;
	Color color;
	Transform transform;
};
