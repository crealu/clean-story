#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Dialog {
public:
  void setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText);
  void draw(SDL_Renderer *renderer);
  int getLength(const char *text);

protected:
  SDL_Rect textRect;
  SDL_Texture *textureText;
  int xPos;
  int yPos;
};

void Dialog::setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surfaceText = TTF_RenderText_Solid(aFont, theText, fontColor);
  textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);
  textRect.x = 20;
  textRect.y = 400;
  textRect.h = 30;
  if (15 * getLength(theText) >= 600) {
    textRect.w = 10 * getLength(theText);
  } else {
    textRect.w = 15 * getLength(theText);
  }
  SDL_FreeSurface(surfaceText);
}

void Dialog::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &textRect);
  SDL_RenderCopy(renderer, textureText, NULL, &textRect);
}

int Dialog::getLength(const char *text) {
  int size = 0;
  while (text[size] != '\0') size++;
  return size;
}
