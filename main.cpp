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
  string themes[] = {"green", "red", "blue"};
  for (int s = 0; s < sizeof(themes)/sizeof(themes[0]); s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes[s]);
  }

  Home home;
  home.setText(theFont, renderer, "Press Spacebar To Begin");

  const char *controls[] = {
    "A - left",
    "D - right",
    "W - forward",
    "S - back",
    "",
    "N - talk (back)",
    "M - talk (forward)",
    "Click - display text"
  };

  Menu menu;
  menu.addContents(theFont, renderer, controls);
  Button button;
  button.setText(theFont, renderer);

  int wizardX = screens[active].wizard->getX();
  int wizardY = screens[active].wizard->getY();
  int playerX = player.getPosition()->x;
  int playerY = player.getPosition()->y;

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
      player.move(event);
      near = player.getVicinity(wizardX, wizardY, event, near);
      current = screens[active].setCurrent(event, current);
      // home.setState(event, state);

      switch (event.type) {
        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_y && active != 2)
            active++;
          if (event.key.keysym.sym == SDLK_t && active != 0)
            active--;
          if (event.key.keysym.sym == SDLK_SPACE)
            state = "play";
          if (event.key.keysym.sym == SDLK_RETURN) {
            if (state == "menu")
              state = "play";
            else
              state = "menu";
          }
          break;
      }
    }

    if (state == "home") {
      home.draw(renderer);
    } else if (state == "menu") {
      menu.draw(renderer);
    } else {
      screens[active].draw(renderer, near, current);
    }

    if (near)
      button.draw(renderer);

    player.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
