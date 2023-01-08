#include "wizard.hpp"

Hat::Hat(SDL_Color wizardColor) {
  shape = new FilledTriangle(wizardColor, 100, 170);
  collected = false;
}

Hat::~Hat() {}

void Hat::updateStatus() {
  collected = true;
}

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
    // pause = true;
    // t0 = SDL_GetTicks() / 1000;
    // t1 = t0 + 3;
    // while (t0 < t1) {
    //   t0 = SDL_GetTicks() / 1000;
    // }
    // pause = false;
    speed = -speed;
  }

  if (pRect.x >= 500) {
    speed = -speed;
  }
}

pos Wizard::getPosition() {
  pos position = {pRect.x, pRect.y};
  return position;
}

pos Wizard::getHatPosition() {
  pos position = {
    hat->shape->vertex[0].position.x,
    hat->shape->vertex[0].position.y
  };
  return position;
}
