#include "Tree.h"
#include "GameObjectHousing.h"
#include "Collision.h"
#include "Task.h"
#include "Actor.h"
#include "Resource.h"
#include "EnemyManager.h"
#include "SlimeActor.h"
#include "WeaponSoldier.h"
#include "MagicSoldier.h"
#include "Utility.h"

const Float3 GraphicSize = Float3(300, 300, 0.0001f);

CTree::CTree(Float3 pos) :
transform(pos, Float3(100, 100, 200), Float3(0, 0, 0)),
state(State::None),
velocity(Float3(0, 0, 0)),
id(0),
count(0),
alpha(255),
texture(utility::CreateMirroredBox(GraphicSize, 1)),
animation(std::make_unique<CGraphicAnimation<int>>())
{
	AnimationList();
}

const Float2 ConbineSize = Float2(100, 50);

CTree::CTree(Float3 pos, int direction) :
transform(pos, Float3(ConbineSize.x, ConbineSize.y, 200), Float3(0, 0, PiF / 180 * -90)),
state(State::Conbine),
velocity(Float3(10 * direction, 0, 0)),
id(3),
count(0),
alpha(255),
texture(utility::CreateMirroredBox(Float3(ConbineSize.x, ConbineSize.y * 3, 0.00001f), 1)),
animation(std::make_unique<CGraphicAnimation<int>>())
{
	AnimationList();
}

//	アニメーションリスト
void CTree::AnimationList()
{
	animation->Append(0, AnimationFrame(0, 0, 0));
	animation->Append(1, AnimationFrame(1, 1, 0));
	animation->Append(2, AnimationFrame(2, 2, 0));
	animation->Append(3, AnimationFrame(3, 3, 0));
	animation->OnAnimation(id);
}

//	終了処理
void CTree::Finish()
{
	state = State::Death;
}

//	あたり判定で当たったかどうかを取得
bool CTree::IsCollisionHit(std::shared_ptr<CTask> task,const std::string &name)
{
	for (auto& it : task->GetActor(name))
	{
		if (collision::AABBToAABB(transform.GetPos(), transform.GetScale(),
			it->transform.GetPos(), it->transform.GetScale()))
		{
			transform.Translate(Float3(0, GraphicSize.y / 3, 50));
			return true;
		}
	}
	return false;
}

//	ヒット時の生成
void CTree::CreateHit(std::shared_ptr<CTask> task)
{
	if (state != State::None) return;
	transform.Translate(velocity);
	velocity.y -= 5.0f;
	if (IsCollisionHit(task, CGameObjectHousing::FloorName))
	{
		state = State::Bloom;
	}
	if (IsCollisionHit(task, CGameObjectHousing::TombstoneName) || IsCollisionHit(task, CGameObjectHousing::FenceName))
	{
		state = State::Death;
	}
}

//	アップデート
void CTree::BloomUpdate()
{
	if (state != State::Bloom) return;

	count++;
	if (count >= 30)
	{
		count = 0;
		id++;
		animation->OnAnimation(id);
		if (id >= 3)
		{
			count = 0;
			state = State::FullBloom;
		}
	}
}

//	満開の処理
void CTree::FullBloom()
{
	if (state != State::FullBloom) return;
	alpha -= 3;
	if (alpha <= 0)
	{
		state = State::Death;
	}
}

//	合体のアップデート
void CTree::ConbieUpdate()
{
	if (state != State::Conbine) return;

	transform.Translate(velocity);
	//alpha -= 1;
	if (alpha <= 0)
	{
		state = State::Death;
	}
}

void CTree::Update(std::shared_ptr<CTask> task)
{
	CreateHit(task);
	BloomUpdate();
	FullBloom();
	ConbieUpdate();
}

void CTree::Draw()
{
	if (state == State::None || state == State::Death) return;
	
	auto graph = TextureAsset(CResource::GetInstance().GetTree(animation->GetId()));

	texture.rotate(transform.GetRotation()).translate(transform.GetPos()).draw(graph,
		Alpha(alpha), *CResource::GetInstance().GetAlphaRenderer());
}