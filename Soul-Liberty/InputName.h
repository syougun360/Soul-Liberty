
/**
*
*	@author	yamada masamitsu
*	@date	2014.11.20
*
*/
#pragma once
#include <siv3D.hpp>

//	–¼‘O“ü—Í
class CInputName
{
public:

	void Init();
	void Update();
	void Draw();
	String GetName()const{ return name_str; }
	bool IsDecision()const{ return isDecision; }

private:
	//	–¼‘O“ü—Í
	void InputNameString();

	//	Cursor‚ğ•\¦
	void ShowCursor();

	//	Œ¸­
	void Decision();

	bool isCursor;
	bool isDecision;
	int count;
	Font* name_font;
	Font name_box;
	String name_str;
	Point cursor_pos;
};

