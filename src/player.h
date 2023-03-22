#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Vector3 position;
  Model model;

  Player(float x, float y, float z);
  Player(float x, float y, float z, Model model);
  void draw();
  void move(Vector3 velocity);
  void setModel(Model model);
};

#endif // !PLAYER_H
