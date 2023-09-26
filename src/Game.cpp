#include "Game.h"

Game::Game(int cellSize, int cell_w, int cell_h, double speed, int padding,
           int interface)
    : cellSize(cellSize), cell_w(cell_w), cell_h(cell_h), center(cell_w / 2),
      padding(padding), interface(interface), speed(speed), grid(padding),
      ui(cellSize, cell_w, cell_h, speed, padding, interface) {

  blocks = GetAllBlocks();
  activeBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdate = 0;
  running = true;
  score = 0;
  totalLines = 0;
  blockSpeed = 0.07;
  InitAudioDevice();
  music = LoadMusicStream("sounds/music.mp3");
  rotateBlockSound = LoadSound("sounds/rotateBlock.wav");
  placeBlockSound = LoadSound("sounds/placeBlock.wav");
  moveBlockSound = LoadSound("sounds/moveBlock.wav");
  clearLineSound = LoadSound("sounds/clearLine.wav");
  tetrisSound = LoadSound("sounds/tetris.wav");
  SetSoundPitch(tetrisSound, 1.5);
  loseSound = LoadSound("sounds/lose.wav");
  PlayMusicStream(music);
}

Game::~Game() {
  UnloadMusicStream(music);
  UnloadSound(rotateBlockSound);
  UnloadSound(placeBlockSound);
  UnloadSound(moveBlockSound);
  UnloadSound(clearLineSound);
  UnloadSound(tetrisSound);
  UnloadSound(loseSound);
  CloseAudioDevice();
}

void Game::Draw() {
  grid.Draw();
  activeBlock.Draw(padding, padding);
  ui.Draw(score, nextBlock);
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
  nextBlock = GetRandomBlock();
  score = 0;
  speed = 0.5;
  totalLines = 0;
  PlayMusicStream(music);
}
void Game::Move() {

  if (IsKeyDown(KEY_DOWN) && blockTriggered(blockSpeed)) {
    moveBlock();
    UpdateScore(0, 1);
  }

  if (IsKeyDown(KEY_RIGHT) && blockTriggered(blockSpeed)) {
    activeBlock.moveRight();
    if (isBlockOutside() || !isBlockFit())
      activeBlock.moveLeft();
    else {
      PlaySound(moveBlockSound);
    }
  }

  if (IsKeyDown(KEY_LEFT) && blockTriggered(blockSpeed)) {
    activeBlock.moveLeft();
    if (isBlockOutside() || !isBlockFit())
      activeBlock.moveRight();
    else {
      PlaySound(moveBlockSound);
    }
  }

  if (IsKeyPressed(KEY_UP)) {
    activeBlock.rotate();
    PlaySound(rotateBlockSound);
    if (isBlockOutside() || !isBlockFit())
      activeBlock.unRotate();
  }
  if (IsKeyPressed(KEY_SPACE)) {
    moveBlock();
  }
}

void Game::UpdateScore(int lines, int moves) {

  switch (lines) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 200;
    break;
  case 3:
    score += 500;
    break;
  case 4:
    score += 777;
    break;
  }
  score++;
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
  PlaySound(placeBlockSound);
  activeBlock = nextBlock;
  if (!isBlockFit()) {
    PlaySound(loseSound);
    StopMusicStream(music);
    running = false;
  }
  nextBlock = GetRandomBlock();
  int lines = grid.ClearFullRows();
  if (lines >= 4) {
    PlaySound(tetrisSound);
    PlaySound(clearLineSound);
  } else if (lines > 0) {
    PlaySound(clearLineSound);
  }
  totalLines += lines;
  UpdateScore(lines, 0);

  if (totalLines > 20 && speed > 0.1) {
    speed -= 0.01;
    totalLines = 0;
  }
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
bool Game::blockTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - blockUpdate >= interval) {
    blockUpdate = currentTime;
    return true;
  }
  return false;
}

void Game::Cheats() {
  if (IsKeyPressed(KEY_C)) {
    activeBlock = GetRandomBlock();
  }
  if (IsKeyDown(KEY_V)) {
    score += 100;
  }
}