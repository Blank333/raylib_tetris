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
  double lastUpdate, blockUpdate, speed, blockSpeed;
  Block activeBlock, nextBlock;
  std::vector<Block> blocks;
  Grid grid;
  bool running;
  int score, totalLines;
  UI ui;
  void Move();
  bool eventTriggered(double interval);
  Sound rotateBlockSound;
  Sound moveBlockSound;
  Sound placeBlockSound;
  Sound clearLineSound;
  Sound loseSound;
  Sound tetrisSound;

public:
  Game(int cellSize, int cell_w, int cell_h, double speed, int padding,
       int interface);
  ~Game();
  void Draw();
  bool blockTriggered(double interval);
  void Update();
  void Reset();
  void moveBlock();
  void LockBlock();
  bool isBlockOutside();
  bool isBlockFit();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void UpdateScore(int lines, int moves);
  Music music;

  void Cheats();
};

#endif