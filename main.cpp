#include <SDL2/SDL.h>
#include "main.hpp"
#include "entity.cpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

void drawBackground(SDL_Renderer *renderer);
int quitGame(int running, SDL_Window *window, SDL_Event &event);
void checkVicinity(Player player, Wizard wizard, SDL_Event &event);

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;

  window = SDL_CreateWindow("Game Window",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  int running = 1;
  Player player(100, 100);
  Wizard wizard(200, 200);

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
      player.move(event);
      checkVicinity(player, wizard, event);
    }

    drawBackground(renderer);
    player.draw(renderer);
    wizard.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
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

void drawBackground(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void checkVicinity(Player player, Wizard wizard, SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_a) {
      player.getPos();
      wizard.getPos();
    }
  }
}
