#include "UI.h"

UI::UI(int cellSize, int cell_w, int cell_h, int speed, int padding,
       int interface)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h), speed(speed),
      padding(padding), interface(interface) {
  center = cell_w * cellSize + interface * cellSize / 2 - 40;
}

void UI::Draw(int score, Block nextBlock) {
  DrawText("SCORE", center, cellSize * 2, 30, WHITE);
  DrawRectangleRounded({(float)center - 75, (float)cellSize * 3,
                        (float)cellSize * 8, (float)cellSize},
                       0.5, 2, DARKGRAY);
  const char *scoreStr = TextFormat("%d", score);
  int scoreSize = MeasureText(scoreStr, 30);

  DrawText(scoreStr, center - 75 + cellSize * 4 - scoreSize / 2,
           cellSize * 3 + 2, 30, WHITE);

  DrawText("NEXT BLOCK", center - 50, cellSize * 6, 30, WHITE);
  DrawRectangleRounded({(float)center - 75, (float)cellSize * 7,
                        (float)cellSize * 8, (float)cellSize * 4},
                       0.5, 2, DARKGRAY);

  switch (nextBlock.id) {
  case 3:
    nextBlock.Draw(cell_w * cellSize + cellSize / 2,
                   cellSize * 8 + cellSize / 2);
    break;
  case 4:
    nextBlock.Draw(cell_w * cellSize + cellSize / 2, cellSize * 8);
    break;
  default:
    nextBlock.Draw(cell_w * cellSize + cellSize, cellSize * 8);
    break;
  }
}
