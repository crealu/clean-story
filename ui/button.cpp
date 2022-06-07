#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

class Button {
public:
  Button();
  ~Button();
  void draw(SDL_Renderer *renderer);
  void drawContainer(SDL_Renderer *renderer);
  void drawCircle(SDL_Renderer *renderer);
  void drawText(SDL_Renderer *renderer);
  void setText(TTF_Font *font, const char *text[], SDL_Renderer *renderer);

private:
  int x;
  int y;
  int radius;
  SDL_Texture *circleTexture;
  SDL_Texture *textTexture;
  SDL_Surface *circleSurface;
  SDL_Surface *textSurface;
  SDL_Rect containerRect;
  SDL_Rect circleRect;
  SDL_Rect textRect;
};

Button::Button() {
  x = 300;
  y = 390;
  radius = 16;
  int offset = 20;
  SDL_Rect cRect = {x - offset, y - offset, 90, 40};
  containerRect = cRect;
}

Button::~Button() {}

void Button::draw(SDL_Renderer *renderer) {
  drawContainer(renderer);
  drawCircle(renderer);
  drawText(renderer);
}

void Button::drawCircle(SDL_Renderer *renderer) {
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
  SDL_QueryTexture(circleTexture, NULL, NULL, &circleRect.w, &circleRect.h);
  SDL_RenderCopy(renderer, circleTexture, NULL, &circleRect);
}

void Button::drawContainer(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &containerRect);
}

void Button::drawText(SDL_Renderer *renderer) {
  SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
  SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}

void Button::setText(TTF_Font *font, const char *text[], SDL_Renderer *renderer) {
  SDL_Color circleFontColor = {255, 255, 255};
  circleSurface = TTF_RenderText_Blended(font, text[0], circleFontColor);
  circleTexture = SDL_CreateTextureFromSurface(renderer, circleSurface);
  circleRect.x = x - 9;
  circleRect.y = y - 9;
  circleRect.h = 14;
  circleRect.w = 14;
  SDL_FreeSurface(circleSurface);

  SDL_Color textFontColor = {0, 0, 0};
  textSurface = TTF_RenderText_Blended(font, text[1], textFontColor);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  textRect.x = x + 20;
  textRect.y = y -10;
  textRect.h = 30;
  textRect.w = 20;
  SDL_FreeSurface(textSurface);
}
