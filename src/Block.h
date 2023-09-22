#ifndef BLOCK_H
#define BLOCK_H

#include <raylib.h>

class Block {
private:
  int cellSize, cell_h, cell_w;
  int x, y;

public:
  Block(int center, int cellSize, int cell_h, int cell_w)
      : cellSize(cellSize), x(center), y(cellSize), cell_h(cell_h),
        cell_w(cell_w) {}

  void Draw() { DrawRectangle(x, y, cellSize, cellSize, WHITE); }

  void Update() { y += cellSize; }

  void moveRight() { x += cellSize; }
  void moveLeft() { x -= cellSize; }
  void connect() { y = cell_h * cellSize - cellSize; }
};

#endif