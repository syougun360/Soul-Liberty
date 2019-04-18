
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <map>
#include "Scene.h"
#include "SubScene.h"

///	�v�����[�O�Ǘ�
class CPrologueManager :public CScene
{
public:
	CPrologueManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	///	�V�[��
	enum class Scene
	{
		MobPeople,		//	���u�B
		Devil,			//	����
		DevilMagic,		//	���������@��������
		EnemyPeople,	//	�G�B
		End,			//	�I��
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
	};

	std::shared_ptr<CSubScene<CPrologueManager::Scene>> scene;		///<	�V�[���̃C���X�^���X
	std::shared_ptr<CSubScene<CPrologueManager::Scene>> next_scene;	///<	�V�[���̃C���X�^���X
	
	std::map<Scene, std::shared_ptr<CSubScene<CPrologueManager::Scene>>> scene_table;

	State state;	///<	�V�[���Ǘ��̏��
	double alpha;	///<	�t�F�[�h�A�E�g�p�̕ϐ�
	bool isFade;	///<	�t�F�[�h�A�E�g�t���O
};

typedef CSubScene<CPrologueManager::Scene> PrologueScene;