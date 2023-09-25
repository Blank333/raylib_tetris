#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <raylib.h>
#include <vector>

#include "Colors.h"
#include "Position.h"

class Block {
private:
  int cellSize, cell_h, cell_w;
  int x, y, rotation;
  std::vector<Color> colors;

  void Bounds();

public:
  int id;
  std::map<int, std::vector<Position>> cells;

  Block(int center, int cellSize, int cell_h, int cell_w);
  void Draw();
  void Update();
  int getX();
  int getY();
  std::vector<Position> getTiles();
  int rotate();

  void moveRight();
  void moveLeft();
  void connect();
};

#endif