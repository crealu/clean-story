#include <string>
#include <SDL2/SDL.h>

class Game {
public:
  Game();
  ~Game();
  string state;
  int running;
  int active;
  int current;
  bool near[3];
  void handleKeyDown(SDL_Event &event);
};

Game::Game():
state("home"),
running(1),
active(0),
current(0)
{
  near[0] = false;
  near[1] = false;
  near[2] = false;
}

Game::~Game() {}

void Game::handleKeyDown(SDL_Event &event) {
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
