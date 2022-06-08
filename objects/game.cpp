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
  void handleInput(SDL_Event &event);
  void changeState(int theKey);
  void changeWorld(int theKey);
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

void Game::handleInput(SDL_Event &event) {
  switch (event.type) {
    case SDL_KEYDOWN:
      changeState(event.key.keysym.sym);
      changeWorld(event.key.keysym.sym);
      break;
  }
}

void Game::changeState(int theKey) {
  if (theKey == SDLK_SPACE)
    state = "play";
  if (theKey == SDLK_RETURN) {
    if (state == "menu")
      state = "play";
    else
      state = "menu";
  }
}

void Game::changeWorld(int theKey) {
  if (theKey == SDLK_h && active != 2)
    active++;
  if (theKey == SDLK_t && active != 0)
    active--;
}
