#include "Flame.h"
#include "Utility.h"
#include "Resource.h"
#include "GameObjectHousing.h"
#include "BossActor.h"

const Float3 GraphicSize = Float3(150, 150, 0.00001f);
const int Power = 3;

CFlame::CFlame(Float3 pos, Float3 player_pos) :
CBossAttackState(pos, GraphicSize, player_pos, Power),
particles(std::make_unique<CParticleSystem>(CParticleSystem::Mode::Individual,Float3(0,0,0),10.0f,CParticleScale(30.0f,50.0f),
CParticleVelocity(Float3(-5,5,-5),Float3(5,10,5)),CParticleDuration(30,60),10))
{

}

CFlameManager::CFlameManager() :
CBossAttackState(GraphicSize, Power),
count(0)
{

}

//	生成
void CFlameManager::Create(Float3 pos, Float3 player_pos)
{
	const int CreateTime = 60;
	const int CreateNum = 5;

	if (state != State::Create) return;

	count++;
	if ((count % CreateTime) == 0)
	{
		flames.push_back(std::make_unique<CFlame>(pos,player_pos));
	}

	if (count >= CreateTime * CreateNum)
	{
		count = 0;
		state = State::Effect;
	}
}

//	終了処理
void CFlameManager::Finish()
{
	if (state != State::Effect) return;

	count++;
	if (count >= 120)
	{
		state = State::Create;
		count = 0;
		actor->ReturnAttackPreparation();
	}
}

//	静的なオブジェクトのあたり判定
void CFlameManager::CollisionStaticObject(std::unique_ptr<CFlame>& flame)
{
	for (auto& name : CGameObjectHousing::collision_table)
	{
		if (actor->CollisionStaticObject(name, flame->transform))
		{
			flame->OnHit();
			continue;
		}
	}
}

//	プレイヤーとのあたり判定
void CFlameManager::CollisionPlayer(std::unique_ptr<CFlame>& flame)
{
	if (actor->CollisionToPlayer(flame->transform))
	{
		flame->OnHit();
	}
}

//	あたり判定のアップデート
void CFlameManager::CollisionUpdate()
{
	for (auto& flame : flames)
	{
		if (!flame->IsCollision()) continue;
		CollisionPlayer(flame);
		CollisionStaticObject(flame);
	}
}

//	アップデート
void CFlameManager::Update()
{
	for (auto& flame : flames)
	{
		flame->Update();
	}

	CollisionUpdate();
	Finish();

	Erase_if(flames, [](std::unique_ptr<CFlame>& flame)
	{
		return flame->IsDelete();
	});
}

//	描画
void CFlameManager::Draw()
{
	for (auto& flame : flames)
	{
		flame->Draw();
	}
}

//	移動処理
void CFlame::Move()
{
	if (state != State::Live) return;

	transform.Translate(velocity);

}

//	パーティクルアップデート
void CFlame::ParticleUpdate()
{
	if (state != State::None) return;

	particles->ChildrenUpdate();
	particles->Remove();
	if (particles->IsEmpty())
	{
		isDelete = true;
	}
}

//	アップデート
void CFlame::Update()
{
	Move();
	ParticleUpdate();
}

//	当たった瞬間の処理
void CFlame::OnHit()
{
	if (state != State::Live) return;

	state = State::None;
	particles->TransformPoint(transform.GetPos());
	particles->CreateChildren();
}

//	描画
void CFlame::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetEffect(CResource::EffectType::Fire));

	if (state == State::Live)
	{
		graph.rotate(transform.GetRotation()).translate(transform.GetPos()).draw(texture, Color(20, 20, 20), *CResource::GetInstance().GetAlphaRenderer());
	}

	auto particle_texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));

	particles->Draw(particle_texture, ColorF(0.2, 0.2, 0.2));

}