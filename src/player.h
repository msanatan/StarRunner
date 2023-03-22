#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Vector3 position;
  float size;

  Player(float x, float y, float z, float size);
  void draw();
  void move(Vector3 velocity);
};

#endif // !PLAYER_H
