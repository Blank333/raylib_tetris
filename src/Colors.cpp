#include "Colors.h"

Color GREEN_GHOST = Color{0, 228, 48, 100};
Color RED_GHOST = Color{230, 41, 55, 100};
Color ORANGE_GHOST = Color{255, 161, 0, 100};
Color YELLOW_GHOST = Color{253, 249, 0, 100};
Color PURPLE_GHOST = Color{200, 122, 255, 100};
Color SKYBLUE_GHOST = Color{102, 191, 255, 100};
Color BLUE_GHOST = Color{0, 121, 241, 100};

std::vector<Color> GetCellColors() {

  return {DARKGRAY, ORANGE, BLUE, SKYBLUE, YELLOW, GREEN, RED, PURPLE};
}

std::vector<Color> GetGhostColors() {

  return {DARKGRAY,     ORANGE_GHOST, BLUE_GHOST, SKYBLUE_GHOST,
          YELLOW_GHOST, GREEN_GHOST,  RED_GHOST,  PURPLE_GHOST};
}