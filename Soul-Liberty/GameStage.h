
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/

#pragma once
#include <memory>
#include <siv3D.hpp>
#include "Resource.h"
#include "BackGround.h"
class CMapRead;

class CGameStage
{
public:
	CGameStage(const FilePath path, CResource::GraphicType background);
	enum class State
	{
		Start,
		FadeOut,
		End,
		Move,
	};
	virtual void EventUpdate() = 0;
	virtual void EventDraw() = 0;
	virtual void Draw() = 0;
	void FadeOut();

	std::shared_ptr<CMapRead> GetMapReadData()const{ return map_read; }
	bool IsEventEnd()const{ return (state == State::End); }
protected:
	std::shared_ptr<CMapRead> map_read;
	std::unique_ptr<CBackGround> background;
	State state;
	double alpha;
};

