#include "DoorLeft.h"
#include "Resource.h"

const Float3 Size = Float3(220, 300, 100);
CDoorLeft::CDoorLeft(Float3 pos) :
transform(pos + Float3(20, Size.y / 4, 0), Size, Float3(0, 0, 0))
{
}


void CDoorLeft::Rotation()
{
	transform.Rotation(Float3(0, -PiF / 10, 0));
}


void CDoorLeft::Update()
{

}

void CDoorLeft::Draw()
{
	CResource::GetInstance().GetModel(CResource::ModelType::DoorL)->Draw(
		transform.GetPos(), transform.GetScale() / 100, transform.GetRotation() + Float3(0, PiF / 180 * 90,0), CModel::Mode::TextureNormal);
}
