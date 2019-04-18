#include "Tombstone.h"
#include "MapRead.h"


CTombstone::CTombstone(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type) :
CActor(task, Transform(pos + Float3(0, CMapRead::Size/2 * (static_cast<float>(scale_type) - 1.0f), 0),
Float3(CMapRead::Size*static_cast<float>(scale_type), CMapRead::Size*static_cast<float>(scale_type), CMapRead::Size),
Float3(0, PiF / 180 * 180, 0)), State::Live, L"engine/data/database/static_object.ini")
{
	if(scale_type == ScaleType::Normal)
		model = CResource::ModelType::Tombstone;

	else if (scale_type == ScaleType::Huge)
		model = CResource::ModelType::Tombstone2;
}


void CTombstone::Draw()
{
	CResource::GetInstance().GetModel(model)->Draw(
		transform.GetPos(), transform.GetScale() / 100, transform.GetRotation(), CModel::Mode::TextureNormal);
}