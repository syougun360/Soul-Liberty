#include "Fence.h"
#include "MapRead.h"

CFence::CFence(std::shared_ptr<CTask> task, Float3 pos, CGameManager::Stage type) :
CActor(task, Transform(pos, Float3(CMapRead::Size, CMapRead::Size, CMapRead::Size), Float3(0, 0, 0)),
State::Live, L"engine/data/database/static_object.ini")
{
	this->type = (type == CGameManager::Stage::Boneyard) ? CResource::ModelType::Fence : CResource::ModelType::Fence2;
}


void CFence::Draw()
{
	CResource::GetInstance().GetModel(type)->Draw(
		transform.GetPos(), transform.GetScale() / 100, Float3(0, 0, 0), CModel::Mode::TextureNormal);
}