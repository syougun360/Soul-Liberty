#include "Floor.h"
#include "MapRead.h"

CFloor::CFloor(std::shared_ptr<CTask> task, Float3 pos, CGameManager::Stage texture_type) :
CActor(task, Transform(pos, CMapRead::FloorSize, Float3(0, 0, 0)),
State::Live, L"engine/data/database/static_object.ini")
{
	if (texture_type == CGameManager::Stage::Boneyard)
		type = CResource::FloorType::BoneyardFloor;

	else if (texture_type == CGameManager::Stage::Castle)
		type = CResource::FloorType::CastleFloor;
}

CFloor::CFloor(Float3 pos, CGameManager::Stage texture_type) :
CActor(nullptr, Transform(pos, CMapRead::FloorSize, Float3(0, 0, 0)), 
State::Live, L"engine/data/database/static_object.ini")
{
	if (texture_type == CGameManager::Stage::Boneyard)
		type = CResource::FloorType::BoneyardFloor;

	else if (texture_type == CGameManager::Stage::Castle)
		type = CResource::FloorType::CastleFloor;
}

void CFloor::Draw()
{
	CResource::GetInstance().GetFloor(type)->Draw(
		transform.GetPos(), transform.GetScale() / 100, Float3(0, 0, 0), CModel::Mode::TextureNormal);
}
