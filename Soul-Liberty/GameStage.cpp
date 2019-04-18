#include "GameStage.h"
#include "MapRead.h"
#include "BackGround.h"
#include "GameApplication.h"


CGameStage::CGameStage(const FilePath path, CResource::GraphicType background) :
map_read(std::make_shared<CMapRead>(path)),
background(std::make_unique<CBackGround>(background)),
state(State::Start),
alpha(0.0)
{
}

void CGameStage::FadeOut()
{
	if (state != State::FadeOut) return;

	Draw();

	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha += 0.005;
	if (alpha >= 1)
	{
		state = State::End;
	}
}