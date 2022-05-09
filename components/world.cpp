#include <iostream>
#include <SDL2/SDL.h>

class World {
public:
  World();
  ~World();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Color *color;
};

World::World(SDL_Color color) {
  color = color;
}

World::~World() {}

void World::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(renderer);
}
