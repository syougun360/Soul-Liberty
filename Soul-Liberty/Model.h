
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

class CModel
{
public:
	CModel(const String modelfile,const String texfile = L" ");

	enum class Mode
	{
		TextureNormal,
		TextureAlpha,
		Material,
	};

	///	描画
	void Draw(const Float3 pos, const Float3 size, const Float3 rota, Mode mode, double alpha = 1.0);
	
private:
	Model *model;	///<	モデル
	Texture *texture;	///<	テクスチャ
};

