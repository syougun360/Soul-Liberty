/**
*
*	@author	yamada masamitsu
*	@date	2014.10.12
*
*/

#pragma once
#include "Transform.h"
#include "GraphicAnimation.h"

class CTask;
class CEnemyManager;
class CTree
{
public:
	enum class State
	{
		None,
		Death,
		FullBloom,
		Bloom,
		Conbine,
	};

	CTree(Float3 pos);
	CTree(Float3 pos, int direction);

	void Update(std::shared_ptr<CTask> task);
	void Draw();
	void Finish();

	bool IsDelete()const{ return (state == State::Death); }
	bool CanCollision()const{ return (state == State::FullBloom); }
	State GetState()const{ return state; }
	Transform transform;

private:
	void AnimationList();
	void ConbieUpdate();
	void FullBloom();
	void BloomUpdate();
	void CreateHit(std::shared_ptr<CTask> task);
	bool IsCollisionHit(std::shared_ptr<CTask> task, const std::string &name);
	int id;
	int alpha;
	int count;
	Float3 velocity;
	State state;
	Mesh texture;
	std::unique_ptr<CGraphicAnimation<int>> animation;

};

