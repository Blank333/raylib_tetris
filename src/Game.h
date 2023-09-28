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

  Sound rotateBlockSound;
  Sound moveBlockSound;
  Sound placeBlockSound;
  Sound clearLineSound;
  Sound loseSound;
  Sound tetrisSound;

  void Move();
  bool eventTriggered(double interval);
  bool blockTriggered(double interval);
  void moveBlock();
  void LockBlock();
  bool isBlockOutside();
  bool isBlockFit();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void UpdateScore(int lines, int moves);
  int dropDistance(Position pos);
  int dropBlock();
  void hardDrop();

  void Cheats();

public:
  Game(int cellSize, int cell_w, int cell_h, double speed, int padding,
       int interface);
  ~Game();
  void Draw();
  void Update();
  void Reset();
  Music music;
};

#endif