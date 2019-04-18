#include "WeaponAttack.h"
#include "WeaponSoldier.h"
#include "Utility.h"

CWeaponAttack::CWeaponAttack(const int power, const float jumpforce, const float mass, const float speed) :
CEnemyAttack(power, mass, jumpforce, speed)
{
}

void CWeaponAttack::Init(CEnemyActor *enemy)
{
	enemy = nullptr;
	state = State::Appearance;
	count = 0;
}

void CWeaponAttack::Update(CEnemyActor *enemy)
{
	Appearance(enemy);
	Move(enemy);

	for (auto& smoke : smokes)
	{
		smoke->Update();
		smoke->Draw();
	}

	Erase_if(smokes, [](std::unique_ptr<CFootSmoke>& smoke)
	{
		return smoke->GetDelete();
	});

	if (utility::Distance(enemy->transform.GetPos().x, enemy->GetPlayerPos().x) >= 600)
	{
		Init(enemy);
	}
}

//	ˆÚ“®ˆ—
void CWeaponAttack::Move(CEnemyActor *enemy)
{
	if (state != State::Move) return;

	velocity.x *= 0.95f;
	enemy->transform.Translate(Float3(velocity.x, 0, 0));
	if (utility::IsInclude<float>(velocity.x,1,2))
	{
		Init(enemy);
	}
}

//	“oêˆ—
void CWeaponAttack::Appearance(CEnemyActor *enemy)
{
	if (state != State::Appearance) return;

	auto enemy_pos = enemy->transform.GetPos();
	auto enemy_scale = enemy->transform.GetScale();
	smokes.push_back(std::make_unique<CFootSmoke>(enemy_pos + Float3(-enemy->GetDirection() * enemy_scale.x / 2, -enemy_scale.y / 2, 0),
		Float3(-enemy->GetDirection() * Random(1.0f, 6.0f), Random(0.0f, 5.0f), 0)));
	
	count++;
	if (count >= 60)
	{
		dynamic_cast<CWeaponSoldier*>(enemy)->StartAttack();
		velocity = Float3(enemy->GetDirection() * 20, 0, 0);
		state = State::Move;
	}
}
