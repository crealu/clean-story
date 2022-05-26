#include <SDL2/SDL.h>

class Theme {
public:
  Theme();
  ~Theme();
  SDL_Color red[];
  SDL_Color green[];
  SDL_Color blue[];
  SDL_Color *all[];
};

Theme::Theme() {
  red[] = {
    {83, 0, 6},
    {248, 166, 172},
    {166, 55, 63}
  };

  green[] = {
    {20, 73, 0},
    {165, 218, 145},
    {75, 145, 48}
  };

  blue[] = {
    {6, 19, 57},
    {121, 134, 172},
    {47, 64, 115}
  };

  all[] = {green, red, blue};
}

Theme::~Theme() {}
