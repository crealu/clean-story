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

class FilledTriangle {
public:
  FilledTriangle(SDL_Color color);
  ~FilledTriangle();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Vertex vertex[3];
  SDL_Color color;
};

FilledTriangle::FilledTriangle(SDL_Color hatColor, int x1, int y1) {
  vertex[0].position.x = x1;
  vertex[0].position.y = y1;
  vertex[0].color.r = 0;
  vertex[0].color.g = 0;
  vertex[0].color.b = 0;
  vertex[0].color.a = 255;

  vertex[1].position.x = x1 + 15;
  vertex[1].position.y = y1 - 25;
  vertex[1].color.r = hatColor.r;
  vertex[1].color.g = hatColor.g;
  vertex[1].color.b = hatColor.b;
  vertex[1].color.a = 255;

  vertex[2].position.x = x1 + 30;
  vertex[2].position.y = y1;
  vertex[2].color.r = 255;
  vertex[2].color.g = 255;
  vertex[2].color.b = 255;
  vertex[2].color.a = 255;
  color = hatColor;
}

FilledTriangle::~FilledTriangle() {}

void FilledTriangle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderGeometry(renderer, NULL, vertex, 3, NULL, 0);
}
