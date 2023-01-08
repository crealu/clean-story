#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Dialog {
public:
  void draw(SDL_Renderer *renderer);
  void setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText);
  int getLength(const char *text);
  void setRect(const char *text);

private:
  SDL_Rect rect;
  SDL_Texture *texture;
  SDL_Surface *surface;
  int xPos;
  int yPos;
};
