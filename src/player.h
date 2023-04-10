#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Player(float x, float y, float z);
  Player(float x, float y, float z, Model model);
  void draw();
  void drawCrosshair();
  void update(float deltaTime);
  void setModel(Model model);
  void setCrosshairTexture(Texture2D texture);
  void resetMovement();
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void shoot();

private:
  Vector3 position;
  Vector3 velocity;
  Vector3 rotation;
  Vector3 crosshairPosition;
  Model model;
  Texture2D crosshairTexture;
  float speed = 10.0f;
};

#endif // !PLAYER_H
