
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <siv3D.hpp>
#include "Noncopyable.h"

class CSceneManager;
class CGameApplication;

// �V�[���̊��N���X
class CScene :private Noncopyable
{
public:
	CScene(std::shared_ptr<CSceneManager> scene) :app_scene(scene){}
	virtual ~CScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;

protected:
	std::shared_ptr<CSceneManager> app_scene;	///<	�V�[���Ǘ�

private:


};

//�@�V�[���Ǘ�
class CSceneManager :private Noncopyable
{
public:
	enum class Scene;

	CSceneManager(CGameApplication* app);

	void Update();

	//�@���̃V�[���ɍs�����鏈��
	void ChangeScene(Scene next_scene);

	///	�V�[��
	enum class Scene
	{
		Title,			///<	�^�C�g��
		Help,			///<	�w���v
		NameInput,		///<	���O����
		Prologue,		///<	�v�����[�O
		GameOpening,	///<	Opening
		Game,			///<	�Q�[��
		Clear,			///<	�N���A
		EndRoll,		///<	�G���h���[��
	};

	///	���O����������
	void NameWrite(String& name_str);

private:
	///	�t�F�[�h�A�E�g
	void FadeOut();

	///	�V�[���̏�����
	void SceneInit();

	///	�V�[���̃A�b�v�f�[�g
	void SceneUpdate();

	//�@�V�[���Ǘ��̏��
	enum class State
	{
		Init,	///<	������
		Update,	///<	�A�b�v�f�[�g����
	};

	std::shared_ptr<CScene> scene;		///<	�V�[���̃C���X�^���X
	std::shared_ptr<CScene> next_scene;	///<	�V�[���̃C���X�^���X
	std::shared_ptr<CGameApplication> app;	///<	�A�v���P�[�V����

	State state;	///<	�V�[���Ǘ��̏��
	double alpha;	///<	�t�F�[�h�A�E�g�p�̕ϐ�
	bool isFade;	///<	�t�F�[�h�A�E�g�t���O
};

