#include <SDL2/SDL.h>
#include <string>
using namespace std;

struct themeColor {
  SDL_Color worldColor;
  SDL_Color waveColor;
  SDL_Color wizardColor;
};

struct position {
  int x;
  int y;
};

struct Task {
  string title;
  string description;
  bool completed;
};
