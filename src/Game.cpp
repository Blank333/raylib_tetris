#include "Game.h"

Game::Game(int cellSize, int cell_w, int cell_h, double speed, int padding)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h), center(cell_w / 2),
      padding(padding), speed(speed), grid(padding) {

  blocks = GetAllBlocks();
  activeBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdate = 0;
  running = true;
}

void Game::Draw() {
  grid.Draw();
  activeBlock.Draw();
}

void Game::Update() {

  if (!running) {
    DrawText("GAME OVER\nPress R to Restart", center * cellSize - 50,
             cellSize * cell_h / 2 - 50, 40, WHITE);
    if (IsKeyPressed(KEY_R)) {
      Reset();
    }
    return;
  }
  if (eventTriggered(speed)) {
    moveBlock();
  }

  Move();

  Cheats();
}
void Game::Reset() {
  running = true;
  grid.Initialize();
  activeBlock = GetRandomBlock();
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
  if (!isBlockFit()) {
    running = false;
  }
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
      LBlock(center, cellSize, cell_h, cell_w, padding),
      JBlock(center, cellSize, cell_h, cell_w, padding),
      IBlock(center, cellSize, cell_h, cell_w, padding),
      OBlock(center, cellSize, cell_h, cell_w, padding),
      SBlock(center, cellSize, cell_h, cell_w, padding),
      ZBlock(center, cellSize, cell_h, cell_w, padding),
      TBlock(center, cellSize, cell_h, cell_w, padding),
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