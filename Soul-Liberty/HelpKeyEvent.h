
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/

#pragma once
#include <memory>
class CSceneManager;

///	メニューキーイベント
class CHelpKeyEvent
{
public:
	CHelpKeyEvent();

	///	シーンを変更
	void ChangeSceneGame(std::shared_ptr<CSceneManager> scene);

private:

};

