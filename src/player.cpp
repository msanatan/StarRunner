#include "raylib.h"
#include "raymath.h"
#include "player.h"

Player::Player(float x, float y, float z, float size)
{
  this->position = (Vector3){x, y, z};
  this->size = size;
}

void Player::draw()
{
  DrawCube(this->position, this->size, this->size, this->size, RED);
  DrawCubeWires(this->position, this->size, this->size, this->size, MAROON);
  return;
}

void Player::move(Vector3 velocity)
{
  this->position = Vector3Add(this->position, velocity);
  return;
}
