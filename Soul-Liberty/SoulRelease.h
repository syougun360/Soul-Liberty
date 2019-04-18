#pragma once
#include "SoulParticle.h"

class CSoulRelease
{
public:
	CSoulRelease(std::shared_ptr<CPlayer> player, Float3 pos, Float2 monster_ui_pos,int point, Palette color);

	void Update();
	void Draw();

	//	�폜���ǂ���
	bool GetDelete()const;

	//	�z���̂����蔻��
	bool IsAbsorptionCollision();
private:
	//	�w�肵���ʒu�Ɉړ�
	void MoveTo();

	Float2 monster_ui_pos;
	std::shared_ptr<CPlayer> player;
	std::vector<std::unique_ptr<CSoulParticle>> particles;
};

