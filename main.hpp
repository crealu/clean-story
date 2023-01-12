#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "common/structs.hpp"
#include "display/screen/screen.cpp"
#include "display/theme/theme.cpp"
#include "ui/menu/menu.cpp"
#include "ui/home/home.cpp"
#include "ui/spin/spin.cpp"
#include "ui/button/button.cpp"
#include "sound/music/music.cpp"
#include "objects/game/game.cpp"
#include "objects/story/story.cpp"
#include "entity/player/player.cpp"
// #include "entity/wizard/wizard.cpp"
// #include "entity/portal/portal.cpp"

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
