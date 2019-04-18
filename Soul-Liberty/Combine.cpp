#include "Combine.h"
#include "MonsterActor.h"
#include "Utility.h"

CCombine::CCombine(const Float3& back_size) :
CPlayerState(),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 20.0f, 
CParticleScale(5, 10), CParticleVelocity(Float3(-2, 1, 0), Float3(2, 5, 0)),
CParticleDuration(10, 30), 3)),
soul(std::make_unique<CCombineSoul>()),
left(utility::CreateMirroredBox(back_size + Float3(30, 0, 0), -1)),
right(utility::CreateMirroredBox(back_size +Float3(30, 0, 0), 1)),
back_size(back_size),
alpha(0)
{
	particles->SetCreate(false);
}

void CCombine::OnCombine(std::shared_ptr<CMonsterActor> actor)
{
	state = State::Start;
	monster = actor;
	color = actor->GetSoulColor();
	actor->OnCombine();
	particles->SetCreate(true);
	CResource::GetInstance().PlaySE(CResource::SE::Conbine);
	soul->Create(player->transform.GetPos(), player->GetCameraPos(), color);
}

void CCombine::SoulAppearance()
{
	if (state != State::Start) return;

	count++;
	if (count >= 30)
	{
		state = State::Live;
		count = 0;
	}

}
void CCombine::AlphaDecrease()
{
	if (state != State::Live) return;
	if (!monster->IsCombineLittle()) return;
	alpha -= 50;
	alpha = std::max(0, alpha);

}
void CCombine::ParticleUpdate()
{
	if (state != State::Live) return;
	particles->TransformPoint(player->transform.GetPos() + Float3(0, player->transform.GetScale().y / 2, 30));
	particles->Update();
	MonsterUpdate();
	alpha += 3;
	alpha = std::min(255, alpha);
}

void CCombine::MonsterUpdate()
{
	monster->CombineUpdate();
	if (monster->IsCombineLittle())
	{
		particles->SetCreate(false);
	}
	if (!monster->IsCombine())
	{
		state = State::None;
	}
}

void CCombine::Update()
{
	SoulAppearance();
	AlphaDecrease();
	ParticleUpdate();
	soul->Update();
}

void CCombine::SoulDraw()
{
	soul->Draw();
}
void CCombine::Draw()
{
	if (state != State::Live) return;
	particles->Draw(color);
}

void CCombine::CharacterDraw(const int id)
{
	if (state != State::Live) return;

	auto texture = CResource::GetInstance().GetPlayerBackTexture(id);
	auto graphic_pos = player->transform.GetPos() + Float3(0, back_size.y / 6, 0);

	if (player->GetDirection() == CPlayer::Direction::Left)
	{
		left.translate(graphic_pos).draw(*texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	}
	else if (player->GetDirection() == CPlayer::Direction::Right)
	{
		right.translate(graphic_pos).draw(*texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	}
}