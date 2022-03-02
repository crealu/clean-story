#include <SDL2/SDL.h>
#include "main.hpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

void askQuestion();

int main(int arc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
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

  int running = 1;
  SDL_Event event;
  SDL_Rect rect = { 220, 140, 200, 200 };

  while (running)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          running = 0;
          break;
        case SDL_WINDOWEVENT_CLOSE:
          running = 0;
          if (window)
            window = NULL;
          break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

void askQuestions()
{
  int startWith = initialPrompt();

  if (startWith == theWorld)
  {
    World world;
    Character character;
    world.summarize();
    character.summarize();
  }
  else if (startWith == theCharacter)
  {
    Character character;
    World world;
    character.summarize();
    world.summarize();
  }

  int wantsEdit = editPrompt();
  if (wantsEdit == 'y')
  {
    while (wantsEdit == 'y')
    {
      cout << "Continue? (0) no  (1) yes ";
      cin >> wantsEdit;
    }
  }
}
