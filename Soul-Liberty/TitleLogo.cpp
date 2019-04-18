#include "TitleLogo.h"
#include "Resource.h"

CTitleLogo::CTitleLogo(Float2 pos, Float2 size, bool isAnimation) :
pos(pos),size(size), isAnimation(isAnimation),
state(State::FadeOut),alpha(255)
{
}
const int fade_speed = 3;
void CTitleLogo::FadeIn()
{
	if (state != State::FadeIn) return;

	alpha += fade_speed;
	if (alpha >= 255)
	{
		state = State::FadeOut;
	}
}

void CTitleLogo::FadeOut()
{
	if (state != State::FadeOut) return;

	alpha -= fade_speed;
	if (alpha <= 100)
	{
		state = State::FadeIn;
	}
}
void CTitleLogo::Update()
{
	if (!isAnimation) return;

	FadeIn();
	FadeOut();
}

void CTitleLogo::Draw(CResource::TitleGraphicType type)
{
	TextureAsset(CResource::GetInstance().GetTitleGraphic(type)).resize(size).drawAt(pos,Alpha(alpha));
}

