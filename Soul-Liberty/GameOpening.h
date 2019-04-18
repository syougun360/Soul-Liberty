
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.22
*
*/
#pragma once
#include "Scene.h"
#include "SubScene.h"
#include <map>

class CFloor;

class CGameOpening:public CScene
{
public:
	CGameOpening(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

	enum class Scene
	{
		Fixing,
		Recovery,
		End,
	};

	static const Float3 TombstonePos;
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

	std::shared_ptr<CSubScene<CGameOpening::Scene> > scene;		///<	�V�[���̃C���X�^���X
	std::shared_ptr<CSubScene<CGameOpening::Scene> > next_scene;	///<	�V�[���̃C���X�^���X

	std::map<Scene, std::shared_ptr<CSubScene<CGameOpening::Scene> >> scene_table;

	std::vector<std::unique_ptr<CFloor>> floors;

	State state;	///<	�V�[���Ǘ��̏��
	float radius;	///<	�t�F�[�h�A�E�g�p�̕ϐ�
	bool isFade;	///<	�t�F�[�h�A�E�g�t���O

	String name_str;
	Font* name_font;
};


typedef CSubScene<CGameOpening::Scene> OpeningScene;