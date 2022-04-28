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
  int yPoints;
  int pLen;
  int xp;
};

Wave::Wave() {
  int p;
  pLen = 100;

  yPoints = 100;
  xPoints = new int[pLen];

  for (p = 0; p < pLen; p++)
    xPoints[p] = p;
}

Wave::~Wave() {}

void Wave::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < pLen; xp++)
    SDL_RenderDrawPoint(renderer, xPoints[xp], yPoints);
}
