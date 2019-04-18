#pragma once
#include "GameOpening.h"
#include "Light.h"

class COpeningCamera;
class COpeningSoul;

class COpeningSoulFixing:public OpeningScene
{
public:
	COpeningSoulFixing();

	void Update();
	void Draw();
private:
	//	カメラをズーム
	void CameraZoom();

	//	カメラを引く
	void CameraPull();

	enum class CameraState
	{
		Zoom,
		Pull,
	};
	CameraState camera_state;
	std::unique_ptr<CLight> light;
	std::unique_ptr<COpeningCamera> camera;
	std::unique_ptr<COpeningSoul> soul;
};

