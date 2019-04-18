// ------------------------------------------
//	ステージ全体の処理
//				code by yamada masamitsu
// -------------------------------------------

#include "BackGround.h"
#include "MapRead.h"

CBackGround::CBackGround(CResource::GraphicType background):
background(background)
{


}

void CBackGround::Draw()
{
	const int LoopNum = 22;
	const float WidthSize = CMapRead::Size * 10;
	const float HeightSize = CMapRead::Size * 7;
	for (int i = -1; i < LoopNum; i++)
	{
		Billboard(Float3(WidthSize, HeightSize, 1),
			Float3(i*WidthSize, HeightSize / 10, CMapRead::FloorSize.z / 2)).draw(
			TextureAsset(CResource::GetInstance().GetGraphic(background)));
	}
}
