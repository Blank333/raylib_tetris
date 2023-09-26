#include "Game.h"
#include "UI.h"
#include <iostream>
#include <raylib.h>
using namespace std;

const int cellSize = 32;
const int cell_w = 10, cell_h = 20;
const int interface = 10;
const int padding = 10;
const int width = cellSize * (interface + cell_w) + padding,
          height = cellSize * cell_h + 2 * padding;
const char *title = "Tetris";

double speed = 0.5;

int main() {
  InitWindow(width, height, title);
  SetTargetFPS(165);
  HideCursor();

  Game game(cellSize, cell_w, cell_h, speed, padding);
  UI ui(cellSize, cell_w, cell_h, speed, padding, interface);
  while (!WindowShouldClose()) {
    BeginDrawing();
    // Display FPS
    SetWindowTitle(TextFormat("%s (%i)", title, GetFPS()));

    game.Draw();
    game.Update();
    ui.Draw();

    ClearBackground(DARKPURPLE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}