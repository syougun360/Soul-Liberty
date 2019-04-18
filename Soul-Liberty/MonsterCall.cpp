#include "MonsterCall.h"
#include "Utility.h"

CMonsterCall::CMonsterCall(Float2 pos, Float2 absorption_pos, CResource::MonsterUIType id, int alpha) :
pos(pos),
size(Float2(100, 100)), id(id),
absorption_pos(absorption_pos),
alpha(alpha)
{
}

void CMonsterCall::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetMonsterUI(id));
	texture.resize(size).draw(pos);
}