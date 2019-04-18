#include "Actor.h"

// ------------------------------
//�@�I�u�W�F�N�g������
// ------------------------------
void CActor::Append(std::shared_ptr<CActor> obj)
{
	assert(obj);
	actor.emplace_back(obj);
}

//	-----------------------------
//	INI�f�[�^���A�b�v�f�[�g
//	-----------------------------
void CActor::IniDataList()
{
	for (auto& obj : actor)
	{
		obj->IniDataList();
	}
}

//	---------------------------------
//	INI�f�[�^���㏑�����ꂽ���ǂ���
//	--------------------------------
bool CActor::IsIniChanged()
{
	if (ini.hasChanged())
	{
		ini.reload();
		return true;
	}

	return false;
}

// ------------------------------
//�@��������
// ------------------------------
void CActor::Remove()
{
	Erase_if(actor, [](std::shared_ptr<CActor> &obj)
	{
		return obj->isDelete;
	});
}

// ----------------------------------
//�@�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
// ----------------------------------
void CActor::Start()
{
	for (auto& obj : actor)
	{
		obj->Start();
	}

}

// ------------------------------
//�@�A�b�v�f�[�g
// ------------------------------
void CActor::Update()
{
	for (auto& obj : actor)
	{
		obj->Update();
	}
}

// ------------------------------
//�@�`��
// ------------------------------
void CActor::Draw()
{
	for (auto& obj : actor)
	{
		obj->Draw();
	}
}

// ------------------------------
//�@�I������
// ------------------------------
void CActor::Finish()
{
	for (auto& obj : actor)
	{
		obj->Finish();
	}
}


// ------------------------------------------
// �I�u�W�F�N�g���擾����
// -----------------------------------------
std::shared_ptr<Object> CActor::GetComponent(const int id)const
{
	if (actor.empty()) return nullptr;

	assert(id >= 0);
	assert(id <= (int)actor.size() -1);
	return actor[id];
}
