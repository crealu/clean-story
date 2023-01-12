#include "background.hpp"

Background::Background(SDL_Color BackgroundColor) {
  color = BackgroundColor;
}

Background::~Background() {}

void Background::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(renderer);
}
