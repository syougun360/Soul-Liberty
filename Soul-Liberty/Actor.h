
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Object.h"

class CTask;

//	�A�N�^�[�N���X
class CActor :public Object
{
	std::vector<std::shared_ptr<CActor>> actor;
protected:
	bool isDelete;					///<	�������邩�𒲂ׂ�
	std::shared_ptr<CTask> task;	///<	�^�X�N
	INIReader ini;

public:
	CActor() :isDelete(false){}
	CActor(std::shared_ptr<CTask> task, Transform transform, State state, String ini_filepath) :
		task(task), Object(transform, state), isDelete(false), ini(ini_filepath)
	{

	}
	CActor(std::shared_ptr<CTask> task) :
		task(task), Object(Transform(Float3(0, 0, 0),Float3(0, 0, 0), Float3(0, 0, 0)), State::Live), isDelete(false){}
	
	virtual ~CActor() = default;

	//	-----------------------------
	//	INI�f�[�^���A�b�v�f�[�g
	//	-----------------------------
	virtual void IniDataList();

	//	-------------------------------
	//	�폜
	//	------------------------------
	void Delete(){ isDelete = true; }

	// ------------------------------
	//�@�I�u�W�F�N�g������
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//�@�I�u�W�F�N�g����ɂ���
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//�@��������
	// ------------------------------
	void Remove();

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

	//	---------------------------------
	//	INI�f�[�^���㏑�����ꂽ���ǂ���
	//	--------------------------------
	bool IsIniChanged();

	// ------------------------------------------
	// �I�u�W�F�N�g���擾����
	// -----------------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------------------------------
	//�@�������g���擾����
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }


	// ------------------------------------------
	// �I�u�W�F�N�g�̐����擾
	// -----------------------------------------
	int GetNum()const{ return actor.size(); }

	// ---------------------------------------------------------------
	//	�_�C�i�~�b�N�L���X�g
	//	for(auto&)�͊�{���N���XCActor�̗v�f�����擾�ł��Ȃ����A
	//	������g�p����Ɣh���N���X�̗v�f�܂Ŏ擾�ł���
	// ----------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}

private:

};

