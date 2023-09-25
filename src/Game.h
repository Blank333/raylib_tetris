#ifndef GAME_H
#define GAME_H
#include "Blocks.cpp"
#include "Grid.h"
#include <raylib.h>

class Game {
private:
  int cellSize, cell_w, cell_h;
  int center;
  double lastUpdate, speed;
  Block activeBlock, nextBlock;
  std::vector<Block> blocks;
  Grid grid;

  void Move();
  bool eventTriggered(double interval);

public:
  Game(int cellSize, int cell_w, int cell_h, double speed);
  void Draw();
  void Update();
  bool isBlockOutside();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Cheats();
};

#endif