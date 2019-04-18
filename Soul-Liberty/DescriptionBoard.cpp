#include "DescriptionBoard.h"


CDescriptionBoard::CDescriptionBoard(Float3 pos,CResource::DescriptionType type) :
CActor(nullptr,Transform(pos - Float3(0,60,0),Float3(256,400,0.001f),Float3(0,0,0)),State::Live,L""),
type(type)
{
}


void CDescriptionBoard::Update()
{

}

void CDescriptionBoard::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetDescription(type));
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
}
