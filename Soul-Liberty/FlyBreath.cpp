#include "FlyBreath.h"
#include "Utility.h"
#include "Resource.h"
#include "GameObjectHousing.h"
#include "BossActor.h"

const Float3 GraphicSize = Float3(300, 300, 0.00001f);
const int Power = 10;

CFlyBreath::CFlyBreath() :
CBossAttackState(GraphicSize, Power),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 10.0f, CParticleScale(30.0f, 50.0f),
CParticleVelocity(Float3(-5, 5, -5), Float3(5, 10, 5)), CParticleDuration(30, 60), 30)),
charge(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual, Float3(0, 0, 0), 100.0f, CParticleScale(7.0f, 20.0f),
CParticleVelocity(Float3(0, 0, 0), Float3(0, 0, 0)), CParticleDuration(30, 60), 2))
{
	state = State::None;
	force = 10.0f;
}

//	Updateの前に呼ばれる処理
void CFlyBreath::Start(std::shared_ptr<CBossActor> dragon)
{
	actor = dragon;
	CResource::GetInstance().PlaySE(CResource::SE::DragonFly);
}

//	飛ぶ処理
void CFlyBreath::Fly()
{
	if (state != State::None) return;

	actor->transform.Translate(Float3(0, force, 0));
	force -= 0.6f;

	if (force <= -5.0f)
	{
		actor->transform.Rotation(Float3(0, 0, PiF / 90));
		force = 10.0f;
		CResource::GetInstance().PlaySE(CResource::SE::DragonFly);

	}

	if (actor->transform.GetPos().y > 300)
	{
		actor->transform.Rotation(Float3(0, 0, PiF / 180 * 10));
		state = State::Create;
	}
}

//	生成処理
void CFlyBreath::Create(Float3 pos, Float3 player_pos)
{
	this->player_pos = player_pos + Float3(0, 100, 0);

	if (state != State::Create) return;

	const Float3 center_pos = pos + Float3(70, -80, 0);
	transform.TransformPoint(center_pos);

	charge->TransformPoint(center_pos);
	count = 0;
	state = State::Charge;
}

//	チャージ処理
void CFlyBreath::Charge()
{
	if (state != State::Charge) return;
	charge->MoveTo(transform.GetPos(), 2);
	charge->Update();

	count++;
	if (count == 60)
	{
		CResource::GetInstance().PlaySE(CResource::SE::FireBreath);
	}
	else if (count >= 120)
	{
		count = 0;
		charge->TransformVelocity(CParticleVelocity(Float3(-5, -10, 0), Float3(-2, -5, 0)));
		state = State::Live;
		velocity = utility::MoveBy(transform.GetPos(), player_pos, 15);

	}
}

//	移動処理
void CFlyBreath::Move()
{
	if (state != State::Live) return;

	transform.Translate(velocity);

	CollisionStaticObject();
	CollisionPlayer();

	count++;
	if (count >= 120)
	{
		state = State::Effect;
		count = 0;
	}
}

//	当たった時の処理
void CFlyBreath::OnHit()
{
	count = 0;
	state = State::Effect;
	particles->TransformPoint(transform.GetPos() - Float3(0, transform.GetScale().y / 2, 0));
	particles->CreateChildren();
}

//	降下処理
void CFlyBreath::DragonDescent()
{
	actor->transform.Translate(Float3(0, -2, 0));

	if (actor->transform.GetRotation().z >= 0)
	{
		actor->transform.Rotation(Float3(0, 0, -0.01f));
	}
}

//	パーティクルアップデート
void CFlyBreath::ParticleUpdate()
{
	if (state != State::Effect) return;

	particles->ChildrenUpdate();
	particles->Remove();
	DragonDescent();

	if (actor->CollisionStaticObject(CGameObjectHousing::FloorName, actor->transform))
	{
		actor->transform.LookAt(Float3(0, 0, 0));
		force = 0;
		state = State::None;
		actor->ReturnAttackPreparation();
	}
}

void CFlyBreath::Update()
{
	Fly();
	Move();
	Charge();
	ParticleUpdate();

	charge->ChildrenUpdate();
	charge->Remove();
}

void CFlyBreath::Draw()
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