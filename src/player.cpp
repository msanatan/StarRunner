#include "raylib.h"
#include "raymath.h"
#include "player.h"

Player::Player(float x, float y, float z)
{
  this->position = (Vector3){x, y, z};
  return;
}

Player::Player(float x, float y, float z, Model model)
{
  this->position = (Vector3){x, y, z};
  this->model = model;
}

void Player::draw()
{
  DrawModel(this->model, this->position, 1.0f, WHITE);
  return;
}

void Player::move(Vector3 velocity)
{
  this->position = Vector3Add(this->position, velocity);
  return;
}

void Player::setModel(Model model)
{
  this->model = model;
  return;
}
