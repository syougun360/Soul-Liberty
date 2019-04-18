#pragma once
#include <siv3d.hpp>

class CPlayer;

class CSoulParticle
{
public:
	CSoulParticle(Float3 pos, float radius, ColorF color);

	void Update();
	void Draw();

	///	w’è‚µ‚½À•W‚ÉˆÚ“®‚·‚é
	void MoveTo(Float2 goal_pos);

	///	‹zû‚·‚é‚½‚ß‚Ì‚ ‚½‚è”»’è
	bool IsAbsorptionCollision();

	///	íœ‚µ‚Ä‚¢‚¢‚©‚ğæ“¾
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
	int direction;	///<	Œ¸‘¬“x
	int count;
	bool isDelete;
	ColorF color;
};

