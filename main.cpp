#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "components/entity.cpp"
#include "components/player.cpp"
#include "components/ui.cpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

void drawBackground(SDL_Renderer *renderer);
int quitGame(int running, SDL_Window *window, SDL_Event &event);
void checkVicinity(Player player, Wizard wizard, SDL_Event &event);

class TestClass {
public:
  void doPrint();
private:
  int num;
}

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;

  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);

  window = SDL_CreateWindow("Game Window",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!theFont) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  const char *hello = "hello";
  const char *world = "world";

  int running = 1;
  Player player(200, 300);
  Wizard wizard(200, 200);
  Wizard wizard2(200, 250);

  TextBox allBoxes[10];
  cout << allBoxes[0];
  // for (int i = 0; i < 10; i++) {
  //   allBoxes[i]
  //   TextBox aTextBox(theFont, renderer, hello, i * 10, i * 10);
  //   allBoxes[i] = aTextBox;
  // }
  TextBox textbox(theFont, renderer, hello, 10, 10);
  TextBox textbox1(theFont, renderer, world, 10, 50);

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
    }

    drawBackground(renderer);

    player.draw(renderer);
    wizard.draw(renderer);
    wizard2.draw(renderer);
    textbox.draw(renderer);
    textbox1.draw(renderer);

    // for (int j = 0; j < 9; j++) {
    //   allBoxes[j].draw(renderer);
    // }
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
