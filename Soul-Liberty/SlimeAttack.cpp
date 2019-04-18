#include "SlimeAttack.h"
#include "EnemyActor.h"

CSlimeAttack::CSlimeAttack(const int power, const float jumpforce, const float mass, const float speed) :
CEnemyAttack(power, jumpforce, mass, speed)
{
}


void CSlimeAttack::Init(CEnemyActor *actor)
{
	actor = nullptr;
	force = jumpforce;
}

void CSlimeAttack::Update(CEnemyActor *actor)
{
	force -= mass;
	actor->transform.Translate(Float3(actor->GetDirection() * speed, force, 0));
}