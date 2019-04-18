#pragma once
#include <siv3D.hpp>


///	�p�[�e�B�N���X�P�[��
class CParticleScale
{
public:
	CParticleScale(float min, float max) :
		min(min), max(max){}

	float GetMin()const{ return min; }
	float GetMax()const{ return max; }
private:
	float min, max;

};

///	�p�[�e�B�N���ړ���
class CParticleVelocity
{
public:
	CParticleVelocity(Float3 min, Float3 max) :
		min(min), max(max){}

	Float3 GetMin()const{ return min; }
	Float3 GetMax()const{ return max; }

	//�@�ړ��ʂ�ϊ�
	void TransformVelocity(Float3 min, Float3 max){ this->min = min; this->max = max; }

private:
	Float3 min, max;

};

///	�p�[�e�B�N����������
class CParticleDuration
{
public:
	CParticleDuration(int min, int max) :
		min(min), max(max){}

	int GetMin()const{ return min; }
	int GetMax()const{ return max; }

private:
	int min, max;

};
