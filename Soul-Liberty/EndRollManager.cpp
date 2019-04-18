#include "EndRollManager.h"
#include "GameApplication.h"
#include "Resource.h"

const int MaxTexture = 13;

CEndRollManager::CEndRollManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager)
{

}

void CEndRollManager::Init()
{
	index = 0;
	index2 = 1;
	count = 0;
	alpha = 255;
	alpha2 = 0;
	state = State::Update;
}

void CEndRollManager::FadeOut()
{
	if (state != State::Fade) return;

	alpha -= 5;
	alpha2 += 5;
	if (alpha <= 0)
	{
		index++;
		index2++;
		index2 = (index2 >= MaxTexture) ? index : index2;
		alpha = 255;
		alpha2 = 0;
		state = State::Update;
	}
}

void CEndRollManager::ChangeIndex()
{
	if (state != State::Update) return;

	count++;
	if (count >= 30)
	{
		state = State::Fade;
		count = 0;
	}
	if (index >= MaxTexture)
	{
		index = MaxTexture-1;
		index2 = index;
		app_scene->ChangeScene(CSceneManager::Scene::Title);
		CResource::GetInstance().FadeStartBGM();
		state = State::End;
	}
}
void CEndRollManager::Update()
{
	Draw();
	FadeOut();
	ChangeIndex();
}

void CEndRollManager::Draw()
{
	Texture table[MaxTexture] =
	{
		TextureAsset(CResource::GetInstance().GetTitleGraphic(CResource::TitleGraphicType::TitleLogo)),
		TextureAsset(CResource::GetInstance().GetTitleGraphic(CResource::TitleGraphicType::BackGround)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::BackGroundBoneyard)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::BackGroundCastle)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Castle)),
		TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::MobPeople)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::EndrollMonster)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::EndrollMonster2)),
		TextureAsset(CResource::GetInstance().GetBossDragon(5)),
		TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::Devil)),
		TextureAsset(CResource::GetInstance().GetPrologue(CResource::PrologueGraphicType::EnemyMobPeople)),
		TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Castle2)),
		TextureAsset(CResource::GetInstance().GetTitleGraphic(CResource::TitleGraphicType::TitleLogo)),
	};
	const Float2 Size = Float2(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight);
	const Float2 Pos = Float2(0, 0);
	table[index].resize(Size).draw(Pos, Alpha(alpha));
	table[index2].resize(Size).draw(Pos, Alpha(alpha2));

}
