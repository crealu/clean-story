#include <iostream>
#include <SDL2/SDL.h>

class WizardHat {
public:
  WizardHat(SDL_Color color);
  ~WizardHat();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Point point1;
  SDL_Point point2;
  SDL_Point point3;
  SDL_Color color;
};

WizardHat::WizardHat(SDL_Color hatColor) {
  SDL_Point p1 = {400, 150};
  SDL_Point p2 = {415, 125};
  SDL_Point p3 = {430, 150};

  point1 = p1;
  point2 = p2;
  point3 = p3;
  color = hatColor;
}

WizardHat::~WizardHat() {}

void WizardHat::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
  SDL_RenderDrawLine(renderer, point2.x, point2.y, point3.x, point3.y);
  SDL_RenderDrawLine(renderer, point3.x, point3.y, point1.x, point1.y);
}

class Wizard {
public:
  Wizard(SDL_Color wizardColor);
  ~Wizard();
  void draw(SDL_Renderer *renderer);
  void move(bool near);
  position getPosition();

protected:
  WizardHat *wizardHat;
  SDL_Rect pRect;
  SDL_Color color;
  int speed;
};

Wizard::Wizard(SDL_Color wizardColor) {
  SDL_Rect rect = {400, 150, 30, 30};
  pRect = rect;
  wizardHat = new WizardHat(wizardColor);
  color = wizardColor;
  speed = 2;
}

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(renderer, &pRect);
  wizardHat->draw(renderer);
}

void Wizard::move(bool near) {
  if (!near) {
    pRect.x -= speed;
    if (pRect.x <= 300)
      speed = -speed;
    if (pRect.x >= 500)
      speed = -speed;
  }
}

position Wizard::getPosition() {
  position pos = {pRect.x, pRect.y};
  return pos;
}
