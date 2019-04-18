#include "CharacterController.h"
#include <siv3D.hpp>

bool CharacterController::LeftMoveKey()
{
	if (Input::KeyA.pressed) return true;
	return false;
}

bool CharacterController::RightMoveKey()
{
	if (Input::KeyD.pressed) return true;
	return false;
}

bool CharacterController::JumpKey()
{
	if (Input::KeyW.clicked) return true;
	return false;
}

bool CharacterController::AttackKey()
{
	if (Mouse::LeftClicked()) return true;
	return false;
}

bool CharacterController::AvoidKey()
{
	if (Input::KeyLShift.clicked) return true;
	if (Mouse::RightClicked()) return true;

	return false;
}

bool CharacterController::ChangeSceneKey()
{
	if (Input::KeyZ.pressed) return true;
	if (Input::KeyEnter.pressed) return true;
	return false;
}

bool CharacterController::SelectSceneUpKey()
{
	if (Input::KeyUp.clicked) return true;
	return false;
}

bool CharacterController::SelectSceneDownKey()
{
	if (Input::KeyDown.clicked) return true;
	return false;
}