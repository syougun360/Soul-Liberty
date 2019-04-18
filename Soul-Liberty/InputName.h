
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include <siv3D.hpp>

//	���O����
class CInputName
{
public:

	void Init();
	void Update();
	void Draw();
	String GetName()const{ return name_str; }
	bool IsDecision()const{ return isDecision; }

private:
	//	���O����
	void InputNameString();

	//	Cursor��\��
	void ShowCursor();

	//	����
	void Decision();

	bool isCursor;
	bool isDecision;
	int count;
	Font* name_font;
	Font name_box;
	String name_str;
	Point cursor_pos;
};

