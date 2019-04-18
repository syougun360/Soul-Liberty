#include "DoorManager.h"
#include "DoorLeft.h"
#include "DoorRight.h"
#include "Resource.h"
const float RotaRight = PiF / 180 * 180;
const float RotaLeft = 0;

CDoorManager::CDoorManager(std::shared_ptr<CTask> task,Float3 pos):
CActor(task, Transform(pos + Float3(0, 500/2,0), Float3(100, 500, 100), Float3(0, 0, 0)),
State::Live,L"engine/data/database/static_object.ini")
{
	left = std::make_unique<CDoorLeft>(pos + Float3(0, 0, 50));
	right = std::make_unique<CDoorRight>(pos + Float3(0, 0, -50));
}


void CDoorManager::OnHit()
{
	if (state != State::Live) return;
	state = State::Hit;
}

void CDoorManager::Update()
{
	if (state != State::Hit) return;

	left->Rotation();
	right->Rotation();

	if (left->transform.GetRotation().y <= -PiF / 180 * 90)
	{
		state = State::None;
	}
}

void CDoorManager::Draw()
{
	CResource::GetInstance().GetModel(CResource::ModelType::DoorVicinity)->Draw(
		transform.GetPos() - Float3(0, 500 / 4, 0), Float3(2, 3, 2), Float3(0, PiF / 180 * 90, 0), CModel::Mode::TextureNormal);

	left->Draw();
	right->Draw();
}
