#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Dialog {
public:
  void draw(SDL_Renderer *renderer);
  void setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText);
  int getLength(const char *text);

protected:
  SDL_Rect rect;
  SDL_Texture *texture;
  int xPos;
  int yPos;
};

void Dialog::draw(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Dialog::setDialog(TTF_Font *font, SDL_Renderer *renderer, const char *text) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Blended(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 25;
  rect.y = 412;
  rect.h = 20;
  rect.w = 12 * getLength(text);
  // if (12 * getLength(text) >= 600) {
  //    create new texture for line 2
  // }
  SDL_FreeSurface(surface);
}

int Dialog::getLength(const char *text) {
  int size = 0;
  while (text[size] != '\0') size++;
  return size;
}
