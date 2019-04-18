#include "Soul.h"
#include "SoulRelease.h"
#include "Task.h"
#include "Player.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Resource.h"

const double MaxPoint = 100;
CSoul::CSoul(double max_point, Palette color) :
color(color),
max_point(max_point),
point(0),
now_point(0),
pos(Point(CGameApplication::ScreenWidth-160,160)),
size(Point(300,300)),
state(State::None)
{
}

void CSoul::Start(std::shared_ptr<CPlayer> player)
{
	this->player = player;
}

///	������
void CSoul::Init()
{
	now_point = max_point/2;
	point = 0;
	state = State::Absorption;
}

///	�g�p
void CSoul::Use()
{
	now_point = 0;
	state = State::Use;
}

///	�A�b�v�f�[�g
void CSoul::Update()
{
	UseUpdate();
	AbsorptionUpdate();
	ReleaseUpdate();
}

///	�g�p�A�b�v�f�[�g
void CSoul::UseUpdate()
{
	if (state != State::Use) return;

	if (point <= now_point)
	{
		point = 0;
		state = State::None;
		return;
	}

	point -= max_point / (60*6);

}

///	�z���A�b�v�f�[�g
void CSoul::AbsorptionUpdate()
{
	if (state != State::Absorption) return;

	if (point >= now_point)
	{
		if (max_point <= point)
		{
			now_point = 0;
			point = max_point;
		}
		state = State::None; 
		return;
	}
	point += 0.5;
	
}

void CSoul::CreateRelease(Float3 pos, Float2 monster_ui_pos, const int point)
{
	release.push_back(std::make_unique<CSoulRelease>(player, pos, monster_ui_pos, point, color));
}

///	���o
void CSoul::ReleaseUpdate()
{
	for (auto& it : release)
	{
		it->Update();
	}
	Absorption();
	ReleaseDelete();
}

//	�z���̍ő��
void CSoul::MaxAbsorption()
{
	point = 1;
	now_point = max_point;
	state = State::Absorption;
}

//	�z��
void CSoul::Absorption()
{
	for (auto& it : release)
	{
		if (it->IsAbsorptionCollision())
		{
			if (state == State::Use) return;

			now_point += 1;
			AbsorptionPlaySE();
		}
	}
}

//	�����ō����z��
void CSoul::AutoAbsorption()
{
	now_point += 0.05;
	state = State::Absorption;
}

///	���o
void CSoul::ReleaseDelete()
{
	Erase_if(release, [](const std::unique_ptr<CSoulRelease> &obj)
	{
		return obj->GetDelete();
	});
}

void CSoul::Draw()
{
	for (auto& it : release)
	{
		it->Draw();
	}
}

//	�z��SE���Đ�
void CSoul::AbsorptionPlaySE()
{
	if (state == State::Absorption) return;

	CResource::GetInstance().PlaySE(CResource::SE::GaugeCharge);
	state = State::Absorption;
}