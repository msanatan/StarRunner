#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Player(float x, float y, float z);
  Player(float x, float y, float z, Model model);
  void draw();
  void update(float deltaTime);
  void setModel(Model model);

private:
  Vector3 position;
  Vector3 velocity;
  Vector3 rotation;
  Model model;
  float speed = 10.0f;
};

#endif // !PLAYER_H
