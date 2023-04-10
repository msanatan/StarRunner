#include "raylib.h"
#include "inputmanager.h"

#define GAMEPAD_PLAYER1 0

InputManager::InputManager()
{
}

void InputManager::update()
{
  moveUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP);
  moveDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
  moveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
  moveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
  shoot = IsKeyPressed(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
}

bool InputManager::isMoveUp()
{
  return moveUp;
}

bool InputManager::isMoveDown()
{
  return moveDown;
}

bool InputManager::isMoveLeft()
{
  return moveLeft;
}

bool InputManager::isMoveRight()
{
  return moveRight;
}

bool InputManager::isShoot()
{
  return shoot;
}
