#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Menu {
public:
  Menu();
  ~Menu();
  void draw(SDL_Renderer *renderer);
  void addContents(TTF_Font *font, SDL_Renderer *renderer, const char *text, int offset);

protected:
  SDL_Rect rect;
  SDL_Texture *texture;
};

Menu::Menu() {}
Menu::~Menu() {}

void Menu::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Menu::addContents(TTF_Font *font, SDL_Renderer *renderer, const char *text, int offset) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Solid(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 20;
  rect.y = 30 + offset;
  rect.h = 30;
  rect.w = 100;
  SDL_FreeSurface(surface);
}
