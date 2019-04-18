#include "OpeningSoul.h"
#include "Resource.h"
#include "Utility.h"
#include "Collision.h"
#include "FPS.h"

const float MaxForce = 1.0f;
COpeningSoul::COpeningSoul(Float3 destination) :
Transform(Float3(-300, 100, -100), Float3(126, 126, 1), Float3(0, 0, 0)),
velocity(Float3(0, MaxForce, 0)),
state(State::Stop),
destination(destination),
count(0)
{
}


void COpeningSoul::Preparation()
{
	if (state != State::Stop) return;

	Translate(velocity);
	velocity.y -= 0.1f;
	if (velocity.y <= -MaxForce)
	{
		velocity.y = MaxForce;
	}

	count++;
	if (count >= CFPS::FPS*5)
	{
		velocity = utility::MoveBy(GetPos(), destination, 3);
		velocity.y += 6.0f;
		state = State::Move;
	}
}

void COpeningSoul::Move()
{
	if (state != State::Move) return;

	Translate(velocity);
	velocity.y -= 0.11f;

	if (collision::SphereToSphere(GetPos(), destination, GetScale().x/4, 10))
	{
		state = State::Hit;
	}
}

void COpeningSoul::Update()
{
	Preparation();
	Move();
}

void COpeningSoul::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Soul));
	Billboard(GetScale(), GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
}