#ifndef GAME_H
#define GAME_H
#include "Block.h"
#include <raylib.h>

class Game {
private:
  int cellSize, cell_w, cell_h;
  int center;
  double lastUpdate = 0, speed;

  Block block;

public:
  Game(int cellSize, int cell_w, int cell_h, double speed)
      : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h),
        center(cell_w * cellSize / 2 - cellSize),
        block(center, cellSize, cell_h, cell_w), speed(speed) {}

  void Draw() { block.Draw(); }

  void Update() {
    if (eventTriggered(speed)) {
      block.Update();
    }
    Move();
  }
  void Move() {
    if (IsKeyPressed(KEY_RIGHT) &&
        block.getX() < cell_w * cellSize - cellSize) {
      block.moveRight();
    } else if (IsKeyPressed(KEY_LEFT) && block.getX() >= cellSize) {
      block.moveLeft();
    } else if (IsKeyPressed(KEY_DOWN)) {
      block.connect();
    }
  }

  bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdate >= interval) {
      lastUpdate = currentTime;
      return true;
    }
    return false;
  }
};

#endif