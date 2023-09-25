#include "Block.h"
Block::Block() {
  rotation = 0;
  colors = GetCellColors();
}

Block::Block(int center, int cellSize, int cell_h, int cell_w)
    : cellSize(cellSize), x(0), y(0), cell_h(cell_h), cell_w(cell_w) {
  rotation = 0;
  colors = GetCellColors();
}

void Block::Draw() {
  std::vector<Position> tiles = getTiles();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize, item.row * cellSize, cellSize - 1,
                  cellSize - 1, colors[id]);
    DrawRectangleLinesEx({(float)item.col * cellSize,
                          (float)item.row * cellSize, (float)cellSize,
                          (float)cellSize},
                         2, WHITE);
  }
}

std::vector<Position> Block::getTiles() {
  std::vector<Position> tiles = cells[rotation];
  std::vector<Position> newTiles;
  for (Position item : tiles) {
    Position newPos = Position(item.row + y, item.col + x);
    newTiles.push_back(newPos);
  }
  return newTiles;
}

void Block::rotate() {
  rotation++;
  if (rotation >= (int)cells.size())
    rotation = 0;
}

void Block::unRotate() {
  rotation--;
  if (rotation < 0)
    rotation = (int)cells.size() - 1;
}

void Block::move(int row, int col) {
  x += col;
  y += row;
};

void Block::moveRight() { move(0, 1); }
void Block::moveLeft() { move(0, -1); }
void Block::moveDown() { move(1, 0); }
void Block::moveUp() { move(-1, 0); }

void Block::connect() { y = cell_h - 3; }