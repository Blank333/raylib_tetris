#include "Block.h"
Block::Block() {
  rotation = 0;
  colors = GetCellColors();
}

Block::Block(int center, int cellSize, int cell_h, int cell_w)
    : center(center), cellSize(cellSize), cell_h(cell_h), cell_w(cell_w) {
  x = y = rotation = 0;
  colors = GetCellColors();
  colorsGhost = GetGhostColors();
}

void Block::Draw(int offsetX, int offsetY) {
  std::vector<Position> tiles = getTiles();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize + offsetX,
                  (item.row - 2) * cellSize + offsetY, cellSize - 1,
                  cellSize - 1, colors[id]);
  }
}

void Block::DrawGhost(int offsetX, int offsetY) {
  std::vector<Position> tiles = getTiles();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize + offsetX,
                  (item.row - 2) * cellSize + offsetY, cellSize - 1,
                  cellSize - 1, colorsGhost[id]);
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