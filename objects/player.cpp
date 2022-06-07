#include <iostream>
#include <string>
#include <cmath>
#include <SDL2/SDL.h>
// #include "bag.cpp"
using namespace std;

class Player {
public:
  Player();
  ~Player();
  void move(SDL_Event &event);
  void draw(SDL_Renderer *renderer);
  void update();
  void pickupItem(SDL_Event &event, Screen screen, SDL_Renderer *renderer, TTF_Font *font);
  bool getVicinity(pos entityPosition);
  // Bag bag;

private:
  SDL_Rect pRect;
  SDL_Rect leftRect;
  SDL_Rect rightRect;
  int xVel;
  int yVel;
  int vel;
  string name;
  Chunk *beep;
};

Player::Player() {
  SDL_Rect rect = {200, 300, 30, 30};
  SDL_Rect lRect = {200, 300, 10, 10};
  SDL_Rect rRect = {220, 300, 10, 10};
  pRect = rect;
  leftRect = lRect;
  rightRect = rRect;
  name = "Player";
  vel = 8;
  xVel = 0;
  yVel = 0;
  beep = new Chunk("./assets/audio/beep.wav");
}

Player::~Player() {}

void Player::move(SDL_Event &event) {
  int theKey;
  switch (event.type) {
    case SDL_KEYDOWN:
      theKey = event.key.keysym.sym;
      if (theKey == SDLK_a && (pRect.x - vel) > 0)
        xVel = -vel;
      if (theKey == SDLK_d && (pRect.x + vel) < 610)
        xVel = vel;
      if (theKey == SDLK_w && (pRect.y - vel) > 0)
        yVel = -vel;
      if (theKey == SDLK_s && (pRect.y + vel) < 450)
        yVel = vel;
      break;

    case SDL_KEYUP:
      theKey = event.key.keysym.sym;
      if (theKey == SDLK_a && (pRect.x) > 0)
        xVel = 0;
      if (theKey == SDLK_d && (pRect.x + vel) < 610)
        xVel = 0;
      if (theKey == SDLK_w && (pRect.y) > 0)
        yVel = 0;
      if (theKey == SDLK_s && (pRect.y + vel) < 450)
        yVel = 0;
      break;
  }
}

void Player::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderFillRect(renderer, &pRect);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &leftRect);
  SDL_RenderFillRect(renderer, &rightRect);
  update();
}

void Player::update() {
  pRect.x += xVel;
  leftRect.x += xVel;
  rightRect.x += xVel;
  pRect.y += yVel;
  leftRect.y += yVel;
  rightRect.y += yVel;
}

void Player::pickupItem(SDL_Event &event, Screen screen, SDL_Renderer *renderer, TTF_Font *font) {
  switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_g) {
        if (getVicinity(screen.wizard->getHatPosition())) {
          beep->play();
          screen.wizard->hat->updateStatus();
          screen.updateDialog(font, renderer);
          cout << "picked up hat" << endl;
        }
      }
      break;
  }
}

bool Player::getVicinity(pos entity) {
  if (abs(entity.x - pRect.x) <= 15 && abs(entity.y - pRect.y) <= 15) {
    return true;
  } else {
    return false;
  }
  return false;
}
