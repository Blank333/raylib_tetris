#include "Grid.h"
#include "Colors.h"

Grid::Grid() {
  cell_w = 10;
  cell_h = 20;
  cellSize = 32;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < cell_h; row++) {
    for (int col = 0; col < cell_w; col++) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Draw() {
  for (int row = 0; row < cell_h; row++) {
    for (int col = 0; col < cell_w; col++) {
      int cellVal = grid[row][col];
      DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize,
                    colors[cellVal]);
    }
  }
}

bool Grid::isCellOutside(int row, int col) {
  if (row >= 0 && row < cell_h && col >= 0 && col < cell_w)
    return false;
  return true;
}