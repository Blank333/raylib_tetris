#ifndef GAME_H
#define GAME_H
#include "Blocks.cpp"
#include "Grid.h"
#include "UI.h"
#include <raylib.h>

class Game {
private:
  int cellSize, cell_w, cell_h;
  int center, padding, interface;
  double lastUpdate, speed;
  Block activeBlock, nextBlock;
  std::vector<Block> blocks;
  Grid grid;
  bool running;
  int score;
  UI ui;
  void Move();
  bool eventTriggered(double interval);

public:
  Game(int cellSize, int cell_w, int cell_h, double speed, int padding,
       int interface);
  void Draw();
  void Update();
  void Reset();
  void moveBlock();
  void LockBlock();
  bool isBlockOutside();
  bool isBlockFit();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void UpdateScore(int lines, int moves);

  void Cheats();
};

#endif