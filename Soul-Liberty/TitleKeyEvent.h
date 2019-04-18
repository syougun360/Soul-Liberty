
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <memory>
#include "Scene.h"

class CTitleManager;

///	�^�C�g���L�[�C�x���g
class CTitleKeyEvent
{
public:

	///	������
	void Init(CTitleManager *title);

	///	�V�[����ύX
	void ChangeSceneMenu(std::shared_ptr<CSceneManager> scene);

	///	�A�b�v�f�[�g
	void Update(CTitleManager *title);

	CSceneManager::Scene GetSelectNowScene()const{ return select_scene; }
private:
	///	�I���V�[��
	void SelectScene(CTitleManager *title);
	
	///	�L�[����������
	void PushKey();

	std::shared_ptr<CSceneManager> scene;	///<	�V�[���Ǘ�
	CSceneManager::Scene select_scene;		///<	�I���V�[��
	bool push_key;	///<	���������ǂ����H
};

