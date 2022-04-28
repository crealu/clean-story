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
  int *points;
}

Wave::Wave() {

}

Wave::~Wave() {}

void Wave::draw(SDL_Renderer *renderer) {
  
}
