#include "MagicBullet.h"
#include "Resource.h"
#include "Utility.h"

CMagicBullet::CMagicBullet(Float3 pos, Float3 destination) :
transform(pos,Float3(30,30,30),Float3(0,0,0)),
isDelete(false), isFadeout(false), alpha(200), count(0)
{
	velocity = utility::MoveBy(pos, destination, 30);
	velocity.x += Random(0.0f, 5.0f);
	velocity.y += Random(-5.0f, 5.0f);

}

CMagicBullet::CMagicBullet(Float3 pos,int direction) :
transform(pos, Float3(30, 30, 30), Float3(0, 0, 0)),
isDelete(false), isFadeout(false), alpha(200), count(0)
{
	velocity.x = Random(0.0f, 5.0f) + direction * 30;
	velocity.y = Random(-5.0f, 10.0f);
	velocity.z = 0;
}

void CMagicBullet::Update()
{
	transform.Translate(velocity);
	velocity *= 0.97f;

	count++;
	if (isFadeout || count >= 120)
	{
		alpha -= 3;
		isDelete = (alpha <= 0) ? true : false;
	}
}

void CMagicBullet::Death()
{
	isFadeout = true;
}

void CMagicBullet::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));
	Billboard(transform.GetScale().x, transform.GetPos()).draw(texture,
		Color(255, 255, 0).setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}