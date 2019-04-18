
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

///	仮想コントローラー
class CharacterController
{
public:
	static bool LeftMoveKey();
	static bool RightMoveKey();
	static bool JumpKey();
	static bool AttackKey();
	static bool SpecialInvocationAttackKey();
	static bool AvoidKey();
	static bool ChangeSceneKey();
	static bool SelectSceneUpKey();
	static bool SelectSceneDownKey();

};

