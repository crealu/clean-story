#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "main.hpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);
  SDL_Event event;
  int running = 1;

  window = SDL_CreateWindow("Clean Story",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT, 0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!theFont) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  int active = 0;
  int current = 0;
  bool near = false;

  string themes[] = {"green", "red", "blue"};
  Screen screens[3];
  for (int s = 0; s < sizeof(themes)/sizeof(themes[0]); s++) {
    // screens[s] = new Screen;
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes[s]);
  }
  // Screen screen;
  // screen.prepareDialog(theFont, renderer);
  // screen.setColor("blue");
  Circle circle;
  Player player;

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
      player.move(event);
      current = screens[active].setCurrent(event, current);

      switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
          if (event.button.button == SDL_BUTTON_LEFT)
            near = !near;
          break;

        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_y && active != 2)
            active++;
          if (event.key.keysym.sym == SDLK_t && active != 0)
            active--;
          break;
      }
    }

    screens[active].draw(renderer, near, current);
    circle.draw(renderer);
    player.draw(renderer);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  // SDL_DestroyTexture(textureText);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
