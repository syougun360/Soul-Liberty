#pragma once
#include <siv3d.hpp>

class CPlayer;

class CSoulParticle
{
public:
	CSoulParticle(Float3 pos, float radius, ColorF color);

	void Update();
	void Draw();

	///	指定した座標に移動する
	void MoveTo(Float2 goal_pos);

	///	吸収するためのあたり判定
	bool IsAbsorptionCollision();

	///	削除していいかを取得
	bool GetDelete()const{ return isDelete; }

private:
	void Diffusion();
	enum class State
	{
		None,
		Move,
		Diffusion,
	};
	State state;
	Float2 pos;
	Float2 velocity;
	Float2 absorption_pos;
	float radius;
	int direction;	///<	減速度
	int count;
	bool isDelete;
	ColorF color;
};

