#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
using namespace std;

class Wave {
public:
  Wave();
  ~Wave();

  void draw(SDL_Renderer *renderer);

protected:
  int *xPoints;
  int *yPoints;
  int pLen;
  int xp;
  int yo;
};

Wave::Wave() {
  int p;
  pLen = 640;
  yo = 10;

  yPoints = new int[pLen];
  xPoints = new int[pLen];

  for (p = 0; p < pLen; p++)
    xPoints[p] = p;

  float r = 0.0;
  for (p = 0, r = 0.0; p < pLen; p++, r += 0.09)
    yPoints[p] = round(20 * sin(20.0 * r/0.9));
}

Wave::~Wave() {}

void Wave::draw(SDL_Renderer *renderer) {
  yo = 10;
  SDL_SetRenderDrawColor(renderer, 55, 255, 55, 255);
  for (int ys = 0; ys < 13; ys++) {
    for (xp = 0; xp < pLen; xp++) {
      SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp] + yo);
      SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp] + yo + 1);
    }
    yo += 40;
  }
}
