#include "Actor.h"

// ------------------------------
//　オブジェクトを入れる
// ------------------------------
void CActor::Append(std::shared_ptr<CActor> obj)
{
	assert(obj);
	actor.emplace_back(obj);
}

//	-----------------------------
//	INIデータをアップデート
//	-----------------------------
void CActor::IniDataList()
{
	for (auto& obj : actor)
	{
		obj->IniDataList();
	}
}

//	---------------------------------
//	INIデータが上書きされたかどうか
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
//　消去する
// ------------------------------
void CActor::Remove()
{
	Erase_if(actor, [](std::shared_ptr<CActor> &obj)
	{
		return obj->isDelete;
	});
}

// ----------------------------------
//　アップデートの前に呼ばれる処理
// ----------------------------------
void CActor::Start()
{
	for (auto& obj : actor)
	{
		obj->Start();
	}

}

// ------------------------------
//　アップデート
// ------------------------------
void CActor::Update()
{
	for (auto& obj : actor)
	{
		obj->Update();
	}
}

// ------------------------------
//　描画
// ------------------------------
void CActor::Draw()
{
	for (auto& obj : actor)
	{
		obj->Draw();
	}
}

// ------------------------------
//　終了処理
// ------------------------------
void CActor::Finish()
{
	for (auto& obj : actor)
	{
		obj->Finish();
	}
}


// ------------------------------------------
// オブジェクトを取得する
// -----------------------------------------
std::shared_ptr<Object> CActor::GetComponent(const int id)const
{
	if (actor.empty()) return nullptr;

	assert(id >= 0);
	assert(id <= (int)actor.size() -1);
	return actor[id];
}
