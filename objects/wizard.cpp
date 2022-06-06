#include <iostream>
#include <SDL2/SDL.h>
#include "shapes/triangle.cpp"

class Hat {
public:
  Hat(SDL_Color wizardColor);
  ~Hat();
  bool collected;
  FilledTriangle *shape;
  void updateStatus();
};

Hat::Hat(SDL_Color wizardColor) {
  shape = new FilledTriangle(wizardColor, 100, 170);
  collected = false;
}

Hat::~Hat() {}

void Hat::updateStatus() {
  collected = true;
}

class Wizard {
public:
  Wizard(SDL_Color wizardColor);
  ~Wizard();
  void draw(SDL_Renderer *renderer, bool near);
  void move();
  pos getHatPosition();
  pos getPosition();
  Hat *hat;

protected:
  SDL_Rect pRect;
  SDL_Color color;
  int speed;
  bool pause;
  int t0;
  int t1;
};

Wizard::Wizard(SDL_Color wizardColor) {
  SDL_Rect rect = {400, 150, 30, 30};
  pRect = rect;
  hat = new Hat(wizardColor);
  color = wizardColor;
  speed = 2;
  t0 = 0;
  pause = false;
}

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer, bool near) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(renderer, &pRect);
  if (!near && !pause)
    move();
  if (!hat->collected)
    hat->shape->draw(renderer);
}

void Wizard::move() {
  pRect.x -= speed;

  if (pRect.x <= 300) {
    pause = true;
    t0 = SDL_GetTicks() / 1000;
    t1 = t0 + 3;
    while (t0 < t1) {
      t0 = SDL_GetTicks() / 1000;
    }
    pause = false;
    speed = -speed;
  }

  if (pRect.x >= 500) {
    speed = -speed;
  }
}

pos Wizard::getPosition() {
  pos pos = {pRect.x, pRect.y};
  return pos;
}

pos Wizard::getHatPosition() {
  pos pos = {hat->shape->vertex[0].position.x, hat->shape->vertex[0].position.y};
  return pos;
}
