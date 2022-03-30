#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

struct Position {
  int x;
  int y;
};

class Entity {
public:
  Entity(int x, int y);
  ~Entity();
  void draw(SDL_Renderer *renderer);
  void update();

protected:
  SDL_Rect pRect;
  Position pos;
  char name;
};

Entity::Entity(int x, int y) {
  pos.x = x;
  pos.y = y;
  SDL_Rect rect = {x, y, 30, 30};
  pRect = rect;
  cout << "Entity created \n";
}

Entity::~Entity() {}

void Entity::draw(SDL_Renderer *renderer) {
  update();
  SDL_SetRenderDrawColor(renderer, 200, 15, 0, 255);
  SDL_RenderFillRect(renderer, &pRect);
}

void Entity::update() {}

class Player : public Entity {
public:
  Player(int x, int y);
  ~Player();

  void move(SDL_Event &event);

protected:
  int xVel;
  int yVel;
  int vel;
};

Player::Player(int x, int y) : Entity(x, y) {
  vel = 5;
  cout << "Player created \n";
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

  pRect.x += xVel;
  pRect.y += yVel;
}

class Wizard : public Entity {
public:
  Wizard(int x, int y);
  ~Wizard();

  void speak();
};

Wizard::Wizard(int x, int y) : Entity(x, y) {
  cout << "Wizard created" << "/n";
}

Wizard::~Wizard() {}

void Wizard::speak() {
  cout << "Wizard says yo";
}
