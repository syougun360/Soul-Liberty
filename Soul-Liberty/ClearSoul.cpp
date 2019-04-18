#include "ClearSoul.h"
#include "Resource.h"
#include "Utility.h"
#include "GameApplication.h"

CClearSoul::CClearSoul(Float3 mob_pos):
CActor(nullptr,Transform(Float3(CGameApplication::ScreenWidth/2,CGameApplication::ScreenHeight/6,0),Float3(0,0,1),Float3(0,0,0)),State::Move,L""),
mob_pos(mob_pos + Float3(0,150,0))
{
}
const float MaxSize = 200;

void CClearSoul::Update()
{
	if (state != State::Move) return;
	auto velocity = utility::MoveBy(transform.GetPos(), mob_pos, 4);
	transform.Translate(velocity);

	transform.Scaling(Float3(1, 1, 0));
	if (transform.GetScale().x >= MaxSize)
	{
		transform.TransformScale(Float3(MaxSize, MaxSize, 1));
		if (utility::IsInclude<float>(transform.GetPos().y, mob_pos.y, 10))
		{
			state = State::None;
		}
	}
}

void CClearSoul::Draw()
{
	if (state == State::None) return;

	auto graph = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Soul));
	graph.resize(Float2(transform.GetScale().x, transform.GetScale().y)).drawAt(
		Float2(transform.GetPos().x, transform.GetPos().y));
}