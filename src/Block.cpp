#include "Block.h"

Block::Block(int center, int cellSize, int cell_h, int cell_w)
    : cellSize(cellSize), x(center), y(cellSize), cell_h(cell_h),
      cell_w(cell_w) {
  rotation = 0;
  colors = GetCellColors();
}

void Block::Draw() {
  std::vector<Position> tiles = getTiles();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize + x, item.row * cellSize + y,
                  cellSize - 1, cellSize - 1, colors[id]);
    DrawRectangleLinesEx({(float)item.col * cellSize + x,
                          (float)item.row * cellSize + y, (float)cellSize,
                          (float)cellSize},
                         2, WHITE);
  }
}

void Block::Update() { Bounds(); }

void Block::Bounds() {

  if (y >= cell_h * cellSize - cellSize) {
    // NewBlock();
  } else {
    y += cellSize;
  }
}

std::vector<Position> Block::getTiles() { return cells[rotation]; }

int Block::rotate() {
  if (rotation >= 3)
    rotation = 0;
  else
    rotation++;
}

int Block::getX() { return x; }
int Block::getY() { return y; }

void Block::moveRight() { x += cellSize; }
void Block::moveLeft() { x -= cellSize; }
void Block::connect() { y = cell_h * cellSize - cellSize; }