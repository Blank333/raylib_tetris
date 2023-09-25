#include "Game.h"

Game::Game(int cellSize, int cell_w, int cell_h, double speed)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h), center(cell_w / 2),
      speed(speed) {

  blocks = GetAllBlocks();
  activeBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdate = 0;
}

void Game::Draw() {
  grid.Draw();
  activeBlock.Draw();
}

void Game::Update() {
  if (eventTriggered(speed)) {
    activeBlock.move(1, 0);
  }
  Move();

  Cheats();
}
void Game::Move() {
  int key = GetKeyPressed();
  switch (key) {
  case KEY_RIGHT:
    activeBlock.moveRight();
    if (isBlockOutside())
      activeBlock.moveLeft();
    break;
  case KEY_LEFT:
    activeBlock.moveLeft();
    if (isBlockOutside())
      activeBlock.moveRight();
    break;
  case KEY_DOWN:
    activeBlock.moveDown();
    if (isBlockOutside())
      activeBlock.moveUp();
    break;
  case KEY_UP:
    activeBlock.rotate();
    if (isBlockOutside())
      activeBlock.unRotate();
    break;
  case KEY_SPACE:
    activeBlock = nextBlock;
    nextBlock = GetRandomBlock();
    break;
  }
}

bool Game::isBlockOutside() {
  std::vector<Position> tiles = activeBlock.getTiles();

  for (Position items : tiles) {
    if (grid.isCellOutside(items.row, items.col))
      return true;
  }
  return false;
}

Block Game::GetRandomBlock() {
  return blocks[GetRandomValue(0, blocks.size() - 1)];
}

std::vector<Block> Game::GetAllBlocks() {
  return {
      LBlock(center, cellSize, cell_h, cell_w),
      JBlock(center, cellSize, cell_h, cell_w),
      IBlock(center, cellSize, cell_h, cell_w),
      OBlock(center, cellSize, cell_h, cell_w),
      SBlock(center, cellSize, cell_h, cell_w),
      ZBlock(center, cellSize, cell_h, cell_w),
      TBlock(center, cellSize, cell_h, cell_w),
  };
}

bool Game::eventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdate >= interval) {
    lastUpdate = currentTime;
    return true;
  }
  return false;
}

void Game::Cheats() {
  if (IsKeyPressed(KEY_C)) {
    activeBlock = GetRandomBlock();
  }
}