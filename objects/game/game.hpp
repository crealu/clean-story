using namespace std;

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
  void quit(SDL_Window *window, SDL_Event &event);
};
