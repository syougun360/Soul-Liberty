/**
*
*	@author	yamada masamitsu
*	@date	2014.11.06
*
*/
#pragma once
#include "EnemyActor.h"
#include "Resource.h"
#include "EnemyHitAction.h"

class CPlayer;
class CSlimeAttack;

class CSlimeActor :public CEnemyActor
{
public:
	enum class ScaleType
	{
		Small = 1,
		Big = 2,
	};
	CSlimeActor(std::shared_ptr<CTask> task, Transform transform, ScaleType scale_type, CResource::MonsterUIType soul_type);

protected:
	void CharacterDraw(CResource::SlimeType texture_type);
	void CollisionFloor();
	void ChangeDirection();
private:
	ScaleType scale_type;

};

