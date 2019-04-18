#include "DarknessSword.h"
#include "Resource.h"
#include "Utility.h"

CDarknessSword::CDarknessSword(Float3 pos, Float3 destination) :
transform(pos, Float3(100, 10, 30), Float3(0, 0, 0)),
isDelete(false), isFadeout(false), alpha(200),
sword(utility::CreateMirroredBox(Float3(126, 126, 1), 1)),
velocity(utility::MoveBy(pos, destination, 5))
{
}

CDarknessSword::CDarknessSword(Float3 pos, int direction) :
transform(pos, Float3(100, 10, 30), Float3(0, 0, 0)),
isDelete(false), isFadeout(false), alpha(200),
sword(utility::CreateMirroredBox(Float3(126, 126, 1), 1)),
velocity(Float3(5 * direction,0,0))
{
}

void CDarknessSword::Update()
{
	transform.Translate(velocity);
	velocity.x *= 1.04f;
	if (isFadeout)
	{
		alpha -= 3;
		isDelete = (alpha <= 0) ? true : false;
	}
}

void CDarknessSword::Death()
{
	isFadeout = true;
}

void CDarknessSword::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetEffect(CResource::EffectType::Darkness));
	sword.translate(transform.GetPos()).draw(texture, Alpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}