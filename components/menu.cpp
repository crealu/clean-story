#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Menu {
public:
  Menu();
  ~Menu();
  void draw(SDL_Renderer *renderer);
  void addContents(TTF_Font *font, SDL_Renderer *renderer, const char *text[]);

protected:
  SDL_Rect rect[4];
  SDL_Texture *texture[4];
};

Menu::Menu() {}
Menu::~Menu() {}

void Menu::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
  SDL_RenderClear(renderer);
  for (int i = 0; i <= 3; i++) {
    SDL_RenderCopy(renderer, texture[i], NULL, &rect[i]);
  }
}

void Menu::addContents(TTF_Font *font, SDL_Renderer *renderer, const char *text[]) {
  for (int i = 0; i <= 3; i++) {
    SDL_Color fontColor = {0, 0, 0};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text[i], fontColor);
    texture[i] = SDL_CreateTextureFromSurface(renderer, surface);
    rect[i].x = 20;
    rect[i].y = 30 + (30 * i);
    rect[i].h = 30;
    int size = 0;
    while (text[i][size] != '\0') size++;
    rect[i].w = size * 16;
    size = 0;
    SDL_FreeSurface(surface);
  }
}
