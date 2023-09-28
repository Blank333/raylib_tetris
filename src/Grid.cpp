#include "Grid.h"
#include "Colors.h"

Grid::Grid(int padding) : padding(padding) {
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
      if (cellVal == 0)
        DrawRectangle(col * cellSize + padding, row * cellSize + padding,
                      cellSize, cellSize, colors[cellVal]);
      else
        DrawRectangle(col * cellSize + padding, row * cellSize + padding,
                      cellSize - 1, cellSize - 1, colors[cellVal]);
    }
  }
}

bool Grid::isCellOutside(int row, int col) {
  if (row >= 0 && row < cell_h && col >= 0 && col < cell_w)
    return false;
  return true;
}
bool Grid::isCellEmpty(int row, int col) {
  if (grid[row][col] == 0) {
    return true;
  }
  return false;
}
int Grid::ClearFullRows() {
  int lines = 0;
  for (int row = cell_h - 1; row >= 0; row--) {
    if (isRowFull(row)) {
      ClearRow(row);
      lines++;
    } else if (lines > 0) {
      MoveRowDown(row, lines);
    }
  }
  return lines;
}

bool Grid::isRowFull(int row) {
  for (int col = 0; col < cell_w; col++) {
    if (grid[row][col] == 0)
      return false;
  }
  return true;
}

void Grid::ClearRow(int row) {
  for (int col = 0; col < cell_w; col++) {
    grid[row][col] == 0;
  }
}

void Grid::MoveRowDown(int row, int steps) {
  for (int col = 0; col < cell_w; col++) {
    grid[row + steps][col] = grid[row][col];
    grid[row][col] == 0;
  }
}