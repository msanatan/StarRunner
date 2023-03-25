#include "raylib.h"
#include "raymath.h"
#include "player.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// Global variables
static const Color backgroundColor = Color({32, 33, 63});
static Camera3D camera = {0};
static Player player = Player(0.0f, 0.0f, 0.0f);
static Vector3 playerVelocity = {0.0f, 0.0f, 0.0f};
static const float playerSpeed = 5.0f;

void InitGame()
{
  // Load the player model
  Model playerModel = LoadModel("assets/models/PlayerShip.glb");
  player.setModel(playerModel);
}

void UpdateGame()
{
  auto deltaTime = GetFrameTime();
  player.update(deltaTime);
}

void DrawGame()
{
  BeginDrawing();
  ClearBackground(backgroundColor);
  BeginMode3D(camera);
  player.draw();
  EndMode3D();
  DrawFPS(10, 10);
  EndDrawing();
}

void UpdateAndDrawFrame()
{
  UpdateGame();
  DrawGame();
}

int main()
{
  // Initialize Raylib window
  const int screenWidth = 1600;
  const int screenHeight = 900;
  InitWindow(screenWidth, screenHeight, getenv("APP_NAME"));

  InitGame();

  // Set up camera
  camera.position = (Vector3){0.0f, 10.0f, 10.0f}; // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};     // Camera looking at point
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};         // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;          // Camera mode type

// Run the game loop for web
#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(UpdateAndDrawFrame, 0, 1);
#else
  // Run the game loop for desktop platforms
  SetTargetFPS(60);            // Set our game to run at 60 frames-per-second
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    UpdateAndDrawFrame();
  }
#endif
  // De-Initialization
  CloseWindow(); // Close window and OpenGL context
  return 0;
}
