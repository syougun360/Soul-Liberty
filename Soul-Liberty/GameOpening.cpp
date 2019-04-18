#include "GameOpening.h"
#include "Resource.h"
#include "GameApplication.h"
#include "Floor.h"
#include "OpeningSoulFixing.h"
#include "OpeningRecovery.h"

const Float3 CGameOpening::TombstonePos = Float3(0, 0, 0);

CGameOpening::CGameOpening(std::shared_ptr<CSceneManager> manager):
CScene(manager),
name_font(new Font(40))
{
}

void CGameOpening::Init()
{
	app_scene->NameWrite(name_str);

	for (int i = -5; i < 10; i++)
	{
		floors.push_back(std::make_unique<CFloor>(Float3(i * 100, -100.0f, 0), CGameManager::Stage::Boneyard));
	}

	scene_table.clear();

	scene_table.insert(std::make_pair(Scene::Fixing, std::make_shared<COpeningSoulFixing>()));
	scene_table.insert(std::make_pair(Scene::Recovery, std::make_shared<COpeningRecovery>()));

	next_scene = scene_table.find(Scene::Fixing)->second;

	isFade = false;
	radius = 0.0;
	state = State::Init;
}


//　次のシーンに行かせる処理
void CGameOpening::ChangeScene()
{
	if (isFade) return;
	if (!scene->IsEnd()) return;
	if (ChangeAppScene()) return;

	this->next_scene = scene_table.find(scene->GetNextScene())->second;
	isFade = true;
	radius = 0.0;
	CResource::GetInstance().PlaySE(CResource::SE::ChangeScene);

}

void CGameOpening::FadeOut()
{
	if (!isFade) return;

	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::ParticleGauss));
	texture.scale(radius).drawAt(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	radius += 0.9f;
	if (radius >= 30)
	{
		state = State::Init;
	}
}

void CGameOpening::SceneInit()
{
	if (state != State::Init) return;

	isFade = false;
	scene = next_scene;
	state = State::Update;
}

bool CGameOpening::ChangeAppScene()
{
	if (scene->GetNextScene() != Scene::End) return false;


	CResource::GetInstance().FadeStartBGM();
	app_scene->ChangeScene(CSceneManager::Scene::Game);
	return true;
}

void CGameOpening::SceneUpdate()
{
	if (state != State::Update) return;

	scene->Update();
	ChangeScene();
}

void CGameOpening::Update()
{
	SceneInit();
	SceneUpdate();
	Draw();
	scene->Draw();
	FadeOut();

}

void CGameOpening::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::BackGroundBoneyard));
	Billboard(Float3(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight, 1),Float3(0,250,100)).draw(texture);

	for (auto& floor : floors)
	{
		floor->Draw();
	}
	
	CResource::GetInstance().GetModel(CResource::ModelType::Tombstone)->Draw(
		TombstonePos, Float3(1, 1, 1), Float3(0, PiF / 180 * 180, 0), CModel::Mode::TextureNormal);

	//	name_font->drawCenter(name_str, TransformNamePos(TombstonePos) + Float2(0,-camera->GetPosZ()/2 + 50), Palette::Black,5);


	Texture name_texture;
	for (unsigned int i = 0; i <= name_str.length; i++)
	{
		auto it = name_str[i];
		auto region_texture = name_font->getTexture(it);
		name_texture = region_texture.texture;
	}

	Billboard(Float3(200, 200, 0.00001f), TombstonePos + Float3(88, -70, -50)).draw(name_texture, ColorF(2, 2, 2), *CResource::GetInstance().GetAlphaRenderer());

}