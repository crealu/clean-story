#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class Wizard {
public:
  Wizard();
  ~Wizard();
  void draw(SDL_Renderer *renderer);
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
};

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 15, 200, 0, 255);
  SDL_RenderFillRect(renderer, &pRect);
}

int Wizard::getX() {
  return pRect.x;
}

int Wizard::getY() {
  return pRect.y;
}
