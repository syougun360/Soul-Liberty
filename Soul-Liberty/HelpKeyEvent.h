
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <memory>
class CSceneManager;

///	���j���[�L�[�C�x���g
class CHelpKeyEvent
{
public:
	CHelpKeyEvent();

	///	�V�[����ύX
	void ChangeSceneGame(std::shared_ptr<CSceneManager> scene);

private:

};

