#include <SDL2/SDL.h>

class Menu {
public:
  Menu();
  ~Menu();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Rect *rect;
};

Menu::Menu() {

}
Menu::~Menu() {}

void Menu::draw(SDL_Renderer *render) {
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
  SDL_RenderClear(renderer);
  SDL_RenderFillRect(renderer, &rect);
}
