
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Object.h"

class CTask;

//	アクタークラス
class CActor :public Object
{
	std::vector<std::shared_ptr<CActor>> actor;
protected:
	bool isDelete;					///<	消去するかを調べる
	std::shared_ptr<CTask> task;	///<	タスク
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
	//	INIデータをアップデート
	//	-----------------------------
	virtual void IniDataList();

	//	-------------------------------
	//	削除
	//	------------------------------
	void Delete(){ isDelete = true; }

	// ------------------------------
	//　オブジェクトを入れる
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//　オブジェクトを空にする
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//　消去する
	// ------------------------------
	void Remove();

	// ----------------------------------
	//　アップデートの前に呼ばれる処理
	// ----------------------------------
	void Start();

	// ------------------------------
	//　アップデート
	// ------------------------------
	void Update();

	// ------------------------------
	//　描画
	// ------------------------------
	void Draw();

	// ------------------------------
	//　終了処理
	// ------------------------------
	void Finish();

	//	---------------------------------
	//	INIデータが上書きされたかどうか
	//	--------------------------------
	bool IsIniChanged();

	// ------------------------------------------
	// オブジェクトを取得する
	// -----------------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------------------------------
	//　自分自身を取得する
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }


	// ------------------------------------------
	// オブジェクトの数を取得
	// -----------------------------------------
	int GetNum()const{ return actor.size(); }

	// ---------------------------------------------------------------
	//	ダイナミックキャスト
	//	for(auto&)は基本基底クラスCActorの要素しか取得できないが、
	//	これを使用すると派生クラスの要素まで取得できる
	// ----------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}

private:

};

