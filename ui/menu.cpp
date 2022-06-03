#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Menu {
public:
  Menu();
  ~Menu();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

protected:
  SDL_Rect rect[7];
  SDL_Surface *surface[7];
  SDL_Texture *texture[7];
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

void Menu::setText(TTF_Font *font, SDL_Renderer *renderer) {
  const char *text[] = {
    "A - left",
    "D - right",
    "W - forward",
    "S - back",
    "",
    "N - talk (back)",
    "M - talk (forward)",
    "Click - display text"
  };

  int size = 0;

  for (int i = 0; i <= 6; i++) {
    SDL_Color fontColor = {0, 0, 0};
    SDL_Surface *surface = TTF_RenderText_Blended(font, text[i], fontColor);
    texture[i] = SDL_CreateTextureFromSurface(renderer, surface);
    rect[i].x = 20;
    rect[i].y = 30 + (30 * i);
    rect[i].h = 30;
    while (text[i][size] != '\0') size++;
    rect[i].w = size * 16;
    size = 0;
    SDL_FreeSurface(surface);
  }
}
