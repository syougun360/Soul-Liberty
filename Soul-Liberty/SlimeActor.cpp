#include "SlimeActor.h"
#include "SlimeAttack.h"
#include "Player.h"


CSlimeActor::CSlimeActor(std::shared_ptr<CTask> task, Transform transform, ScaleType scale_type,CResource::MonsterUIType soul_type) :	
	CEnemyActor(task, transform, soul_type),
	scale_type(scale_type)
{
	
}

//	方向を切り替える
void CSlimeActor::ChangeDirection()
{
	if (player->transform.GetPos().x > transform.GetPos().x)
		direction = Direction::Right;

	else if (player->transform.GetPos().x < transform.GetPos().x)
		direction = Direction::Left;
}

//	床とのあたり判定
void CSlimeActor::CollisionFloor()
{
	if (!IsCollisionFloor()) return;

	InitAttack();
	CResource::GetInstance().PlaySE(CResource::SE::SlimeMove);
	
}

//	キャラクター描画
void CSlimeActor::CharacterDraw(CResource::SlimeType texture_type)
{
	auto texture = TextureAsset(CResource::GetInstance().GetSlime(texture_type));
	auto bottom = Float3(0, transform.GetScale().y / 6, 0);

	if (direction == Direction::Left)
		left.translate(transform.GetPos() - bottom).draw(texture, hit_color, *CResource::GetInstance().GetAlphaRenderer());

	if (direction == Direction::Right)
		right.translate(transform.GetPos() - bottom).draw(texture, hit_color, *CResource::GetInstance().GetAlphaRenderer());

}
