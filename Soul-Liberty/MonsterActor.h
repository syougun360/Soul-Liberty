/**
*
*	@author	yamada masamitsu
*	@date	2014.10.02
*
*/

#pragma once
#include <map>
#include "Actor.h"
#include "GraphicAnimation.h"
#include "Soul.h"
#include "MonsterCall.h"
#include "MonsterUI.h"

class CPlayer;
class CEnemyActor;

struct MonsterSoul
{
	MonsterSoul(int point, Palette color) :
	point(point), color(color){}
	int point;
	Palette color;
};

///	Monster
class CMonsterActor :public CActor
{
public:
	CMonsterActor(std::shared_ptr<CTask> task,MonsterUI ui, std::string name, int call_alpha = 255);
	CMonsterActor();
	virtual void Init();
	virtual void Start(std::shared_ptr<CPlayer> player);

	void Init(int hp, MonsterSoul soul);

	///	合体した時の攻撃
	virtual void CombineAttack() = 0;

	//	UI描画
	void UIDraw();

	//	解放するときの生成
	void CreateRelease(Float3 create_pos, Float2 monster_ui_pos, const int point);
	
	//	合体時処理
	void OnCombine();

	//	合体のアップデート
	void CombineUpdate();

	//	呼び出し可能にする
	void EnableToCall();

	///	前回の魂を継続させるための設定
	void ContinuationSoul(double point);
	
	//	自動で魂を吸収
	void AutoSoulAbsorption();

	//	召喚エフェクトアニメーション
	void SummonsEffectAnimation();

	//	召喚アニメーションを設定
	void OnAnimationSummons();

	//	魂の初期化
	void OnInitSoul();

	bool IsExistence();
	bool IsCall();
	bool IsCombine()const{ return isCombine; }
	bool IsCombineable()const;
	bool IsCombineLittle()const;
	double GetSoulPoint()const;
	Palette GetSoulColor()const;
	Float2 GetCallUIPos()const;
	std::string GetName()const{return name; }
	static const float Size;

protected:

	enum class AnimationType
	{
		Move,
		Stop,
		Attack,
		Hit
	};

	//	攻撃時の情報
	virtual void OnAttackInfo() = 0;

	///	攻撃処理
	virtual void Attack() = 0;

	///	攻撃終了処理
	virtual void AttackFinish() = 0;

	//	登場処理
	virtual void Appearance();

	///	死亡処理
	virtual void Death();

	///	ダメージ処理
	virtual void Damage();

	///	移動処理
	virtual void Move();

	///	元の位置を設定
	void SetOriginalPos();

	///	あたり判定
	bool CollisionSphereToEnemy(const Transform& transform);
	bool CollisionAABBToEnemy(const Transform& transform);

	//	召喚エフェクト
	void SummonsEffectDraw();

	//	位置を修正する
	void PositionCorrection();

	///	攻撃スタートするタイミング
	void AttackStartTiming();

	///	体力ゲージ描画
	void HpGageDraw();

	///	制限時間
	void LimitTime();

	///	Characterのみ描画
	void CharaterDraw(Texture textire, Color color);
	void CharaterDraw(Texture textire);

	///	戻るアップデート処理
	void ReturnUpdate();

	void OnAnimation(const AnimationType type);

	///	静的なオブジェクトのあたり判定
	bool CollisionStaticObject(const Transform& transform);

	//	合体攻撃可能かどうか
	bool CanCombineAttack()const;

	bool IsNearToEnemy();

	int max_hp;	///<	最大体力
	int hp;		///<	体力
	int alpha;	///<	アルファ値
	int attack_count;	//	攻撃するカウント
	int call_point;	///<	呼べるポイント
	bool isCombine;	//	合体しているかどうか

	std::shared_ptr<CActor> near_enemy;
	Float3 original_pos;
	Direction direction;	///<	方向
	std::shared_ptr<CPlayer> player;

	std::unique_ptr<CGraphicAnimation<AnimationType>> animation;
	std::unique_ptr<CGraphicAnimation<CResource::MonsterUIType>> summons_anim;

	std::unique_ptr<CSoul> soul;
	std::unique_ptr<CMonsterCall> call;

private:
	///	通常ゲージの描画
	void NormalGaugeDraw();

	///	最大ゲージの描画
	void MaxGaugeDraw();

	///	GaussがかかったUI
	void GaussUI();

	///	アルファ値処理
	void AlphaUpdate();

	///	方向を変更する
	void ChangeDirection();

	//	ゲージサークル描画
	void GaugeCircleDraw();

	bool IsNearToWeaponEnemy();
	bool IsNearToMagicEnemy();
	bool IsNearToSlimeEnemy();
	bool IsNearToBoss();

	//	敵との衝突判定
	bool CollisionSphereToSlimeEnemy(const Transform &transform);
	bool CollisionAABBToSlimeEnemy(const Transform &transform);
	bool CollisionSphereToWeaponEnemy(const Transform &transform);
	bool CollisionAABBToWeaponEnemy(const Transform &transform);
	bool CollisionSphereToMagicEnemy(const Transform &transform);
	bool CollisionAABBToMagicEnemy(const Transform &transform);
	bool CollisionSphereToBoss(const Transform &transform);
	bool CollisionAABBToBoss(const Transform &transform);

	float acceleration;
	std::string name;
	Point ui_pos;
	Mesh left;
	Mesh right;
	Mesh left_back;
	Mesh right_back;
	struct UI_CircleAngle
	{
		UI_CircleAngle() :left(0), right(0){}
		double left, right;
	};
	UI_CircleAngle gauge_angle;
};
