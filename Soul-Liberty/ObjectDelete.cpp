#include "ObjectDelete.h"
#include "Player.h"
#include "Actor.h"
#include "Task.h"
#include "GameManager.h"
#include "EnemyManager.h"

CObjectDelete::CObjectDelete(std::shared_ptr<CTask> task, std::shared_ptr<CPlayer> player, std::vector<std::string> name_table) :
task(task), name_table(name_table), player(player)
{
}

void CObjectDelete::Update()
{
	for (auto& name : name_table)
	{
		for (auto& it : task->GetActor(name))
		{
			IncludeDelete(it);
		}
	}
}

void CObjectDelete::IncludeDelete(std::shared_ptr<CActor> actor)
{
	if (player->GetCameraPos().x - 800 > actor->transform.GetPos().x)
	{
		actor->Delete();
	}
}

