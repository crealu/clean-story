#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Dialog {
public:
  void setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText);
  void draw(SDL_Renderer *renderer);
  int getLength(const char *text);

protected:
  SDL_Rect rect;
  SDL_Texture *texture;
  int xPos;
  int yPos;
};

void Dialog::setDialog(TTF_Font *font, SDL_Renderer *renderer, const char *text) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Blended(font, text, fontColor);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  rect.x = 0;
  rect.y = 450;
  rect.h = 30;
  rect.w = 12 * getLength(text);
  // if (15 * getLength(theText) >= 600) {
  //   textRect.w = 10 * getLength(theText);
  // } else {
  //   textRect.w = 15 * getLength(theText);
  // }
  SDL_FreeSurface(surface);
}

void Dialog::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect);
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}

int Dialog::getLength(const char *text) {
  int size = 0;
  while (text[size] != '\0') size++;
  return size;
}
