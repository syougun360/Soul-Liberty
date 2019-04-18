#include "King.h"
#include "Resource.h"
#include "FPS.h"

const Float3 GraphicScale = Float3(256, 256, 0.0001f);
CKing::CKing(std::shared_ptr<CTask> task,Float3 pos):
CBossActor(task, Transform(pos + Float3(0, GraphicScale.y / 3.5f, 0), GraphicScale, Float3(0, 0, 0)), 0),
particle(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, pos, 50.0f, CParticleScale(32.0f, 64.0f),
CParticleVelocity(Float3(-10, 0, -10), Float3(10, 15, 10)), CParticleDuration(60, 120), 5)),
count(0)
{
}

//	ダメージ処理
void CKing::Damage(const int power)
{
	hp -= power;
}

//	アップデート
void CKing::Update()
{
	if (state != State::Start) return;
	particle->Update();
	
	count++;
	if (count >= CFPS::FPS*5)
	{
		count = 0;
		state = State::Death;
	}
}

//	煙のアップデート
void CKing::SmokeUpdate()
{
	if (state != State::Death) return;

	particle->ChildrenUpdate();
	particle->Remove();

	auto particle_texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Smoke));
	particle->Draw(particle_texture);

	if (!particle->IsEmpty()) return;
	state = State::None;
}

//	キャラクター描画
void CKing::CharacterDraw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::King));
	Billboard(transform.GetScale(), transform.GetPos()).draw(texture, *CResource::GetInstance().GetAlphaRenderer());

}

//	描画
void CKing::Draw()
{
	CharacterDraw();
	auto particle_texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Smoke));
	particle->Draw(particle_texture);
}