#include "Block.h"
#include "Position.h"

class LBlock : public Block {
public:
  LBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 1;
    cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
    move(0, center - 2);
  }
};

class JBlock : public Block {
public:
  JBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 2;
    cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
    move(0, center - 2);
  }
};

class IBlock : public Block {
public:
  IBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 3;
    cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
    move(-1, center - 2);
  }
};

class OBlock : public Block {
public:
  OBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 4;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    move(0, center - 1);
  }
};

class SBlock : public Block {
public:
  SBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 5;
    cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
    move(0, center - 2);
  }
};

class TBlock : public Block {
public:
  TBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 6;
    cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
    move(0, center - 2);
  }
};

class ZBlock : public Block {
public:
  ZBlock(int center, int cellSize, int cell_h, int cell_w)
      : Block(center, cellSize, cell_h, cell_w) {
    id = 1;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
    move(0, center - 2);
  }
};
