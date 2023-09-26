#ifndef GRID_H
#define GRID_H
#include <raylib.h>
#include <vector>

class Grid {
private:
  int cell_h, cell_w, cellSize;
  std::vector<Color> colors;

  bool isRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int steps);

public:
  int grid[20][10];

  Grid();
  void Initialize();
  void Draw();
  bool isCellOutside(int row, int col);
  bool isCellEmpty(int row, int col);
  int ClearFullRows();
};

#endif