#ifndef UI_H
#define UI_H
#include <raylib.h>

class UI {
private:
  int cellSize, cell_w, cell_h, speed, padding, interface, center;

public:
  UI(int cellSize, int cell_w, int cell_h, int speed, int padding,
     int interface);
  void Draw();
};

#endif