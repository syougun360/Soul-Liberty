#include "WaterParticle.h"
#include "Resource.h"

CWaterParticle::CWaterParticle(const Transform transform, const Float3 velocity, int duration) :
transform(transform),
velocity(velocity),
isDelete(false),
alpha(duration)
{
}

void CWaterParticle::Update()
{
	transform.Translate(velocity);

	velocity *= 0.8f;
	alpha -= 3;
	transform.Scaling(Float3(-3.0f, -3.0f, -3.0f));

	if (alpha <= 0 || transform.GetScale().x <= 0)
	{
		isDelete = true;
	}
}


void CWaterParticleSystem::Create(const Float3& pos)
{
	for (int i = 0; i < 30; i++)
	{
		particles.push_back(std::make_unique<CWaterParticle>(Transform(pos, Float3(Random(10, 50), 0, 0), Float3(0, 0, 0)),
			Float3(Random(-10, 10), Random(10, 15), Random(-5, 5)), Random(100, 255)));
	}
}

void CWaterParticleSystem::Update()
{
	for (auto& particle : particles)
	{
		particle->Update();
	}
}

void CWaterParticle::Draw()
{
	if (isDelete) return;
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Particle));
	Billboard(transform.GetScale().x, transform.GetPos()).draw(texture, 
		Color(0,0,200).setAlpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}

void CWaterParticleSystem::Draw()
{
	for (auto& particle : particles)
	{
		particle->Draw();
	}

	Erase_if(particles, [](const std::unique_ptr<CWaterParticle> &it)
	{
		return it->Delete();
	});
}