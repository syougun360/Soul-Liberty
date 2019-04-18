
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Resource.h"

///	”wŒiƒNƒ‰ƒX
class CBackGround
{
public:
	CBackGround(CResource::GraphicType background);
	void Draw();

private:
	CResource::GraphicType background;
};

