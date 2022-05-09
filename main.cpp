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

  window = SDL_CreateWindow("Game Window",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT, 0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!theFont) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  int current = 2;
  StoryScript green;
  Dialog theDialog[10];
  for (int i = 0; i < 10; i++) {
    theDialog[i].setDialog(theFont, renderer, green.getText(i));
  }
  // TextBox textbox(theFont, renderer, green.getText(current), 200, 200);
  World world;
  Wave wave;
  Circle circle;
  Player player;
  Wizard wizard;

  int wizardX = wizard.getX();
  int wizardY = wizard.getY();
  bool near = false;

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
      player.move(event);
      if (!near) {
        near = player.getPos(wizardX, wizardY, event);
      }

      switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
          if (event.button.button == SDL_BUTTON_LEFT)
            near = !near;
          break;

        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_m && current != 10) {
            current++;
          }

          if (event.key.keysym.sym == SDLK_n && current != 0) {
            current--;
          }
          break;
      }
    }

    world.draw(renderer);
    circle.draw(renderer);
    wave.draw(renderer);
    wizard.draw(renderer);
    player.draw(renderer);

    if (near)
      theDialog[current].draw(renderer);
    //
    // if (near)
    //   textbox.draw(renderer);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  // SDL_DestroyTexture(textureText);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
