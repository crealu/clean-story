#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "components/entity.cpp"
#include "components/player.cpp"
#include "components/ui.cpp"
#include "components/circle.cpp"
#include "components/wave.cpp"
#include "components/world.cpp"
#include "components/story.cpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

int quitGame(int running, SDL_Window *window, SDL_Event &event);

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window *window;
  SDL_Renderer *renderer;

  window = SDL_CreateWindow("Game Window",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;
  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);
  int running = 1;

  if (!theFont) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  const char *helloT = "hello";
  const char *worldT = "world";
  const char *transcript[] = { helloT, worldT };

  int current = 0;
  StoryScript green;
  TextBox textbox(theFont, renderer, green.getText(current), 200, 200);

  World world;
  Wave wave;
  Circle circle;
  Player player;
  Wizard wizard(200, 200);

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
      }
    }

    world.draw(renderer);
    circle.draw(renderer);
    wave.draw(renderer);
    wizard.draw(renderer);
    player.draw(renderer);

    if (near)
      textbox.draw(renderer);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  // SDL_DestroyTexture(textureText);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}

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
