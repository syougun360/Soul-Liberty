// ------------------------------------------------
//		パーティクル処理
//					code by yamada masamitsu
// ------------------------------------------------
#include "Particle.h"
#include "Resource.h"
#include "Utility.h"

//	パーティクルシステム
CParticleSystem::CParticleSystem(Mode mode, Float3 pos, float radius, CParticleScale scale,
CParticleVelocity speed, CParticleDuration duration, int num):
pos(pos), radius(radius), scale(scale), speed(speed), duration(duration),mode(mode), isCreate(true),
num(num)
{
	for (int i = 0; i < num; i++)
	{
		particles.emplace_back(std::make_unique<CParticle>(pos + Float3(Random(-radius, radius), Random(-radius, radius), Random(-radius, radius)),
			Random(scale.GetMin(), scale.GetMax()),
			Float3(Random(speed.GetMin().x, speed.GetMax().x), Random(speed.GetMin().y, speed.GetMax().y),
			Random(speed.GetMin().z, speed.GetMax().z)), Random(duration.GetMin(), duration.GetMax())));
	}
	
}

// -----------------------------------------------------------------------------------
//	パーティクル
//	pos : 座標 , size : 大きさ , velocity : 移動速度 , duration : 存続時間
// ----------------------------------------------------------------------------------
CParticle::CParticle(Float3 pos, float size, Float3 velocity, int duration) :
pos(pos), size(size), velocity(velocity), duration(duration),
count(0), isDelete(false), alpha(1.0), color(ColorF(Random(0.0, 1.0), Random(0.0, 1.0), Random(0.0, 1.0)))
{


}

void CParticleSystem::TransformVelocity(const CParticleVelocity& velocity)
{
	speed = velocity;
}

void CParticleSystem::CreateChildren()
{
	if (!isCreate) return;
	if (mode == Mode::Burst)return;

	for (int i = 0; i < num; i++)
	{
		particles.push_back(std::make_unique<CParticle>(pos + Float3(Random(-radius, radius), Random(-radius, radius), Random(-radius, radius)),
			Random(scale.GetMin(), scale.GetMax()),
			Float3(Random(speed.GetMin().x, speed.GetMax().x), Random(speed.GetMin().y, speed.GetMax().y),
			Random(speed.GetMin().z, speed.GetMax().z)), Random(duration.GetMin(), duration.GetMax())));
	}
}

void CParticleSystem::ChildrenUpdate()
{
	for (auto& particle : particles)
	{
		particle->Update();
	}
}

void CParticleSystem::Remove()
{
	Erase_if(particles, [](const std::unique_ptr<CParticle> &obj)
	{
		return obj->GetIsDelete();
	});
}
void CParticleSystem::Update()
{
	CreateChildren();
	ChildrenUpdate();
	Remove();
}
void CParticleSystem::MoveTo(const Float3 pos,const float speed)
{
	for (auto& particle : particles)
	{
		particle->MoveTo(pos, speed);
	}
}

void CParticleSystem::Draw(ColorF color, bool texture_add)
{
	for (auto& particle : particles)
	{
		if (mode == Mode::Color_Individual)
		{
			particle->Draw(particle->GetColor(),texture_add);
		}
		else
		{
			particle->Draw(color, texture_add);
		}
	}
}

void CParticleSystem::Draw(Texture texture, ColorF color)
{
	for (auto& particle : particles)
	{
		particle->Draw(texture, color);
	}
}

void CParticleSystem::Draw2D(Texture texture, ColorF color)
{
	for (auto& particle : particles)
	{
		particle->Draw2D(texture, color);
	}
}

void CParticle::MoveTo(const Float3 pos, const float speed)
{
	velocity = utility::MoveBy(this->pos, pos,speed);
}

//　アップデート
void CParticle::Update()
{
	pos += velocity;

	velocity.x *= Random(0.9f, 1.0f);
	velocity.y *= Random(0.9f, 1.0f);
	velocity.z *= Random(0.9f, 1.0f);

	size -= 0.3f;
	count++;
	if (count >= duration)
	{
		alpha -= 0.1;
	}
	if (alpha <= 0 || size <= 0)
	{
		isDelete = true;
	}
}

//　描画
void CParticle::Draw(ColorF color, bool texture_add)
{
	if (texture_add)
	{
		Sphere(pos, size).draw(color.setAlpha(alpha), *CResource::GetInstance().GetAddRenderer());
	}
	else
	{
		Sphere(pos, size).draw(color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
	}
}

//　描画
void CParticle::Draw(Texture texture,ColorF color)
{
	Billboard(size, pos).draw(texture, color.setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}


//　描画
void CParticle::Draw2D(Texture texture, ColorF color)
{
	texture.resize(size, size).draw(Float2(pos.x, pos.y), color.setAlpha(alpha));
}
