#include "Game.h"
#include <iostream>
#include <raylib.h>
using namespace std;

const int cellSize = 32;
const int cell_w = 10, cell_h = 20;
const int width = cellSize * cell_w, height = cellSize * cell_h;
const char *title = "Tetris";

double speed = 0.5;

int main() {
  InitWindow(width, height, title);
  SetTargetFPS(165);
  HideCursor();

  Game game(cellSize, cell_w, cell_h, speed);
  while (!WindowShouldClose()) {
    BeginDrawing();
    // Display FPS
    SetWindowTitle(TextFormat("%s (%i)", title, GetFPS()));

    game.Draw();
    game.Update();

    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}