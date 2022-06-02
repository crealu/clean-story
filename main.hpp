#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "headers/structs.hpp"
#include "objects/game.cpp"
#include "objects/story.cpp"
#include "objects/player.cpp"
#include "objects/portal.cpp"
#include "objects/screen.cpp"
#include "objects/theme.cpp"
#include "objects/music.cpp"
#include "objects/chunk.cpp"
#include "ui/home.cpp"
#include "ui/menu.cpp"

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

void initialize();
void initialize() {
  SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
  TTF_Init();
  Mix_Init(MIX_INIT_MP3);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_AllocateChannels(16);
  Mix_Volume(1, MIX_MAX_VOLUME/2);
}
