#include "Game.h"

Game::Game(int cellSize, int cell_w, int cell_h, double speed)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h),
      center(cell_w * cellSize / 2 - cellSize),
      block(center, cellSize, cell_h, cell_w), speed(speed) {
  lastUpdate = 0;
}

void Game::Draw() {
  grid.Draw();
  block.Draw();
}

void Game::Update() {
  if (eventTriggered(speed)) {
    block.Update();
  }
  Move();
}
void Game::Move() {
  if (IsKeyPressed(KEY_RIGHT) && block.getX() < cell_w * cellSize - cellSize) {
    block.moveRight();
  } else if (IsKeyPressed(KEY_LEFT) && block.getX() >= cellSize) {
    block.moveLeft();
  } else if (IsKeyPressed(KEY_DOWN)) {
    block.connect();
  }
}

bool Game::eventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdate >= interval) {
    lastUpdate = currentTime;
    return true;
  }
  return false;
}