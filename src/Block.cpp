#include "Block.h"

Block::Block(int center, int cellSize, int cell_h, int cell_w)
    : cellSize(cellSize), x(center), y(cellSize), cell_h(cell_h),
      cell_w(cell_w) {}

void Block::Draw() { DrawRectangle(x, y, cellSize, cellSize, RED); }

void Block::Update() { Bounds(); }

void Block::Bounds() {
  if (y >= cell_h * cellSize - cellSize) {
    // NewBlock();
  } else {
    y += cellSize;
  }
}

int Block::getX() { return x; }
int Block::getY() { return y; }
void Block::moveRight() { x += cellSize; }
void Block::moveLeft() { x -= cellSize; }
void Block::connect() { y = cell_h * cellSize - cellSize; }