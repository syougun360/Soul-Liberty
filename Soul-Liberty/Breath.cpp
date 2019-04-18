#include "Breath.h"
#include "Utility.h"
#include "Resource.h"
#include "GameObjectHousing.h"
#include "BossActor.h"

const Float3 GraphicSize = Float3(300, 300, 0.00001f);
const int Power = 10;

CBreath::CBreath() :
CBossAttackState(GraphicSize, Power,10),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 10.0f, CParticleScale(30.0f, 50.0f),
CParticleVelocity(Float3(-5, 5, -5), Float3(5, 10, 5)), CParticleDuration(30, 60), 30)),
charge(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 100.0f, CParticleScale(7.0f, 20.0f),
CParticleVelocity(Float3(0, 0, 0), Float3(0, 0, 0)), CParticleDuration(30, 60), 2))
{
	state = State::Create;
}

//	生成
void CBreath::Create(Float3 pos, Float3 player_pos)
{
	if (state != State::Create) return;
	
	const Float3 center_pos = pos+ Float3(40,-10,0);
	transform.TransformPoint(center_pos);

	velocity = utility::MoveBy(transform.GetPos(), player_pos + Float3(0,100,0), 15);
	charge->TransformPoint(center_pos);
		
	count = 0;
	state = State::Charge;
}

//	チャージ
void CBreath::Charge()
{
	if (state != State::Charge) return;
	charge->MoveTo(transform.GetPos(), 2);
	charge->Update();

	count++;
	if (count >= 120)
	{
		count = 0;
		charge->TransformVelocity(CParticleVelocity(Float3(-5, -10, 0), Float3(-2, -5, 0)));
		state = State::Live;
		CResource::GetInstance().PlaySE(CResource::SE::FireBreath);

	}
}

//	移動処理
void CBreath::Move()
{
	if (state != State::Live) return;

	transform.Translate(velocity);
	
	CollisionStaticObject();
	CollisionPlayer();
	
	count++;
	if (count >= 120)
	{
		state = State::None;
		actor->ReturnAttackPreparation();
	}
}

//	当たった瞬間の処理
void CBreath::OnHit()
{
	count = 0;
	state = State::Effect;
	particles->TransformPoint(transform.GetPos() - Float3(0,transform.GetScale().y/2,0));
	particles->CreateChildren();
}

//	パーティクルのアップデート
void CBreath::ParticleUpdate()
{
	if (state != State::Effect) return;
	particles->ChildrenUpdate();
	particles->Remove();
	
	if (particles->IsEmpty())
	{
		state = State::Create;
		actor->ReturnAttackPreparation();
	}
}

//	アップデート
void CBreath::Update()
{
	Move();
	Charge();
	ParticleUpdate();

	charge->ChildrenUpdate();
	charge->Remove();
}

//	描画
void CBreath::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetEffect(CResource::EffectType::Fire));

	if (state == State::Live)
	{
		graph.rotate(transform.GetRotation()).translate(transform.GetPos()).draw(texture, Color(20, 20, 20), *CResource::GetInstance().GetAlphaRenderer());
	}
	
	auto particle_texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));

	particles->Draw(particle_texture, ColorF(0.2, 0.2, 0.2));
	charge->Draw(particle_texture, ColorF(0.1, 0.1, 0.1));

}