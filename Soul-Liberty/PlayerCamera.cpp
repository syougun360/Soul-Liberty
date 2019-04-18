#include "PlayerCamera.h"
#include "Player.h"
#include "GameManager.h"
#include "Utility.h"


CPlayerCamera::CPlayerCamera():
CPlayerState(),
camera(std::make_unique<CCamera>(Float3(300, 50, -700), Float3(300, 0, 0))),
light(std::make_unique<CLight>(0, CLight::Type::Point, Float3(300, 1000, -1000), 10000.0f, ColorF(2, 2, 2)))
{

}

Float3 CPlayerCamera::GetPos()const
{
	return camera->GetPos();
}

const Float3 CameraPos = Float3(0, 0, -750);
void CPlayerCamera::Start(std::shared_ptr<CPlayer> player)
{
	this->player = player;
	auto player_pos = player->transform.GetPos();

	camera->TransformPoint(Float3(player_pos.x, 0, 0) + CameraPos);
	camera->LookAt(Float3(player_pos.x, 0, 0));
	state = State::Live;
}

void CPlayerCamera::BossInField()
{
	state = State::BossInFiled;
}

void CPlayerCamera::BossInFiledMove()
{
	if (state != State::BossInFiled) return;

	camera->Translate(Float3(5, 0, 0));
	camera->LookAt(Float3(camera->GetPos().x, CameraPos.y, 0));
	light->TransformPoint(camera->GetPos() + Float3(0, 500, 0));
	
	if (utility::Distance(camera->GetPos().x, player->transform.GetPos().x) >= 300)
	{
		state = State::Stop;
	}
}

void CPlayerCamera::Move()
{
	if (state != State::Live) return;

	if (!player->IsForwardMove()) return;
	camera->TransformPoint(Float3(player->transform.GetPos().x, 0,0) + CameraPos);
	camera->LookAt(Float3(player->transform.GetPos().x + CameraPos.x, CameraPos.y, 0));
	light->TransformPoint(camera->GetPos()+Float3(0,500,0));

}
void CPlayerCamera::Update()
{
	Move();
	BossInFiledMove();
	camera->Update();
	light->Update();
	
}