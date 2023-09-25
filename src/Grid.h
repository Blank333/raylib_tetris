#ifndef GRID_H
#define GRID_H
#include <raylib.h>
#include <vector>

class Grid {
private:
  int cell_h, cell_w, cellSize;
  std::vector<Color> colors;

public:
  int grid[20][10];

  Grid();
  void Initialize();
  void Draw();
  bool isCellOutside(int row, int col);
};

#endif