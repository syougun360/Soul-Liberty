#include "OpeningCamera.h"
#include "Utility.h"

COpeningCamera::COpeningCamera() :
camera(std::make_unique<CCamera>(Float3(0, 0, -300), Float3(0, 0, 0))),
state(State::Zoom),
count(0)
{
}

float COpeningCamera::GetPosZ()const
{
	return camera->GetPos().z;
}
void COpeningCamera::Update()
{
	Zoom();
	Pull();
	camera->Update();
}

void COpeningCamera::Zoom()
{
	if (state != State::Zoom) return;
	count++;
	if (count >= 60)
	{
		state = State::Pull;
	}
}

void COpeningCamera::Pull()
{
	if (state != State::Pull) return;
	const Float3 GoalPos = Float3(0, 100, -600);
	auto velocity = utility::MoveBy(camera->GetPos(), GoalPos, 2);
	camera->Translate(velocity);
	camera->Rotation(Float3(0,velocity.y,0));

	if (utility::IsInclude<float>(camera->GetPos().z, GoalPos.z, 10))
	{
		state = State::Stop;
	}
}