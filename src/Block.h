#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <raylib.h>
#include <vector>

#include "Colors.h"
#include "Position.h"

class Block {
private:
  int cellSize, cell_h, cell_w, center;
  int x, y, rotation;
  std::vector<Color> colors;
  std::vector<Color> colorsGhost;

public:
  int id;
  std::map<int, std::vector<Position>> cells;

  Block();
  Block(int center, int cellSize, int cell_h, int cell_w);
  void Draw(int offsetX, int offsetY);
  std::vector<Position> getTiles();

  void DrawGhost(int offsetX, int offsetY);
  void rotate();
  void unRotate();
  void move(int row, int col);
  void moveRight();
  void moveLeft();
  void moveDown();
  void moveUp();
};

#endif
