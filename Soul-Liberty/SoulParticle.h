#pragma once
#include <siv3d.hpp>

class CPlayer;

class CSoulParticle
{
public:
	CSoulParticle(Float3 pos, float radius, ColorF color);

	void Update();
	void Draw();

	///	�w�肵�����W�Ɉړ�����
	void MoveTo(Float2 goal_pos);

	///	�z�����邽�߂̂����蔻��
	bool IsAbsorptionCollision();

	///	�폜���Ă��������擾
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
	int direction;	///<	�����x
	int count;
	bool isDelete;
	ColorF color;
};

