
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>
#include "Noncopyable.h"
#include "Transform.h"


class Object :private Noncopyable
{
public:
	enum class State;
	Object() :transform(Float3(0, 0, 0), Float3(0, 0, 0), Float3(0, 0, 0)){}
	Object(Transform transform,State state) :
		transform(transform), state(state){}
	virtual ~Object() = default;

	// Updateの前に呼ばれるもの
	virtual void Start(){};

	// アップデート
	virtual void Update(){};

	//　描画
	virtual void Draw() {};

	//　描画
	virtual void Finish() {};


	enum class State
	{
		None,		//　存在しない
		Start,		//	スタート
		Live,		//　存在する
		Appearance,	//	登場
		Move,		//　移動
		AttackPreparation,	//	攻撃準備
		Attack,		//　攻撃動作
		Hit,		//　ヒット
		Death,		//	死亡
		Return,		//	戻る
		BossInFiled,	//	ボスのフィールドに入った
		Call,	//	召喚
	};

	///	方向
	enum Direction
	{
		Left = -1,	///	左向き
		Right = 1,	///	右向き
	};

	State GetState()const{ return state; }

	Transform transform;

protected:
	State state;	///<	状態
	
};