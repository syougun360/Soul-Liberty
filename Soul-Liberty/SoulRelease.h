#pragma once
#include "SoulParticle.h"

class CSoulRelease
{
public:
	CSoulRelease(std::shared_ptr<CPlayer> player, Float3 pos, Float2 monster_ui_pos,int point, Palette color);

	void Update();
	void Draw();

	//	削除かどうか
	bool GetDelete()const;

	//	吸収のあたり判定
	bool IsAbsorptionCollision();
private:
	//	指定した位置に移動
	void MoveTo();

	Float2 monster_ui_pos;
	std::shared_ptr<CPlayer> player;
	std::vector<std::unique_ptr<CSoulParticle>> particles;
};

