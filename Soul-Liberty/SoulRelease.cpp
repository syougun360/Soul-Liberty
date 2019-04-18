#include "SoulRelease.h"
#include "Utility.h"
#include "Player.h"

CSoulRelease::CSoulRelease(std::shared_ptr<CPlayer> player, Float3 pos, Float2 monster_ui_pos, int point, Palette color) :
player(player), monster_ui_pos(monster_ui_pos)
{
	for (int i = 0; i < point; i++)
	{
		particles.push_back(std::make_unique<CSoulParticle>(pos, 30.0f,color));
	}
}

//	Žw’è‚µ‚½À•W‚ÉˆÚ“®
void CSoulRelease::MoveTo()
{
	for (auto& it : particles)
	{
		it->MoveTo(Float2(monster_ui_pos.x, monster_ui_pos.y));
	}
}

//	°‚Ì‹zŽû‚ª“–‚½‚Á‚½‚©‚Ç‚¤‚©‚ðŽæ“¾
bool CSoulRelease::IsAbsorptionCollision()
{
	for (auto& it : particles)
	{
		if (it->IsAbsorptionCollision())
			return true;
	}

	return false;
}

//	íœ‚µ‚½‚©‚Ç‚¤‚©‚ðŽæ“¾
bool CSoulRelease::GetDelete()const
{
	return particles.empty();
}

void CSoulRelease::Update()
{
	MoveTo();

	for (auto& it : particles)
	{
		it->Update();
	}

	Erase_if(particles, [](const std::unique_ptr<CSoulParticle> &obj)
	{
		return obj->GetDelete();
	});
}

void CSoulRelease::Draw()
{
	for (auto& it : particles)
	{
		it->Draw();
	}
}
