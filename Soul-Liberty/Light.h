
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>
#include "Transform.h"

///	���C�g�N���X
class CLight :public Transform
{
public:
	enum class Type;
	CLight(int id, Type type, Float3 pos, float radius = 100, ColorF color = { 1, 1, 1 });

	void Update();

	///	�^�C�v
	enum class Type
	{
		Directional,	///<	�f�B���N�V���i��
		Point,			///<	�|�C���g
	};

	ColorF GetColor()const{ return color; }
	void SetColor(ColorF value){ color = value; }

private:
	///	�f�B���N�V���i������
	void Directional();

	///	�|�C���g����
	void Point();

	ColorF color;	///<	�J���[
	float radius;	///<	���a	
	Type type;		///<	�^�C�v
	int id;			///<	ID
};

