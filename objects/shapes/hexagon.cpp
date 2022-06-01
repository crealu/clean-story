#include <SDL2/SDL.h>

class Hexagon {
public:
  Hexagon(int x1, int y1);
  ~Hexagon();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Vertex vertex[12];
  SDL_Color color;
};

Hexagon::Hexagon(int x1, int y1) {
  int sideLength = 10;
  int sideLength2 = sideLength * 2;

  vertex[0].position.x = x1;
  vertex[0].position.y = y1;
  vertex[1].position.x = x1 + sideLength;
  vertex[1].position.y = y1;
  vertex[2].position.x = x1 + sideLength2;
  vertex[2].position.y = y1 + sideLength;

  vertex[3].position.x = x1 + sideLength;
  vertex[3].position.y = y1 + sideLength2;
  vertex[4].position.x = x1;
  vertex[4].position.y = y1 + sideLength2;
  vertex[5].position.x = x1 - sideLength;
  vertex[5].position.y = y1 + sideLength;

  vertex[6].position.x = x1;
  vertex[6].position.y = y1;
  vertex[7].position.x = x1 - sideLength;
  vertex[7].position.y = y1 + sideLength;
  vertex[8].position.x = x1 + sideLength2;
  vertex[8].position.y = y1 + sideLength;

  vertex[9].position.x = x1 - sideLength;
  vertex[9].position.y = y1 + sideLength;
  vertex[10].position.x = x1 + sideLength2;
  vertex[10].position.y = y1 + sideLength;
  vertex[11].position.x = x1 + sideLength;
  vertex[11].position.y = y1 + sideLength2;

  for (int i = 0; i <= 11; i++) {
    vertex[i].color.r = 255;
    vertex[i].color.g = 255;
    vertex[i].color.b = 255;
    vertex[i].color.a = 255;
  }
}

Hexagon::~Hexagon() {}

void Hexagon::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderGeometry(renderer, NULL, vertex, 12, NULL, 0);
}
