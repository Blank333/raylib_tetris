#ifndef GAME_H
#define GAME_H
#include "Block.h"
#include "Grid.h"
#include <raylib.h>

class Game {
private:
  int cellSize, cell_w, cell_h;
  int center;
  double lastUpdate, speed;
  Block block;
  Grid grid;

  void Move();
  bool eventTriggered(double interval);

public:
  Game(int cellSize, int cell_w, int cell_h, double speed);
  void Draw();
  void Update();
};

#endif