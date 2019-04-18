#pragma once
#include <siv3D.hpp>
#include <vector>
#include "SoulRelease.h"
#include "Noncopyable.h"

class CPlayer;

class CSoul :private Noncopyable
{
public:
	CSoul(double max_point, Palette color);

	void Start(std::shared_ptr<CPlayer> player);

	//	������
	void Init();

	void Update();

	///	�g�p
	void Use();

	///	�z��
	void Absorption();

	///	���o
	void CreateRelease(Float3 pos, Float2 monster_ui_pos, const int point);

	///	�`��
	void Draw();

	///	�ő�ɋz��
	void MaxAbsorption();

	///	�O��̍����p�������邽�߂̐ݒ�
	void Continuation(double point){ now_point = this->point = point; }

	//	�����ō����z��
	void AutoAbsorption();

	enum class State
	{
		None,
		Use,
		Absorption,
	};
	double GetPoint()const{ return point; }
	const double GetMaxPoint()const{ return max_point; }
	Palette GetColor()const{ return color; }
	bool IsMaxGauge()const{ return (point >= max_point); }
	State GetState()const{ return state; }
private:

	///	���o���������폜
	void ReleaseDelete();

	///	�g�p�A�b�v�f�[�g
	void UseUpdate();

	///	�z���A�b�v�f�[�g
	void AbsorptionUpdate();

	///	���o�A�b�v�f�[�g
	void ReleaseUpdate();

	//	�z��SE�Đ�
	void AbsorptionPlaySE();

	double point;
	double now_point;
	Point pos;
	Point size;
	Palette color;
	const double max_point;
	std::shared_ptr<CPlayer> player;
	std::vector<std::unique_ptr<CSoulRelease>> release;

	State state;
};

