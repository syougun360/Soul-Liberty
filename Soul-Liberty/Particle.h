
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>
#include <memory>
#include "ParticleMath.h"

class CParticle;

///	�p�[�e�B�N���V�X�e��
class CParticleSystem
{
public:
	enum class Mode;
	CParticleSystem(Mode mode, Float3 pos, float radius, CParticleScale scale,
		CParticleVelocity speed, CParticleDuration duration, int num = 1);
	
	//	�S�񂵃A�b�v�f�[�g
	void Update();

	//	�q�𐶐�
	void CreateChildren();

	//	�폜
	void Remove();

	//	�q���A�b�v�f�[�g
	void ChildrenUpdate();

	//	�`��
	void Draw(ColorF color = Palette::White, bool texture_add = true);
	void Draw(Texture texture, ColorF color = Palette::White);
	void Draw2D(Texture texture, ColorF color = Palette::White);

	enum class Mode
	{
		Individual,	//�@��ɌX�ŏo��
		Burst,		//�@��C�ɏo��
		Color_Individual,	//�@�F�������_���Ɍ��܂��Ă����ŏo��
	};

	void TransformNum(const int num){ this->num = num; }
	void TransformPoint(Float3 value){ pos = value; }
	void Transformlate(Float3 value){ pos += value; }

	//�@�������邩�ǂ�����ݒ肷��
	void SetCreate(bool type){ isCreate = type; }

	void TransformVelocity(const CParticleVelocity& velocity);

	void MoveTo(const Float3 pos, const float speed);

	Float3 GetPos()const{ return pos; }

	//�@���ݏo�Ă�������擾
	int GetNum()const{ return particles.size(); }

	bool IsCreate()const{ return isCreate; }

	bool IsEmpty()const{ return (particles.size() == 0); }
private:
	void CreateUpdate();
	std::vector<std::unique_ptr<CParticle>> particles;
	Mode mode;		///<	���[�h
	Float3 pos;		///<	���W
	CParticleVelocity speed;	///<	���x
	CParticleScale scale;		///<	�傫��	
	CParticleDuration duration;	///<	��������
	float radius;	///<	���a
	int num;		///<	��
	bool isCreate;	///<	�������邩�ǂ���
};

///	�p�[�e�B�N���i���j
class CParticle
{
public:
	CParticle(Float3 pos, float size, Float3 velocity, int duration);

	void Update();
	void Draw(ColorF color, bool texture_add);
	void Draw(Texture texture, ColorF color);
	void Draw2D(Texture texture, ColorF color);

	bool GetIsDelete()const{ return isDelete; }
	ColorF GetColor()const{ return color; }
	void MoveTo(const Float3 pos, const float speed);
private:
	Float3 pos;
	Float3 velocity;
	float size;
	double alpha;
	int duration;
	int count;
	ColorF color;
	bool isDelete;
};
