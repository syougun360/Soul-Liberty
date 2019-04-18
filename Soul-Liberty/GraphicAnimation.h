#pragma once
#include "Noncopyable.h"
#include <map>
#include <memory>

struct AnimationFrame
{
	AnimationFrame();
	AnimationFrame(int start, int end, int switchframe);
	AnimationFrame(int start, int end, int finish, int switchframe);

	AnimationFrame& AnimationFrame::operator=(const AnimationFrame& obj) {
		this->id = obj.id;
		this->count = obj.count;
		return *this;
	}

	void IdCount();
	void Update();
	void Start();

	int id;		//	ID
	int count;	//	カウント
	const int start, end, finish;	//	最初と最後のフレーム
	const int switch_frame;	//	切り替えるフレーム
	
};

template<class T>
class CGraphicAnimation :private Noncopyable
{
public:
	void Append(T type, AnimationFrame animarion)
	{
		animation_table.insert(std::make_pair(type, std::make_shared<AnimationFrame>(animarion)));
	}

	void OnAnimation(T animation_type)
	{
		animation = animation_table.find(animation_type)->second;
		animation->Start();
	}
	
	void Update()
	{
		animation->Update();
	}

	int GetId()const
	{
		return animation->id;
	}

	bool IsFinish()const{ return (animation->id == animation->finish); }

private:
	std::map<T, std::shared_ptr<AnimationFrame>> animation_table;
	std::shared_ptr<AnimationFrame> animation;
};

