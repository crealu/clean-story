#include <iostream>
#include <string>
#include <cmath>
#include <SDL2/SDL.h>
using namespace std;

class Player {
public:
  Player();
  ~Player();

  void move(SDL_Event &event);
  void draw(SDL_Renderer *renderer);
  bool getPos(int wizardX, int wizardY, SDL_Event &event);
  void update();

protected:
  SDL_Rect pRect;
  int xVel;
  int yVel;
  int vel;
  string name;
};

Player::Player() {
  SDL_Rect rect = {200, 300, 30, 30};
  pRect = rect;
  name = "Player";
  vel = 1;
  xVel = 0;
  yVel = 0;
}

Player::~Player() {}

void Player::move(SDL_Event &event) {
  int theKey;
  switch (event.type) {
    case SDL_KEYDOWN:
      theKey = event.key.keysym.sym;
      xVel = theKey == SDLK_LEFT  ? -vel : xVel;
      xVel = theKey == SDLK_RIGHT ?  vel : xVel;
      yVel = theKey == SDLK_UP    ? -vel : yVel;
      yVel = theKey == SDLK_DOWN  ?  vel : yVel;
      break;

    case SDL_KEYUP:
      theKey = event.key.keysym.sym;
      xVel = theKey == SDLK_LEFT  ?  0 : xVel;
      xVel = theKey == SDLK_RIGHT ?  0 : xVel;
      yVel = theKey == SDLK_UP    ?  0 : yVel;
      yVel = theKey == SDLK_DOWN  ?  0 : yVel;
      break;
  }
}

void Player::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 10, 15, 200, 255);
  SDL_RenderFillRect(renderer, &pRect);
  update();
}

void Player::update() {
  pRect.x += xVel;
  pRect.y += yVel;
}

bool Player::getPos(int wizardX, int wizardY, SDL_Event &event) {
  int theKey;
  switch (event.type) {
    case SDL_KEYDOWN:
      theKey = event.key.keysym.sym;
      if (theKey == SDLK_a) {
        if (abs(wizardX - pRect.x) <= 10 && abs(wizardY - pRect.y) <= 10) {
          cout << "they are near \n";
          return true;
        }
      }
      break;
  }
  return false;
}
