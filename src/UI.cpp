#include "UI.h"

UI ::UI(int cellSize, int cell_w, int cell_h, int speed, int padding,
        int interface)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h), speed(speed),
      padding(padding), interface(interface) {
  center = cell_w * cellSize + interface * cellSize / 2 - 25;
}

void UI::Draw() {
  DrawText("SCORE", center, cellSize * 2, 20, WHITE);
  DrawRectangleRounded({(float)center - 30, (float)cellSize * 3,
                        (float)cellSize * 4, (float)cellSize},
                       0.5, 2, PURPLE);

  DrawText("NEXT BLOCK", center - 30, cellSize * 6, 20, WHITE);
  DrawRectangleRounded({(float)center - 30, (float)cellSize * 7,
                        (float)cellSize * 4, (float)cellSize * 4},
                       0.5, 2, PURPLE);
}
