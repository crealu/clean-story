#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

class Circle {
public:
  Circle();
  ~Circle();
  void draw(SDL_Renderer *renderer);

protected:
  int p;
  int xp;
  int *xPoints;
  int *yPoints;
  int cx;
  int cy;
  int pLen;
};

Circle::Circle() {
  float pn = 6.29;
  float pInc = 0.09;
  int p;

  pLen = pn / pInc;
  cx = 320;
  cy = 400;
  xPoints = new int[pLen];
  yPoints = new int[pLen];

  float r = 0.0;
  for (r = 0.0, p = 0; r <= pn; r += pInc, p++)
    if (p < pLen)
      xPoints[p] = round( 20 * (cos(r/1.0)) );

  for (r = 0.0, p = 0; r <= pn; r += pInc, p++)
    if (p < pLen)
      yPoints[p] = round( 20 * (sin(r/1.0)) );
}

Circle::~Circle() {}

void Circle::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < pLen; xp++)
    SDL_RenderDrawPoint(renderer, cx+xPoints[xp], cy+yPoints[xp]);
}

class FilledCircle {
public:
  FilledCircle();
  ~FilledCircle();
  void draw(SDL_Renderer *renderer);

private:
  int x;
  int y;
  int radius;
};

FilledCircle::FilledCircle() {
  x = 100;
  y = 100;
  radius = 20;
}
FilledCircle::~FilledCircle() {}

void FilledCircle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  for (int w = 0; w < radius * 2; w++) {
    for (int h = 0; h < radius * 2; h++) {
      int dx = radius - w;
      int dy = radius - h;
      if ((dx * dx + dy * dy) <= (radius * radius)) {
        SDL_RenderDrawPoint(renderer, x + dx, y + dy);
      }
    }
  }
}
