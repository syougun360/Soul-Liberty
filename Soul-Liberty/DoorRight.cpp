#include "DoorRight.h"
#include "Resource.h"

const Float3 Size = Float3(220, 300, 100);
CDoorRight::CDoorRight(Float3 pos) :
transform(pos + Float3(0, Size.y / 4, 0), Size, Float3(0,0, 0))
{
}


void CDoorRight::Rotation()
{
	transform.Rotation(Float3(0, PiF / 10, 0));
}


void CDoorRight::Update()
{

}

void CDoorRight::Draw()
{
	CResource::GetInstance().GetModel(CResource::ModelType::DoorR)->Draw(
		transform.GetPos(), transform.GetScale() / 100, 
		transform.GetRotation() + Float3(0, PiF / 180 * 90, 0), CModel::Mode::TextureNormal);
}
