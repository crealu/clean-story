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
};

Wave::Wave() {
  int p;
  pLen = 640;

  yPoints = new int[pLen];
  xPoints = new int[pLen];

  for (p = 0; p < pLen; p++)
    xPoints[p] = p;

  float r = 0.0;
  for (p = 0, r = 0.0; p < pLen; p++, r += 0.09)
    yPoints[p] = round(20 * sin(r/1.0)) + 100;
}

Wave::~Wave() {}

void Wave::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < pLen; xp++) {
    SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp]);
    SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints[xp] + 10);
  }
}
