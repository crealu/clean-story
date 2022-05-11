#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "main.hpp"
using namespace std;

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);
  SDL_Event event;

  string state = "home";
  int running = 1;
  int active = 0;
  int current = 0;
  bool near = false;

  Player player;
  Screen screens[3];
  Home home;
  string themes[] = {"green", "red", "blue"};

  for (int s = 0; s < sizeof(themes)/sizeof(themes[0]); s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes[s]);
  }

  // Circle circle;

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

    if (state == "home") {
      home.draw(renderer);
    } else {
      screens[active].draw(renderer, near, current);
    }

    // circle.draw(renderer);
    player.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
