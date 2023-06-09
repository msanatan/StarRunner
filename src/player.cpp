#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include "player.h"

Player::Player(float x, float y, float z)
{
  this->position = {x, y, z};
  this->rotation = {0.0f, 0.0f, 0.0f};
  this->crosshairPosition = {0.0f, 0.0f, -10.0f};
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

void Player::drawCrosshair()
{
  // You typically draw a texture like this: DrawTextureEx(this->crosshairTexture, this->crosshairPosition, 0, 0.25f, WHITE);
  // In this case, we want the crosshair to follow the player's movement, but further in the z-axis so it looks farther away
  // Since we don't have access to the z-axis while drawing 2d, we essentially draw this texture on a cube so we can move it in 3d space
  // Taken from here: https://www.raylib.com/examples/models/loader.html?name=models_draw_cube_texture
  float width = 1.0;
  float height = 1.0;
  float length = 1.0;
  float x = this->crosshairPosition.x;
  float y = this->crosshairPosition.y;
  float z = this->crosshairPosition.z;

  // Set desired texture to be enabled while drawing following vertex data
  rlSetTexture(this->crosshairTexture.id);

  rlBegin(RL_QUADS);
  rlColor4ub(WHITE.r, WHITE.g, WHITE.b, WHITE.a);

  // Front Face
  rlNormal3f(0.0f, 0.0f, 1.0f); // Normal Pointing Towards Viewer
  rlTexCoord2f(0.0f, 0.0f);
  rlVertex3f(x - width / 2, y - height / 2, z + length / 2); // Bottom Left Of The Texture and Quad
  rlTexCoord2f(1.0f, 0.0f);
  rlVertex3f(x + width / 2, y - height / 2, z + length / 2); // Bottom Right Of The Texture and Quad
  rlTexCoord2f(1.0f, 1.0f);
  rlVertex3f(x + width / 2, y + height / 2, z + length / 2); // Top Right Of The Texture and Quad
  rlTexCoord2f(0.0f, 1.0f);
  rlVertex3f(x - width / 2, y + height / 2, z + length / 2); // Top Left Of The Texture and Quad

  rlSetTexture(0);
}

void Player::resetMovement()
{
  this->velocity = {0.0f, 0.0f, 0.0f};
}

void Player::moveUp()
{
  this->velocity.y += 1.0;
}

void Player::moveDown()
{
  this->velocity.y -= 1.0;
}

void Player::moveLeft()
{
  this->velocity.x -= 1.0;
}

void Player::moveRight()
{
  this->velocity.x += 1.0;
}

void Player::update(float deltaTime)
{
  this->velocity = Vector3Scale(Vector3Normalize(this->velocity), this->speed * deltaTime);
  this->position = Vector3Add(this->position, this->velocity);

  this->rotation.x = this->velocity.y / 2;
  this->rotation.y = -this->velocity.x / 2;
  this->rotation.z = -this->velocity.x * 2;
  this->model.transform = MatrixRotateXYZ(this->rotation);

  // Update crosshair position as well
  this->crosshairPosition = {this->position.x, this->position.y, this->crosshairPosition.z};
}

void Player::setCrosshairTexture(Texture2D texture)
{
  this->crosshairTexture = texture;
  return;
}

Model Player::getModel()
{
  return this->model;
}

void Player::setModel(Model model)
{
  this->model = model;
  return;
}
