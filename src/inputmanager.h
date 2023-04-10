#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "raylib.h"

class InputManager
{
public:
  InputManager();
  void update();
  bool isMoveUp();
  bool isMoveDown();
  bool isMoveLeft();
  bool isMoveRight();
  bool isShoot();

private:
  bool moveUp = false;
  bool moveDown = false;
  bool moveLeft = false;
  bool moveRight = false;
  bool shoot = false;
};
#endif // !INPUT_MANAGER_H
