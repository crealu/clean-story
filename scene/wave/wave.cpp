#include "wave.hpp"

Wave::Wave(SDL_Color waveColor) {
  int p;
  pLen = 640;
  yo = 10;

  yPoints = new int[pLen];
  xPoints = new int[pLen];
  color = waveColor;

  for (p = 0; p < pLen; p++)
    xPoints[p] = p;

  float r = 0.0;
  for (p = 0, r = 0.0; p < pLen; p++, r += 0.09)
    yPoints[p] = round(20 * sin(20.0 * r/0.9));
}

Wave::~Wave() {}

void Wave::draw(SDL_Renderer *renderer) {
  yo = 10;
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  for (int ys = 0; ys < 13; ys++) {
    for (xp = 0; xp < pLen; xp++) {
      SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp] + yo);
      SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp] + yo + 1);
    }
    yo += 40;
  }
}
