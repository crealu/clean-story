#include "dialog.hpp"

void Dialog::draw(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Dialog::setDialog(TTF_Font *font, SDL_Renderer *renderer, const char *text) {
  SDL_Color fontColor = {0, 0, 0};
  surface = TTF_RenderText_Blended(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  setRect(text);
  // if (12 * getLength(text) >= 600) {
  //    create new texture for line 2
  // }
  SDL_FreeSurface(surface);
}

int Dialog::getLength(const char *text) {
  int size = 0;
  while (text[size] != '\0') size++;
  return size;
}

void Dialog::setRect(const char *text) {
  rect.x = 25;
  rect.y = 412;
  rect.h = 20;
  rect.w = 12 * getLength(text);
}
