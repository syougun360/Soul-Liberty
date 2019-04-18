#include "InputName.h"
#include "GameApplication.h"
#include "Utility.h"
#include "Resource.h"

const Point NameInput = Point(CGameApplication::ScreenWidth / 2 + 50, 300);

const Point DecisionPos = Point(NameInput.x, NameInput.y + 150);
const Point DecisionSize = Point(300, 50);


void CInputName::Init()
{
	name_font = new Font(45, Typeface::Regular);
	isCursor = false;
	isDecision = false;
	count = 0;
	cursor_pos = NameInput + Point(0, 10);
}
void CInputName::ShowCursor()
{
	count++;
	if (count == 15)
	{
		isCursor = true;
	}
	else if (count >= 30)
	{
		count = 0;
		isCursor = false;
	}
}

void CInputName::InputNameString()
{
	if (isDecision) return;

	if (name_str.length < 6)
	{
		if (Input::KeyEnter.clicked) return;
		Input::GetCharsHelper(name_str);

	}
	else
	{
		if (name_str.length != 6)
			name_str.pop_back();

		if (Input::KeyBackspace.clicked)
			name_str.pop_back();
	}
}
void CInputName::Decision()
{
	if (name_str.length == 0) return;
	if (isDecision) return;
	if (utility::IsMouseIncludeRectPointer(DecisionPos, DecisionSize))
	{
		if (Mouse::LeftClicked())
		{
			isDecision = true;
			CResource::GetInstance().PlaySE(CResource::SE::Decision);
		}
	}
}

void CInputName::Update()
{
	Decision();
	InputNameString();
	ShowCursor();
}

void CInputName::Draw()
{
	auto texture = TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::NameInput));
	texture.draw(0,0);

	name_font->draw(name_str, NameInput, Palette::White);

	auto rext = name_box(name_str).region(NameInput);
	if (!isCursor) return;
	Line(cursor_pos.x + rext.w * 2 + 10, cursor_pos.y, cursor_pos.x + rext.w * 2 + 10, cursor_pos.y + 70).draw(5.0, Palette::White);
}