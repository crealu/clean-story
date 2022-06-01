#include <SDL2/SDL.h>

class Hexagon {
public:
  Hexagon(int x1, int y1);
  ~Hexagon();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Vertex vertex[6];
  SDL_Color color;
};

Hexagon::Hexagon(int x1, int y1) {
  vertex[0].position.x = x1;
  vertex[0].position.y = y1;
  vertex[1].position.x = x1 + 10;
  vertex[1].position.y = y1;
  vertex[2].position.x = x1 + 20;
  vertex[2].position.y = y1 + 10;

  vertex[3].position.x = x1 + 10;
  vertex[3].position.y = y1 + 20;
  vertex[4].position.x = x1;
  vertex[4].position.y = y1 + 20;
  vertex[5].position.x = x1 - 10;
  vertex[5].position.y = y1 + 10;

  for (int i = 0; i <= 5; i++) {
    vertex[i].color.r = 255;
    vertex[i].color.g = 255;
    vertex[i].color.b = 255;
    vertex[i].color.a = 255;
  }
}

Hexagon::~Hexagon() {}

void Hexagon::draw(SDL_Renderer *renderer) {
  SDL_RenderGeometry(renderer, NULL, vertex, 3, NULL, 0);
}
