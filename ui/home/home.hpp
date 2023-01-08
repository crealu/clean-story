#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Home {
public:
  Home();
  ~Home();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

protected:
  SDL_Rect rect;
  SDL_Surface *surface;
  SDL_Texture *texture;
  const char *text;
};
