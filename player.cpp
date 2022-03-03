#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Player
{
public:
  Player();
  ~Player();
  void move(SDL_Event event);
  void stop(SDL_Event event);
  void update(SDL_Rect *rect);

protected:
  int velocity;
  int xVel;
  int yVel;
};

Player::Player()
{
  velocity = 5.0;
  cout << "Player created \n";
}

Player::~Player() {}

void Player::move(SDL_Event event)
{
  if (event.key.keysym.sym == SDLK_LEFT)
    xVel = -velocity;
  if (event.key.keysym.sym == SDLK_RIGHT)
    xVel = velocity;
  if (event.key.keysym.sym == SDLK_UP)
    yVel = -velocity;
  if (event.key.keysym.sym == SDLK_DOWN)
    yVel = velocity;

  cout << event.type;
}

void Player::stop(SDL_Event event)
{
  if (event.key.keysym.sym == SDLK_LEFT)
    xVel = 0;
  if (event.key.keysym.sym == SDLK_RIGHT)
    xVel = 0;
  if (event.key.keysym.sym == SDLK_UP)
    yVel = 0;
  if (event.key.keysym.sym == SDLK_DOWN)
    yVel = 0;
}

void Player::update(SDL_Rect *rect)
{
  rect->x += xVel;
  rect->y += yVel;
}
