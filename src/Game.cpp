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
    moveBlock();
  }
  Move();

  Cheats();
}
void Game::Move() {
  int key = GetKeyPressed();
  switch (key) {
  case KEY_RIGHT:
    activeBlock.moveRight();
    if (isBlockOutside() || !isBlockFit())
      activeBlock.moveLeft();
    break;
  case KEY_LEFT:
    activeBlock.moveLeft();
    if (isBlockOutside() || !isBlockFit())
      activeBlock.moveRight();
    break;
  case KEY_DOWN:
    moveBlock();
    break;
  case KEY_UP:
    activeBlock.rotate();
    if (isBlockOutside() || !isBlockFit())
      activeBlock.unRotate();
    break;
  case KEY_SPACE:
    moveBlock();
    break;
  }
}

void Game::moveBlock() {
  activeBlock.moveDown();
  if (isBlockOutside() || !isBlockFit()) {
    activeBlock.moveUp();
    LockBlock();
  }
}

void Game::LockBlock() {
  std::vector<Position> tiles = activeBlock.getTiles();
  for (Position item : tiles) {
    grid.grid[item.row][item.col] = activeBlock.id;
  }
  activeBlock = nextBlock;
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::isBlockFit() {
  std::vector<Position> tiles = activeBlock.getTiles();
  for (Position item : tiles) {
    if (!grid.isCellEmpty(item.row, item.col))
      return false;
  }
  return true;
}

bool Game::isBlockOutside() {
  std::vector<Position> tiles = activeBlock.getTiles();

  for (Position item : tiles) {
    if (grid.isCellOutside(item.row, item.col))
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