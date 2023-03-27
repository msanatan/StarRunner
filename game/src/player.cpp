#include "raylib.h"
#include "raymath.h"
#include "player.h"

Player::Player(float x, float y, float z)
{
  this->position = {x, y, z};
  this->rotation = { 0.0f, 0.0f , 0.0f };
  return;
}

Player::Player(float x, float y, float z, Model model)
{
  this->position = {x, y, z};
  this->model = model;
}

void Player::draw()
{
  DrawModel(this->model, this->position, 1.0f, WHITE);
  return;
}

void Player::update(float deltaTime)
{
  this->velocity = {0.0f, 0.0f, 0.0f};
  // Update player position based on arrow key input
  if (IsKeyDown(KEY_LEFT))
  {
      this->velocity.x -= 1.0;
  }
  if (IsKeyDown(KEY_RIGHT))
  {
      this->velocity.x += 1.0;
  }
  if (IsKeyDown(KEY_UP))
  {
      this->velocity.y += 1.0;
  }
  if (IsKeyDown(KEY_DOWN))
  {
      this->velocity.y -= 1.0;
  }

  this->rotation.x = this->velocity.y / 2;
  this->rotation.y = -this->velocity.x / 2;
  this->rotation.z = -this->velocity.x / 2;

  this->velocity = Vector3Scale(Vector3Normalize(this->velocity), this->speed * deltaTime);
  this->position = Vector3Add(this->position, this->velocity);
  this->model.transform = MatrixRotateXYZ(this->rotation);
}

void Player::setModel(Model model)
{
  this->model = model;
  return;
}
