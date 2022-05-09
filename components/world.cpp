#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "wave.cpp"
#include "wizard.cpp"
using namespace std;

class World {
public:
  World();
  ~World();
  void draw(SDL_Renderer *renderer);

protected:
  int r;
  int g;
  int b;
  Wave *wave;
  Wizard *wizard;
};

World::World() {
  wave = new Wave;
  wizard = new Wizard;
}

World::~World() {}

void World::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 55, 0, 55);
  SDL_RenderClear(renderer);
  wave->draw(renderer);
  wizard->draw(renderer);
}
