#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Home {
public:
  Home();
  ~Home();
  void draw(SDL_Renderer *renderer);
};

Home::Home() {}
Home::~Home() {}

void Home::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  SDL_RenderClear(renderer);
}
