#ifndef LASER_H
#define LASER_H

#include "raylib.h"

class Laser
{
public:
  Laser(Vector3 position, Vector3 direction, float speed, float length);
  void update(float deltaTime);
  void draw();
  Vector3 getPosition();
  Vector3 getDirection();
  bool isAlive();

private:
  Vector3 position;
  Vector3 direction;
  float speed;
  float length;
  float distanceTravelled = 0.0f;
  float maxDistance = 100.0f;
  bool alive = true;
  Color color = YELLOW;
};
#endif // !LASER_H
