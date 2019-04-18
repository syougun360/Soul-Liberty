#include "PlayerHpGauge.h"
#include "Resource.h"

float CPlayerHpGauge::max_hp;

CPlayerHpGauge::CPlayerHpGauge() :
CPlayerState(),
pos(Float2(100, 50)), size(Float2(400, 40))
{
}


void CPlayerHpGauge::IniData(INIReader ini)
{
	max_hp = ini.get<float>(L"HP.max_hp");
	hp = now_hp = max_hp;
}

void CPlayerHpGauge::Damage(const int power)
{
	if (hp <= 0)
	{
		hp = now_hp = 0; 
		player->Death();
		return;
	}
	now_hp -= power;
}

///	アップデート
void CPlayerHpGauge::Update()
{
	if (now_hp >= hp) return;
	hp -= 0.1f;
}

void CPlayerHpGauge::Draw()
{
	const float FrameSize = 10;
	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::HPBack)).resize(
		size + Float2(FrameSize, FrameSize)).draw(pos + Float2(-FrameSize / 2, -FrameSize / 2));

	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::HP)).resize(
		Float2(size.x * hp / max_hp, size.y)).draw(pos);

	const float TextureSize = 120;
	TextureAsset(CResource::GetInstance().GetUI(CResource::UIType::Face)).resize(
		TextureSize, TextureSize).drawAt(pos + Float2(-TextureSize / 4, TextureSize / 6));

}