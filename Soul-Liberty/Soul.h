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

	//	初期化
	void Init();

	void Update();

	///	使用
	void Use();

	///	吸収
	void Absorption();

	///	放出
	void CreateRelease(Float3 pos, Float2 monster_ui_pos, const int point);

	///	描画
	void Draw();

	///	最大に吸収
	void MaxAbsorption();

	///	前回の魂を継続させるための設定
	void Continuation(double point){ now_point = this->point = point; }

	//	自動で魂を吸収
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

	///	放出した魂を削除
	void ReleaseDelete();

	///	使用アップデート
	void UseUpdate();

	///	吸収アップデート
	void AbsorptionUpdate();

	///	放出アップデート
	void ReleaseUpdate();

	//	吸収SE再生
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

