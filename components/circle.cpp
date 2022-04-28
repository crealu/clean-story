#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
using namespace std;

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
}

Circle::Circle() {
  float pn = 6.29;
  float pInc = 0.01;
  int p, pLen;
  pLen = pn / pInc;

  cx = 320;
  cy = 240;

  xPoints = new int[pLen];
  yPoints = new int[pLen];

  float r = 0.0;
  for (r = 0.0, p = 0; r <= pn; r += pinc, p++)
    if (p < plen)
      xpoints[p] = round( 20 * (cos(r/1.0)) );

  for (r = 0.0, p = 0; r <= pn; r += pinc, p++)
    if (p < plen)
      ypoints[p] = round( 20 * (sin(r/1.0)) );
}

Circle::~Circle() {}

void Circle::draw(SDL_Renderer *renderer) {
  for (xp = 0; xp < plen; xp++)
    SDL_RenderDrawPoint(renderer, cx+xPoints[xp], cy+yPoints[xp]);
}
