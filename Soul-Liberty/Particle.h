
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

///	パーティクルシステム
class CParticleSystem
{
public:
	enum class Mode;
	CParticleSystem(Mode mode, Float3 pos, float radius, CParticleScale scale,
		CParticleVelocity speed, CParticleDuration duration, int num = 1);
	
	//	全回しアップデート
	void Update();

	//	子を生成
	void CreateChildren();

	//	削除
	void Remove();

	//	子をアップデート
	void ChildrenUpdate();

	//	描画
	void Draw(ColorF color = Palette::White, bool texture_add = true);
	void Draw(Texture texture, ColorF color = Palette::White);
	void Draw2D(Texture texture, ColorF color = Palette::White);

	enum class Mode
	{
		Individual,	//　常に個々で出す
		Burst,		//　一気に出す
		Color_Individual,	//　色がランダムに決まってここで出す
	};

	void TransformNum(const int num){ this->num = num; }
	void TransformPoint(Float3 value){ pos = value; }
	void Transformlate(Float3 value){ pos += value; }

	//　生成するかどうかを設定する
	void SetCreate(bool type){ isCreate = type; }

	void TransformVelocity(const CParticleVelocity& velocity);

	void MoveTo(const Float3 pos, const float speed);

	Float3 GetPos()const{ return pos; }

	//　現在出ている個数を取得
	int GetNum()const{ return particles.size(); }

	bool IsCreate()const{ return isCreate; }

	bool IsEmpty()const{ return (particles.size() == 0); }
private:
	void CreateUpdate();
	std::vector<std::unique_ptr<CParticle>> particles;
	Mode mode;		///<	モード
	Float3 pos;		///<	座標
	CParticleVelocity speed;	///<	速度
	CParticleScale scale;		///<	大きさ	
	CParticleDuration duration;	///<	存続時間
	float radius;	///<	半径
	int num;		///<	数
	bool isCreate;	///<	生成するかどうか
};

///	パーティクル（粒）
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
