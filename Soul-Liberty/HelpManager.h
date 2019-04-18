
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include "Scene.h"

class CHelpKeyEvent;

///	���j���[�Ǘ�
class CHelpManager :public CScene
{
public:
	CHelpManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

private:
	Font* Logo;		///<	���S
	std::unique_ptr<CHelpKeyEvent> key;	///<	�L�[�C�x���g
};
