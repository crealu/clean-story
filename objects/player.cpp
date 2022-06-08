#include <iostream>
#include <string>
#include <cmath>
#include <SDL2/SDL.h>
#include "chunk.cpp"
using namespace std;

class Player {
public:
  Player();
  ~Player();
  void setActiveScreen(Screen activeScreen);
  void handleInput(SDL_Event &event);
  void draw(SDL_Renderer *renderer);
  void move(int key);
  void stop(int key);
  void talk(int key);
  void pickup(int key);
  void update();
  bool getVicinity(pos entityPosition);
  Screen screen;

private:
  SDL_Rect rect[3];
  int xVel;
  int yVel;
  int vel;
  string name;
  Chunk *beep;
};

Player::Player() {
  SDL_Rect rects[3] = {
    {200, 300, 30, 30},
    {200, 300, 10, 10},
    {220, 300, 10, 10}
  };

  for (int r = 0; r < 3; r++) {
    rect[r] = rects[r];
  }

  name = "Player";
  vel = 8;
  xVel = 0;
  yVel = 0;
  beep = new Chunk("./assets/audio/beep.wav");
}

Player::~Player() {}

void Player::setActiveScreen(Screen activeScreen) {
  screen = activeScreen;
}

void Player::handleInput(SDL_Event &event) {
  switch (event.type) {
    case SDL_KEYDOWN:
      move(event.key.keysym.sym);
      pickup(event.key.keysym.sym);
      break;
    case SDL_KEYUP:
      stop(event.key.keysym.sym);
      break;
  }
}

void Player::move(int key) {
  if (key == SDLK_a && (rect[0].x - vel) > 0)
    xVel = -vel;
  if (key == SDLK_d && (rect[0].x + vel) < 610)
    xVel = vel;
  if (key == SDLK_w && (rect[0].y - vel) > 0)
    yVel = -vel;
  if (key == SDLK_s && (rect[0].y + vel) < 450)
    yVel = vel;
}

void Player::stop(int key) {
  if (key == SDLK_a && (rect[0].x) > 0)
    xVel = 0;
  if (key == SDLK_d && (rect[0].x + vel) < 610)
    xVel = 0;
  if (key == SDLK_w && (rect[0].y) > 0)
    yVel = 0;
  if (key == SDLK_s && (rect[0].y + vel) < 450)
    yVel = 0;
}

void Player::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect[0]);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect[1]);
  SDL_RenderFillRect(renderer, &rect[2]);
  update();
}

void Player::update() {
  for (int rp = 0; rp < 3; rp++) {
    rect[rp].x += xVel;
    rect[rp].y += yVel;
  }
}

void Player::pickup(int key) {
  if (key == SDLK_g) {
    if (getVicinity(screen.wizard->getHatPosition())) {
      beep->play();
      screen.wizard->hat->updateStatus();
      screen.updateDialog();
      cout << "picked up hat" << endl;
    }
  }
}

bool Player::getVicinity(pos entity) {
  if (abs(entity.x - rect[0].x) <= 15 &&
      abs(entity.y - rect[0].y) <= 15)
  {
    return true;
  }
  return false;
}
