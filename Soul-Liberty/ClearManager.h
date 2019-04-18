
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once

#include "Scene.h"
#include "SubScene.h"
#include <map>

///	�N���A�Ǘ�
class CClearManager :public CScene
{
public:
	CClearManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	enum class Scene
	{
		Castle,
		Mob,
		End,
	};
private:

	//�@���̃V�[���ɍs�����鏈��
	void ChangeScene();

	///	�t�F�[�h�A�E�g
	void FadeOut();

	///	�V�[���̏�����
	void SceneInit();

	///	�V�[���̃A�b�v�f�[�g
	void SceneUpdate();

	//	�A�v���V�[����ύX
	bool ChangeAppScene();

	//�@�V�[���Ǘ��̏��
	enum class State
	{
		Init,	///<	������
		Update,	///<	�A�b�v�f�[�g����
		End,
	};

	std::shared_ptr<CSubScene<CClearManager::Scene> > scene;		///<	�V�[���̃C���X�^���X
	std::shared_ptr<CSubScene<CClearManager::Scene> > next_scene;	///<	�V�[���̃C���X�^���X

	std::map<Scene, std::shared_ptr<CSubScene<CClearManager::Scene> >> scene_table;

	State state;	///<	�V�[���Ǘ��̏��
	double alpha;	///<	�t�F�[�h�A�E�g�p�̕ϐ�
	bool isFade;	///<	�t�F�[�h�A�E�g�t���O
};

typedef CSubScene<CClearManager::Scene> ClearScene;