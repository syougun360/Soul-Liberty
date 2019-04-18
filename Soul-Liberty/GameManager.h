
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "Scene.h"

class CGameStage;
class CGameObjectHousing;

class CGameManager:public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

	static const float Gravity;

	enum class Stage
	{
		Boneyard,
		Castle,
	};
private:
	//	Monster�̂��ׂČĂяo����悤�ɂ���
	void MonsterAllCallToEnable();

	//	���̃X�e�[�W�ɍs��
	void NextStage();

	//	�X�e�[�W��ݒ�
	void SetStage();

	//	�X�e�[�W�̏�����
	void InitStage();

	//	�e�X�e�[�W�̃C�x���g����
	void Event();

	//	�^�X�N�̃A�b�v�f�[�g
	void UpdateTask();

	//	�X�e�[�W�I������
	void StageFinish();
	
	//	�Q�[���I������
	void GameFinish();

	//	�t�F�[�h�A�E�g
	void FadeOut();

	//	�t�F�[�h�C��
	void FadeIn();

	//	�v���C���[�����񂾂Ƃ��Ɉڂ肤��V�[��
	void PlayerDeath();

	///<	���
	enum class State
	{
		Init,	///<	������
		Event,	///<	�C�x���g
		FadeIn,	///<	�t�F�[�h�C��
		Update,	///<	�A�b�v�f�[�g
		FadeOut,	///<	�t�F�[�h�A�E�g
	};


	Stage stage;
	State state;	///<	���
	double alpha;
	std::unique_ptr<CGameStage> game_stage;
	std::unique_ptr<CGameObjectHousing> game_object;

};
