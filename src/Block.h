#ifndef BLOCK_H
#define BLOCK_H

#include <raylib.h>

class Block {
private:
  int cellSize, cell_h, cell_w;
  int x, y;
  void Bounds();

public:
  Block(int center, int cellSize, int cell_h, int cell_w);

  void Draw();
  void Update();
  int getX();
  int getY();
  void moveRight();
  void moveLeft();
  void connect();
};

#endif