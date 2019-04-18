
/**
*
*	Soul-Liberty
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#include <stdlib.h>

# include <Siv3D.hpp>
#include "GameApplication.h"

void Main()
{
	Window::SetTitle(L"Soul-Liberty");
	Window::Resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight);
	CGameApplication app;
	
	while (System::Update())
	{
		app.Update();

	}
}
