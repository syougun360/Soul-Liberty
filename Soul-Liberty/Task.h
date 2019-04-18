
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <unordered_map>
#include <string> 
#include <memory>
#include <cassert>
#include "Noncopyable.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//	�y�^�X�N�̎g�p���@�z
//	
//�@�E�܂��^�X�N�̃C���X�^���X��錾������
//	
//	�E�C���X�^���X�̏�����
//	
//	�ETask��Start(),Update(),Draw(),Remove()�̏����ꏊ
//	�Q�[���Ǘ��N���X�̃R���X�g���N�^�̈�ԉ���Task->Start();������
//	�Q�[���Ǘ��N���X��Update�֐��̒���
//	Task->Update();
//	Task->Draw();
//	Tadk->Remove();
//	���̏��ŏ����Ă�������!
//	����œo�^�����I�u�W�F�N�g�͂��ׂď��������悤�ɂȂ�܂�!
//	
//
//	�E�^�X�N�ɓo�^����܂ł̎菇

//	�@	�X�}�[�g�|�C���^��Instance��錾,������
//	
//	�A	�A�N�^�[�ɃI�u�W�F�N�g�̏�����ꍞ��
//	
//	�B	�I�u�W�F�N�g���^�X�N�ɓ����
//	Task->Append("�o�^��", �o�^����I�u�W�F�N�g(�C���X�^���X));
//	��jTask->Append("Player",Player);
//	
//	�E���ӓ_
//	�o�^���ĂȂ����O�͕K���G���[���o��I
//�@�K���o�^�������O���o���Ă����I
//	�o�^�������ȏ�̂��̂��擾���Ȃ��悤�ɂ��Ă��������I
//�@
//	�E�o�^�����I�u�W�F�N�g�𑼂̏��Ŏ擾�������ꍇ
//	Task->GetComponent<�擾�������N���X��>(�o�^�������O, �o�^�����ԍ�);
//	��jTask->GetComponent<CPlayer>("Player", 0);
//	
//�@�E�o�^�����v�f�����ׂĎ擾�������ꍇ
//	Task->GetComponent<�擾�������N���X��>(�o�^�������O);
//	��jTask->GetComponent<CEnemy>("Enemy");
//
//	�E�o�^�����v�f�̐����擾����
//	Task->GetNum(�o�^�������O);
//	��jTask->GetNum("Enemy");
//	
//	�Efor(auto&)�Ń^�X�N�̗v�f���g�����@
//	��{�I�Ɋ��N���XObject�̃N���X�ɓ����Ă���v�f�����擾�ł��Ȃ�
//	��jfor(auto& obj : Task->GetActor(�o�^��))
//	{
//		obj->���\�b�h(�֐�) or �ϐ�;
//	}
//	
//�@�h���N���X�̗v�f���擾�������ꍇ
//	DynamicCast<�擾�������N���X��>(�v�f);
//	��jfor(auto& obj : Task->GetActor(�o�^��))
//	{
//		DynamicCast<�N���X��>(obj)->���\�b�h(�֐�) or �ϐ�;
//	}
//	
//	�E�^�X�N�ɓo�^�����I�u�W�F�N�g�̓������̉���͂��Ȃ��Ă悢�I
//	�E�o�^�����I�u�W�F�N�g��r���ō폜�������ꍇ�́AisDelete ��true�ɂ���Ύ��̃t���[���ō폜�����
//�@
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CActor;

class CTask 
{
	std::unordered_map<std::string, std::shared_ptr<CActor>> object;
public:

	// ------------------------------
	//�@Actor������
	// ------------------------------
	void Append(std::string name, std::shared_ptr<CActor> actor);

	// ------------------------------
	//�@Actor����ɂ���
	// ------------------------------
	void Clear();
	
	// ------------------------------
	//�@�^�X�N�����������
	// ------------------------------
	void Remove();

	// ------------------------------
	//�@ini�f�[�^�A�b�v�f�[�g
	// ------------------------------
	void IniDataUpdate();

	// ------------------------------
	//�@ini�f�[�^���X�g
	// ------------------------------
	void IniDataList();

	// ----------------------------------
	//�@�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
	// ----------------------------------
	void Start();
	
	// ------------------------------
	//�@�A�b�v�f�[�g
	// ------------------------------
	void Update();
	
	// ------------------------------
	//�@�`��
	// ------------------------------
	void Draw();

	// ------------------------------
	//�@�I������
	// ------------------------------
	void Finish();

	// ------------------------------------------------------
	// �I�u�W�F�N�g���擾����iID�܂Ŏ擾�ł���j
	// ------------------------------------------------------
	template<typename OBJ>
	std::shared_ptr<OBJ> GetComponent(const std::string& name, const int Id)
	{
		auto it = object.find(name);
		return std::dynamic_pointer_cast<OBJ>(it->second->GetComponent(Id));
	}

	// -------------------------------------------------------------
	// �I�u�W�F�N�g���擾����iActor�̒��ɂ���N���X�̑S�̂��擾�j
	// -------------------------------------------------------------
	std::shared_ptr<CActor>  GetComponents(const std::string& name);

	// ------------------------------------------------------
	//�@�A�N�^�[���̂��擾����
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor(const std::string& name);

	// ------------------------------------------
	// �I�u�W�F�N�g�̐����擾
	// -----------------------------------------
	int GetNum(const std::string& name);
};
