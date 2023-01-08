#include <SDL2/SDL.h>

class Theme {
public:
  Theme();
  ~Theme();
  themeColor getColor(int index);
};
