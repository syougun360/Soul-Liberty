#include "OpeningSoulFixing.h"
#include "Resource.h"
#include "OpeningCamera.h"
#include "OpeningSoul.h"
#include "GameApplication.h"


COpeningSoulFixing::COpeningSoulFixing():
OpeningScene(CGameOpening::Scene::Recovery),
soul(std::make_unique<COpeningSoul>(CGameOpening::TombstonePos)),
camera(std::make_unique<COpeningCamera>()),
light(std::make_unique<CLight>(0, CLight::Type::Point, Float3(0, 200, -500), 2000.0f, ColorF(2, 2, 2)))
{
}

void COpeningSoulFixing::Update()
{
	camera->Update();
	light->Update();
	soul->Update();

	if (soul->IsHit())
	{
		NextScene(0);
	}
}

void COpeningSoulFixing::Draw()
{
	soul->Draw();

}