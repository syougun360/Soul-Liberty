
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Noncopyable.h"
#include "Scene.h"
#include "FPS.h"
#include <map>

///	�Q�[���A�v���P�[�V����
class CGameApplication :private Noncopyable
{
public:
	CGameApplication();

	///	�A�b�v�f�[�g
	void Update();

	static const int ScreenWidth;
	static const int ScreenHeight;

	std::shared_ptr<CScene> SceneFind(CSceneManager::Scene scene);
private:
	std::map<CSceneManager::Scene, std::shared_ptr<CScene>> scene;	///<	�V�[�����
	std::shared_ptr<CSceneManager> scene_manager;	///<	�V�[���Ǘ�
	std::unique_ptr<CFPS> fps;	///<	�t���[�����[�g
};

