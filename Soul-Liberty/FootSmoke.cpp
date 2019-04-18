#include "FootSmoke.h"
#include "PlayerMove.h"
#include "Resource.h"

CFootSmoke::CFootSmoke(Float3 pos,Float3 velocity):
pos(pos), velocity(velocity),
size(Random(20.0f,50.0f)),isDelete(false),
id(Random(2)),
alpha(255)
{
	//CResource::GetInstance().PlaySE(CResource::SE::BoneyardFoot);

}

CFootSmokeSystem::CFootSmokeSystem() :
count(0)
{
}

void CFootSmoke::Update()
{
	pos += velocity;

	velocity *= 0.95f;

	alpha -= 3;
	size -= 0.3f;
	if (size <= 0 || alpha <= 0)
	{
		isDelete = true;
	}
}

void CFootSmoke::Draw()
{
	Billboard(size, pos).draw(TextureAsset(CResource::GetInstance().GetSmoke(id)),
		Alpha(alpha),*CResource::GetInstance().GetAlphaRenderer());
}


void CFootSmokeSystem::Update(CPlayerMove *instance, const Float3 &player_pos)
{
	if (instance->GetState() == CPlayerState::State::Live && instance->CanFootSmoke())
	{
		count++;
		if (count % 10 == 0)
		{
			count = 0;
			particles.push_back(std::make_unique<CFootSmoke>(player_pos, Float3(Random(-1.0f, 1.0f), Random(2.0f, 5.0f), 0)));
		}

	}

	for (auto& particle : particles)
	{
		particle->Update();
	}

	Erase_if(particles, [](std::unique_ptr<CFootSmoke>& smoke)
	{
		return smoke->GetDelete();
	});
}


void CFootSmokeSystem::Draw()
{
	for (auto& particle : particles)
	{
		particle->Draw();
	}
}