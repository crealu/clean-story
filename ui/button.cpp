#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

class Button {
public:
  Button();
  ~Button();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

private:
  int x;
  int y;
  int radius;
  SDL_Texture *texture;
  SDL_Rect rect;
};

Button::Button() {
  x = 605;
  y = 390;
  radius = 16;
}

Button::~Button() {}

void Button::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  for (int w = 0; w < radius * 2; w++) {
    for (int h = 0; h < radius * 2; h++) {
      int dx = radius - w;
      int dy = radius - h;
      if ((dx * dx + dy * dy) <= (radius * radius)) {
        SDL_RenderDrawPoint(renderer, x + dx, y + dy);
      }
    }
  }

  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Button::setText(TTF_Font *font, SDL_Renderer *renderer) {
  SDL_Color fontColor = {255, 255, 255};
  SDL_Surface *surface = TTF_RenderText_Blended(font, "M", fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = x - 9;
  rect.y = y - 9;
  rect.h = 14;
  rect.w = 14;
  SDL_FreeSurface(surface);
}

// void Button::drawCircle(SDL_Renderer *renderer, int x, int y, int radius) {
//   SDL_SetRenderDrawColor(renderer, 155, 155, 155, 155);
//   for (int w = 0; w < radius * 2; w++) {
//     for (int h = 0; h < radius * 2; h++) {
//       int dx = radius - w; // horizontal offset
//       int dy = radius - h; // vertical offset
//       if ((dx * dx + dy * dy) <= (radius * radius)) {
//         SDL_RenderDrawPoint(renderer, x + dx, y + dy);
//       }
//     }
//   }
// }
//
// void draw_circle(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color)
// {
//   SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//   for (int w = 0; w < radius * 2; w++)
//   {
//       for (int h = 0; h < radius * 2; h++)
//       {
//           int dx = radius - w; // horizontal offset
//           int dy = radius - h; // vertical offset
//           if ((dx*dx + dy*dy) <= (radius * radius))
//           {
//               SDL_RenderDrawPoint(renderer, x + dx, y + dy);
//           }
//       }
//   }
// }
