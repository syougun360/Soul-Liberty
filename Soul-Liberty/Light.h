
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>
#include "Transform.h"

///	ライトクラス
class CLight :public Transform
{
public:
	enum class Type;
	CLight(int id, Type type, Float3 pos, float radius = 100, ColorF color = { 1, 1, 1 });

	void Update();

	///	タイプ
	enum class Type
	{
		Directional,	///<	ディレクショナル
		Point,			///<	ポイント
	};

	ColorF GetColor()const{ return color; }
	void SetColor(ColorF value){ color = value; }

private:
	///	ディレクショナル処理
	void Directional();

	///	ポイント処理
	void Point();

	ColorF color;	///<	カラー
	float radius;	///<	半径	
	Type type;		///<	タイプ
	int id;			///<	ID
};

