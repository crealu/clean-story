#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "components/player.cpp"
#include "components/circle.cpp"
#include "components/screen.cpp"
#include "components/home.cpp"
#include "components/menu.cpp"
#include "components/button.cpp"

int quitGame(int running, SDL_Window *window, SDL_Event &event);
int quitGame(int running, SDL_Window *window, SDL_Event &event) {
  switch (event.type) {
    case SDL_QUIT:
    case SDL_WINDOWEVENT_CLOSE:
      running = 0;
      if (window)
        window = NULL;
      break;
  }
  return running;
}

void checkFontError(TTF_Font *font);
void checkFontError(TTF_Font *font) {
  if (!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }
}

SDL_Window *initWindow(const char *title, int width, int height);
SDL_Window *initWindow(const char *title, int width, int height) {
  SDL_Window *window = SDL_CreateWindow(
    title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width,
    height,
    0
  );
  return window;
}

SDL_Renderer *initRenderer(SDL_Window *window);
SDL_Renderer *initRenderer(SDL_Window *window) {
  SDL_Renderer *renderer;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  return renderer;
}

int getLength(string str);
int getLength(string str) {
  int size = sizeof(str)/sizeof(str[0]);
  return size;
}
