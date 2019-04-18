#pragma once
#include <Siv3D.hpp>
#include "Resource.h"

class CTitleLogo
{
public:
	CTitleLogo(Float2 pos, Float2 size, bool isAnimation = false);

	void Update();
	void Draw(CResource::TitleGraphicType type);

private:
	void FadeOut();
	void FadeIn();
	enum class State
	{
		FadeIn,
		FadeOut,
	};
	Float2 pos;
	Float2 size;
	int alpha;
	bool isAnimation;
	State state;
};

