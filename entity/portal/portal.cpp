#include "portal.hpp"

Portal::Portal() {
  hexagon = new Hexagon(100, 100);
}

Portal::~Portal() {}

void Portal::draw(SDL_Renderer *renderer) {
  hexagon->draw(renderer);
}

pos Portal::getPosition() {
  pos position = {
    hexagon->vertex[0].position.x,
    hexagon->vertex[0].position.y
  };
  return position;
}
