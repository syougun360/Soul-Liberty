
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Resource.h"

///	�w�i�N���X
class CBackGround
{
public:
	CBackGround(CResource::GraphicType background);
	void Draw();

private:
	CResource::GraphicType background;
};

