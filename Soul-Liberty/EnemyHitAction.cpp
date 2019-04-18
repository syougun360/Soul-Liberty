#include "EnemyHitAction.h"
#include "EnemyActor.h"
#include "Player.h"

CEnemyHitAction::CEnemyHitAction(const float mass, const float force, const float knock_back) :
velocity(Float3(1, 0, 0)), mass(mass), force(force), knock_back(knock_back)

{

}

void CEnemyHitAction::Init()
{
	velocity = Float3(1, 0, 0);
}

void CEnemyHitAction::Update(CEnemyActor *actor)
{
	velocity.y -= mass;
	velocity.x *= 0.95f;
	actor->transform.Translate(velocity);
}


///	“–‚½‚Á‚½Žž
void CEnemyHitAction::OnHit(std::shared_ptr<CPlayer> player)
{
	velocity.x = player->GetDirection() * ((player->GetAttacPower() / 2) + knock_back);
	velocity.y = force;
}


void CEnemyHitAction::OnDeathVelocity()
{
	velocity = Float3(0, force*3, force);
}