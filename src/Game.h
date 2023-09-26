#ifndef GAME_H
#define GAME_H
#include "Blocks.cpp"
#include "Grid.h"
#include <raylib.h>

class Game {
private:
  int cellSize, cell_w, cell_h;
  int center, padding;
  double lastUpdate, speed;
  Block activeBlock, nextBlock;
  std::vector<Block> blocks;
  Grid grid;
  bool running;

  void Move();
  bool eventTriggered(double interval);

public:
  Game(int cellSize, int cell_w, int cell_h, double speed, int padding);
  void Draw();
  void Update();
  void Reset();
  void moveBlock();
  void LockBlock();
  bool isBlockOutside();
  bool isBlockFit();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Cheats();
};

#endif