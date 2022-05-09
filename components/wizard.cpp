#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class Wizard {
public:
  Wizard(int x, int y);
  ~Wizard();
  void draw(SDL_Renderer *renderer);
  void speak();
  int getX();
  int getY();

protected:
  SDL_Rect pRect;
  string name;
};

Wizard::Wizard() {
  SDL_Rect rect = {400, 200, 30, 30};
  pRect = rect;
  name = "Wizard";
  cout << "Wizard created" << "/n";
}

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 15, 0, 255);
  SDL_RenderFillRect(renderer, &pRect);
}

void Wizard::speak() {
  cout << "Wizard says yo";
}

int Wizard::getX() {
  return pRect.x;
}

int Wizard::getY() {
  return pRect.y;
}
