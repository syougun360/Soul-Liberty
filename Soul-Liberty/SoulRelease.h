#pragma once
#include "SoulParticle.h"

class CSoulRelease
{
public:
	CSoulRelease(std::shared_ptr<CPlayer> player, Float3 pos, Float2 monster_ui_pos,int point, Palette color);

	void Update();
	void Draw();

	//	íœ‚©‚Ç‚¤‚©
	bool GetDelete()const;

	//	‹zû‚Ì‚ ‚½‚è”»’è
	bool IsAbsorptionCollision();
private:
	//	w’è‚µ‚½ˆÊ’u‚ÉˆÚ“®
	void MoveTo();

	Float2 monster_ui_pos;
	std::shared_ptr<CPlayer> player;
	std::vector<std::unique_ptr<CSoulParticle>> particles;
};

