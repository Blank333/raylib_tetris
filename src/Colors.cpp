#include "Colors.h"

Color GREEN_GHOST = Color{0, 228, 48, 100};
Color RED_GHOST = Color{230, 41, 55, 100};
Color ORANGE_GHOST = Color{255, 161, 0, 100};
Color YELLOW_GHOST = Color{253, 249, 0, 100};
Color PURPLE_GHOST = Color{200, 122, 255, 100};
Color SKYBLUE_GHOST = Color{102, 191, 255, 100};
Color BLUE_GHOST = Color{0, 121, 241, 100};

std::vector<Color> GetCellColors() {

  return {DARKGRAY, GREEN, RED, ORANGE, YELLOW, PURPLE, SKYBLUE, BLUE};
}

std::vector<Color> GetGhostColors() {

  return {DARKGRAY,     GREEN_GHOST,  RED_GHOST,     ORANGE_GHOST,
          YELLOW_GHOST, PURPLE_GHOST, SKYBLUE_GHOST, BLUE_GHOST};
}