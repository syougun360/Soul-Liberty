/**
*
*	@author	yamada masamitsu
*	@date	2014.10.07
*
*/

#pragma once
#include "Transform.h"
#include "ParticleMath.h"
#include <vector>
#include <memory>

class CWaterParticle
{
public:
	CWaterParticle(const Transform transform, const Float3 velocity, int duration);

	void Update();
	void Draw();

	bool Delete()const{ return isDelete; }
private:
	Transform transform;
	Float3 velocity;
	int alpha;
	bool isDelete;
};

class CWaterParticleSystem
{
public:

	void Create(const Float3& pos);
	void Update();
	void Draw();
	bool IsEmpty()const{ return particles.empty(); }
private:
	std::vector<std::unique_ptr<CWaterParticle>> particles;

};
