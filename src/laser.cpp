#include "raylib.h"
#include "raymath.h"
#include "laser.h"

Laser::Laser(Vector3 position, Vector3 direction, float speed, float length)
{
  this->position = position;
  this->direction = direction;
  this->speed = speed;
  this->length = length;
}

void Laser::update(float deltaTime)
{
  auto movement = Vector3Scale(this->direction, this->speed * deltaTime);
  this->position = Vector3Add(this->position, movement);
  this->distanceTravelled += Vector3Length(movement);
  if (this->distanceTravelled > this->maxDistance)
  {
    this->alive = false;
  }
}

void Laser::draw()
{
  if (this->alive)
  {
    DrawCapsule(
        this->position,
        (Vector3){this->position.x, this->position.y, this->position.z + this->length},
        0.25f,
        16,
        16,
        this->color);
  }
}

Vector3 Laser::getPosition()
{
  return this->position;
}

Vector3 Laser::getDirection()
{
  return this->direction;
}

bool Laser::isAlive()
{
  return this->alive;
}
