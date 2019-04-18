#include "PlayerStartEvent.h"
#include "Resource.h"

CPlayerStartEvent::CPlayerStartEvent():
Transform(Float3(50, 250, 0), Float3(500, 500, 1), Float3(0, 0, 0)),
animation(std::make_unique<CGraphicAnimation<AnimationType>>()),
state(State::Normal)
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Attack, AnimationFrame(8, 16, 16, 10));
}


void CPlayerStartEvent::Init()
{
	count = 0;
	state = State::Normal;
	animation->OnAnimation(AnimationType::Stop);

}
void CPlayerStartEvent::ChangeMontion()
{
	if (state != State::Normal) return;
	state = State::Motion;
	animation->OnAnimation(AnimationType::Attack);
}

void CPlayerStartEvent::CountFinish()
{
	if (!animation->IsFinish()) return;
	state = State::Finish;
}

void CPlayerStartEvent::Update()
{
	if (state != State::Motion) return;
	animation->Update();
	CountFinish();
}

void CPlayerStartEvent::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetPlayer(animation->GetId()));
	texture.resize(Point(GetScale().x, GetScale().y)).draw(Point(GetPos().x,GetPos().y));
}