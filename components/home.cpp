#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Home {
public:
  Home();
  ~Home();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer, const char *text);
protected:
  SDL_Rect rect;
  // TTF_Font *font;
  SDL_Surface *surface;
  SDL_Texture *texture;
};

Home::Home() {}
Home::~Home() {}

void Home::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Home::setText(TTF_Font *font, SDL_Renderer *renderer, const char *text) {
  SDL_Color fontColor = {0, 0, 0};
  // font = TTF_OpenFont("../fonts/Comfortaa[wght].ttf", 24);
  surface = TTF_RenderText_Solid(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 125;
  rect.y = 210;
  rect.h = 30;
  rect.w = 400;
  SDL_FreeSurface(surface);
}
