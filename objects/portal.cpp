#include <SDL2/SDL.h>
#include <math.h>

class Portal {
public:
  Portal();
  ~Portal();
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

Portal::Portal() {
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

Portal::~Portal() {}

void Portal::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < pLen; xp++)
    SDL_RenderDrawPoint(renderer, cx+xPoints[xp], cy+yPoints[xp]);
}
