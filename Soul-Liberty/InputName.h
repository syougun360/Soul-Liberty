
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include <siv3D.hpp>

//	名前入力
class CInputName
{
public:

	void Init();
	void Update();
	void Draw();
	String GetName()const{ return name_str; }
	bool IsDecision()const{ return isDecision; }

private:
	//	名前入力
	void InputNameString();

	//	Cursorを表示
	void ShowCursor();

	//	減少
	void Decision();

	bool isCursor;
	bool isDecision;
	int count;
	Font* name_font;
	Font name_box;
	String name_str;
	Point cursor_pos;
};

