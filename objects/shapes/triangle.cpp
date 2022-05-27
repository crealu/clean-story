#include <iostream>
#include <SDL2/SDL.h>

class Triangle {
public:
  Triangle(SDL_Color color);
  ~Triangle();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Point point1;
  SDL_Point point2;
  SDL_Point point3;
  SDL_Color color;
};

Triangle::Triangle(SDL_Color hatColor) {
  SDL_Point p1 = {400, 150};
  SDL_Point p2 = {415, 125};
  SDL_Point p3 = {430, 150};

  point1 = p1;
  point2 = p2;
  point3 = p3;
  color = hatColor;
}

Triangle::~Triangle() {}

void Triangle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
  SDL_RenderDrawLine(renderer, point2.x, point2.y, point3.x, point3.y);
  SDL_RenderDrawLine(renderer, point3.x, point3.y, point1.x, point1.y);
}
