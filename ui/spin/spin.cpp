#include "spin.hpp"

Spin::Spin() {}
Spin::~Spin() {}

void Spin::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  SDL_RenderClear(renderer);
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopyEx(renderer, texture, NULL, &rect, degrees, center, flip);
  // SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Spin::setAngle() {
  degrees = 10.0;
  flip = SDL_FLIP_NONE;
  center = 0;
}

void Spin::setText(TTF_Font *font, SDL_Renderer *renderer) {
  text = "Spin";
  SDL_Color fontColor = {0, 0, 0};
  surface = TTF_RenderText_Blended(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 200;
  rect.y = 210;
  rect.h = 30;
  rect.w = 400;
  SDL_FreeSurface(surface);
}
