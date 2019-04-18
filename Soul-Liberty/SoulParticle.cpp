#include "SoulParticle.h"
#include "Utility.h"
#include "Player.h"
#include "Collision.h"
#include "Resource.h"

CSoulParticle::CSoulParticle(Float3 pos,float radius,ColorF color) :
pos(Float2(Graphics::GetScreenPos(pos).x, Graphics::GetScreenPos(pos).y)), radius(radius), isDelete(false),
velocity(Float2(Random(-20, 20), Random(-20, -15))),
state(State::Diffusion), color(color),
count(0), direction(Random(-1, 1))
{
	if (direction == 0)
	{
		direction = 1;
	}
	velocity.x *= direction;
}


//	éwíËÇµÇΩç¿ïWÇ…à⁄ìÆ
void CSoulParticle::MoveTo(Float2 goal_pos)
{
	if (state != State::Move) return;
	
	utility::MoveTo(goal_pos, pos, velocity);
	absorption_pos = goal_pos;
	velocity.y *= 0.93f;
	if (velocity.x <= 5 || velocity.y <= 5)
	{
		velocity = Float2(5, 5);
	}
}

//	ãzé˚Ç≈ÇÃÇ†ÇΩÇËîªíËÇéÊìæ
bool CSoulParticle::IsAbsorptionCollision()
{
	if (collision::CircleToCircle(pos, absorption_pos, radius, 50))
	{
		isDelete = true;
		return true;
	}

	return false;
}

//	ägéUèàóù
void CSoulParticle::Diffusion()
{
	if (state != State::Diffusion) return;

	pos += velocity;
	velocity.y += 1.0f;
	velocity.x *= 0.93f;

	count++;
	if (count >= 30)
	{
		velocity = Float2(32, 32);
		state = State::Move;
	}
}

void CSoulParticle::Update()
{
	Diffusion();
}

void CSoulParticle::Draw()
{
	const float Radius = radius * 3;
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Soul));
	texture.resize(Radius, Radius).draw(pos - Float2(Radius/2, Radius/2), color.setAlpha(0.8));
}
