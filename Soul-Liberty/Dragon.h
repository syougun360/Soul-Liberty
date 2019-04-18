/**
*
*	@author	yamada masamitsu
*	@date	2014.11.30
*
*/

#pragma once
#include "BossActor.h"

class CBossAttackState;
class CKing;

//	ƒhƒ‰ƒSƒ“
class CDragon:public CBossActor
{
public:
	CDragon(std::shared_ptr<CTask> task, Float3 pos);

	void Update();
	void Draw();

private:

	//	UŒ‚í—Ş
	enum class AttackType
	{
		Flame,
		Breath,
		FlyBreath,
		MaxType,
	};

	//	Character•`‰æ
	void CharacterDraw();

	//	‘Ì—Íˆ—
	void HitPoint(const int power);

	//	UŒ‚€”õ
	void AttackPreparation();

	//	UŒ‚I—¹ˆ—
	void AttackFinish();

	//	UŒ‚í—Ş‚ğİ’è
	void SetAttackType();

	//	ƒ_ƒ[ƒWˆ—
	void Damage(const int power);

	//	UŒ‚
	void Attack();

	//	€–Sˆ—
	void Death();

	std::map<AttackType, std::shared_ptr<CBossAttackState>> attack_table;
	std::shared_ptr<CBossAttackState> attack;
	AttackType attack_type;
	std::unique_ptr<CKing> king;
	int death_count;
};

