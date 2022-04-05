#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class Entity {
public:
  Entity(int x, int y);
  ~Entity();

  void draw(SDL_Renderer *renderer);
  void update();
  void getPos();

protected:
  SDL_Rect pRect;
  string name;
};

Entity::Entity(int x, int y) {
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

void Entity::update() {

}

void Entity::getPos() {
  cout << name << ": " << pRect.x << " " << pRect.y << "\n";
}

class Wizard : public Entity {
public:
  Wizard(int x, int y);
  ~Wizard();

  void speak();
};

Wizard::Wizard(int x, int y) : Entity(x, y) {
  name = "Wizard";
  cout << "Wizard created" << "/n";
}

Wizard::~Wizard() {}

void Wizard::speak() {
  cout << "Wizard says yo";
}
