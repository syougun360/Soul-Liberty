#include "PlayerEvent.h"
#include "Resource.h"
#include "Utility.h"

const Float3 GraphicScale = Float3(256, 256, 1);

CPlayerEvent::CPlayerEvent() :
animation(std::make_unique<CGraphicAnimation<AnimationType>>()),
Transform(Float3(0, -GraphicScale.y/2.3f, 0), GraphicScale, Float3(0, 0, 0))
{
	animation->Append(AnimationType::Stop, AnimationFrame(0, 0, 0));
	animation->Append(AnimationType::Move, AnimationFrame(1, 5, 7));
	animation->OnAnimation(AnimationType::Stop);
}

void CPlayerEvent::Update()
{
	animation->Update();
}

void CPlayerEvent::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetPlayer(animation->GetId()));

	Billboard(GetScale(), GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());
}