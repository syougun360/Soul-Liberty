#include "PlayerGravity.h"
#include "GameManager.h"
#include "Player.h"
#include "Task.h"

CPlayerGravity::CPlayerGravity():
gravity(0)
{
}

void CPlayerGravity::Update()
{
	if (player->IsGravity())
	{
		gravity = 0;
		return;
	}

	if (!player->IsGravity())
	{
		gravity = CGameManager::Gravity;
	}
}
