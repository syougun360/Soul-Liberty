
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Scene.h"


/// ƒGƒ“ƒhƒ[ƒ‹
class CEndRollManager :public CScene
{
public:
	CEndRollManager(std::shared_ptr<CSceneManager> manager);
	void Init();
	void Update();
	void Draw();

private:
	enum class State
	{
		Fade,
		Update,
		End
	};
	void ChangeIndex();
	void FadeOut();
	State state;
	int count;
	int alpha;
	int index;
	int alpha2;
	int index2;

};

