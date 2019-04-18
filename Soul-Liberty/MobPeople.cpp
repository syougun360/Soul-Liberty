#include "MobPeople.h"
#include "Mob.h"
#include "GameApplication.h"
#include "Resource.h"

const std::string MobName = "mob";
const int NextSceneTime = 3;

CMobPeople::CMobPeople() :
PrologueScene(CPrologueManager::Scene::Devil),
task(std::make_shared<CTask>())
{
	const Float2 MobPos = Float2(100, CGameApplication::ScreenHeight / 2 + 100);
	const float MobSpace = 200;

	auto mob = std::make_shared<CActor>();

	for (int i = 0; i < 6; i++)
	{
		mob->Append(std::make_shared<CMob>(Float3(MobPos.x + MobSpace * i, MobPos.y, 0), i));
	}

	task->Append(MobName, mob);
}

void CMobPeople::MobUpdate()
{
	task->Update();
}
void CMobPeople::Update()
{
	MobUpdate();
	NextScene(NextSceneTime);
}

void CMobPeople::Draw()
{
	auto graph = TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::MobPeople));
	graph.resize(Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)).draw(Float2(0, 0));

	task->Draw();
}