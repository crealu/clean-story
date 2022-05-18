#include <string>

class Game {
public:
  Game();
  ~Game();
  string state;
  int running;
  int active;
  int current;
  bool near;
};

Game::Game():
string("home")
running(1)
active(0)
current(0)
near(false)
{}

Game::~Game() {}
