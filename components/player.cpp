#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class Player {
public:
  Player();
  ~Player();

  void move(SDL_Event &event);
  void draw(SDL_Renderer *renderer);
  void update();
  void getPos();

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
  vel = 5;
  cout << "Player created \n";
}

Player::~Player() {}

void Player::move(SDL_Event &event) {
  int theKey;
  switch (event.type) {
    case SDL_KEYDOWN:
      theKey = event.key.keysym.sym;
      if (theKey == SDLK_LEFT)
        xVel = -vel;
      if (theKey == SDLK_RIGHT)
        xVel = vel;
      if (theKey == SDLK_UP)
        yVel = -vel;
      if (theKey == SDLK_DOWN)
        cout << "down pressed";
        yVel = vel;
      // xVel = theKey == SDLK_LEFT  ? -vel : xVel;
      // xVel = theKey == SDLK_RIGHT ?  vel : xVel;
      // yVel = theKey == SDLK_UP    ? -vel : yVel;
      // yVel = theKey == SDLK_DOWN  ?  vel : yVel;
      break;

    case SDL_KEYUP:
      theKey = event.key.keysym.sym;
      xVel = theKey == SDLK_LEFT  ?  0 : xVel;
      xVel = theKey == SDLK_RIGHT ?  0 : xVel;
      yVel = theKey == SDLK_UP    ?  0 : yVel;
      yVel = theKey == SDLK_DOWN  ?  0 : yVel;
      break;
  }

  pRect.x += xVel;
  pRect.y += yVel;
}

void Player::draw(SDL_Renderer *renderer) {
  update();
  SDL_SetRenderDrawColor(renderer, 10, 15, 200, 255);
  SDL_RenderFillRect(renderer, &pRect);
}

void Player::update() {
  pRect.x += xVel;
  pRect.y += yVel;
}

void Player::getPos() {
  cout << "x " << pRect.x << " y " << pRect.y;
}
