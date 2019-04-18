#include "CombineSoul.h"
#include "Resource.h"
#include "Utility.h"

const Float3 GraphicSize = Float3(300, 300, 0.001f);

CCombineSoul::CCombineSoul():
CActor(nullptr, Transform(Float3(0, 0, 0), GraphicSize, Float3(0, 0, 0)), State::None, L""),
speed(0),
mesh(utility::CreateMirroredBox(GraphicSize, 1))
{
}

void CCombineSoul::Create(const Float3& pos, const Float3& camera_pos, Color color)
{
	if (state != State::None) return;

	state = State::Live;
	transform.TransformPoint(pos + Float3(0,transform.GetScale().y/4,50));
	this->color = color;
	this->camera_pos = camera_pos;

	alpha = 255;
	speed = 0;
}

void CCombineSoul::Update()
{
	if (state != State::Live) return;

	auto velocity = utility::MoveBy(transform.GetPos(), camera_pos, speed);
	transform.Translate(velocity);
	speed += 0.6f;

	alpha--;
	if (alpha <= 0)
	{
		state = State::None;
	}
}

void CCombineSoul::Draw()
{
	if (state != State::Live) return;

	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::CombineSoul));
	mesh.translate(transform.GetPos()).draw(texture, color, *CResource::GetInstance().GetAlphaRenderer());
}