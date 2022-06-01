#include <iostream>
#include <SDL2/SDL.h>
#include "shapes/triangle.cpp"

// class WizardHat {
// public:
//   WizardHat(SDL_Color color);
//   ~WizardHat();
//   void draw(SDL_Renderer *renderer);
//
// protected:
//   SDL_Vertex vertex[3];
//   SDL_Color color;
// };
//
// WizardHat::WizardHat(SDL_Color hatColor) {
//   vertex[0].position.x = 400;
//   vertex[0].position.y = 150;
//   vertex[0].color.r = 0;
//   vertex[0].color.g = 0;
//   vertex[0].color.b = 0;
//   vertex[0].color.a = 255;
//
//   vertex[1].position.x = 415;
//   vertex[1].position.y = 125;
//   vertex[1].color.r = hatColor.r;
//   vertex[1].color.g = hatColor.g;
//   vertex[1].color.b = hatColor.b;
//   vertex[1].color.a = 255;
//
//   vertex[2].position.x = 430;
//   vertex[2].position.y = 150;
//   vertex[2].color.r = 255;
//   vertex[2].color.g = 255;
//   vertex[2].color.b = 255;
//   vertex[2].color.a = 255;
//   color = hatColor;
// }
//
// WizardHat::~WizardHat() {}
//
// void WizardHat::draw(SDL_Renderer *renderer) {
//   SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//   SDL_RenderGeometry(renderer, NULL, vertex, 3, NULL, 0);
// }

class Wizard {
public:
  Wizard(SDL_Color wizardColor);
  ~Wizard();
  void draw(SDL_Renderer *renderer);
  void move(bool near);
  position getPosition();

protected:
  FilledTriangle *wizardHat;
  SDL_Rect pRect;
  SDL_Color color;
  int speed;
};

Wizard::Wizard(SDL_Color wizardColor) {
  SDL_Rect rect = {400, 150, 30, 30};
  pRect = rect;
  wizardHat = new FilledTriangle(wizardColor, 100, 120);
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
