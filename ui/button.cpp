#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

class Button {
public:
  Button();
  ~Button();
  void setup(SDL_Renderer *theRenderer, TTF_Font *theFont);
  void setText(const char *text[]);
  SDL_Rect setRect(int x, int y, int height, int width);
  void draw();
  void drawContainer();
  void drawCircle();
  void drawText();

private:
  SDL_Renderer *renderer;
  TTF_Font *font;
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

void Button::setup(SDL_Renderer *theRenderer, TTF_Font *theFont) {
  renderer = theRenderer;
  font = theFont;
}

void Button::draw() {
  drawContainer();
  drawCircle();
  drawText();
}

void Button::drawCircle() {
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

void Button::drawContainer() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &containerRect);
}

void Button::drawText() {
  SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
  SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}

void Button::setText(const char *text[]) {
  SDL_Color circleFontColor = {255, 255, 255};
  circleSurface = TTF_RenderText_Blended(font, text[0], circleFontColor);
  circleTexture = SDL_CreateTextureFromSurface(renderer, circleSurface);
  circleRect = setRect(x - 9, y - 9, 14, 14);
  SDL_FreeSurface(circleSurface);

  SDL_Color textFontColor = {0, 0, 0};
  textSurface = TTF_RenderText_Blended(font, text[1], textFontColor);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  textRect = setRect(x + 20, y - 10, 30, 20);
  SDL_FreeSurface(textSurface);
}

SDL_Rect Button::setRect(int x, int y, int height, int width) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.h = height;
  rect.w = width;
  return rect;
}
