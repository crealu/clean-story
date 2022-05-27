#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Home {
public:
  Home();
  ~Home();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

protected:
  SDL_Rect rect;
  SDL_Surface *surface;
  SDL_Texture *texture;
  const char *text;
};

Home::Home() {}
Home::~Home() {}

void Home::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  SDL_RenderClear(renderer);
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Home::setText(TTF_Font *font, SDL_Renderer *renderer) {
  text = "Press Spacebar To Begin";
  SDL_Color fontColor = {0, 0, 0};
  surface = TTF_RenderText_Blended(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 200;
  rect.y = 210;
  rect.h = 30;
  rect.w = 400;
  SDL_FreeSurface(surface);
}
