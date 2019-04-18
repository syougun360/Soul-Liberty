#include "Scene.h"
#include "GameApplication.h"
#include "InputNameEvent.h"

CSceneManager::CSceneManager(CGameApplication *app) :
app(app),
isFade(false)
{
	state = State::Init;
}

//　次のシーンに行かせる処理
void CSceneManager::ChangeScene(Scene next_scene)
{
	if (isFade) return;

	this->next_scene = app->SceneFind(next_scene);
	isFade = true;
	alpha = 0.0;
}

///	名前を書き込む
void CSceneManager::NameWrite(String& name_str)
{
	auto name_input = app->SceneFind(Scene::NameInput);
	name_str = std::dynamic_pointer_cast<CInputNameEvent>(name_input)->GetName();
}

void CSceneManager::FadeOut()
{
	if (!isFade) return;

	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(0, 0, 0, alpha));
	alpha += 0.03;
	if (alpha >= 1)
	{
		state = State::Init;
	}
}

void CSceneManager::SceneInit()
{
	if (state != State::Init) return;

	isFade = false;
	scene = next_scene;
	scene->Init();
	state = State::Update;
}
void CSceneManager::SceneUpdate()
{
	if (state != State::Update) return;

	scene->Update();
	FadeOut();
}
//　シーン管理のアップデート
void CSceneManager::Update()
{
	SceneInit();
	SceneUpdate();

}
