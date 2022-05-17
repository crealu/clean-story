#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

class Button {
public:
  Button();
  ~Button();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

protected:
  int p;
  int xp;
  int *xPoints;
  int *yPoints;
  int cx;
  int cy;
  int pLen;
  SDL_Texture *texture;
  SDL_Rect rect;
};

Button::Button() {
  float pn = 6.29;
  float pInc = 0.09;
  int p;
  pLen = pn / pInc;

  cx = 40;
  cy = 460;

  xPoints = new int[pLen];
  yPoints = new int[pLen];

  float r = 0.0;
  for (r = 0.0, p = 0; r <= pn; r += pInc, p++)
    if (p < pLen)
      xPoints[p] = round( 20 * (cos(r/1.0)) );

  for (r = 0.0, p = 0; r <= pn; r += pInc, p++)
    if (p < pLen)
      yPoints[p] = round( 20 * (sin(r/1.0)) );
};

Button::~Button() {}

void Button::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < pLen; xp++)
    SDL_RenderDrawPoint(renderer, cx+xPoints[xp], cy+yPoints[xp]);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Button::setText(TTF_Font *font, SDL_Renderer *renderer) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Solid(font, "M", fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 20;
  rect.y = 400;
  rect.h = 30;
  rect.w = 20;
  SDL_FreeSurface(surface);
}
