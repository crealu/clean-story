#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Player {
public:
  Player();
  ~Player();
  void draw(SDL_Renderer *renderer);
  void update();
  void move(SDL_Event &event);

private:
  SDL_Rect pRect;
  int vel;
  int xVel;
  int yVel;
};

Player::Player() {
  SDL_Rect rect = {100, 100, 30, 30};
  pRect = rect;
  vel = 5;
  cout << "Player created \n";
}

Player::~Player() {}

void Player::draw(SDL_Renderer *renderer) {
  update();
  SDL_SetRenderDrawColor(renderer, 200, 15, 0, 255);
  SDL_RenderFillRect(renderer, &pRect);
}

void Player::update() {
  pRect.x += xVel;
  pRect.y += yVel;
}

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
