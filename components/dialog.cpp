#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

class Dialog {
public:
  void setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText);
  void draw(SDL_Renderer *renderer);
  int getLength(const char *text);

protected:
  SDL_Rect textRect1;
  SDL_Texture *textureText1;
  int xPos;
  int yPos;
};

void Dialog::setDialog(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surfaceText1 = TTF_RenderText_Solid(aFont, theText, fontColor);
  textureText1 = SDL_CreateTextureFromSurface(renderer, surfaceText1);
  textRect1.x = 20;
  textRect1.y = 400;
  textRect1.h = 30;
  if (15 * getLength(theText) >= 600) {
    textRect1.w = 10 * getLength(theText);
  } else {
    textRect1.w = 15 * getLength(theText);
  }
  cout << getLength(theText) << "\n";
  SDL_FreeSurface(surfaceText1);
}

void Dialog::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &textRect1);
  SDL_RenderCopy(renderer, textureText1, NULL, &textRect1);
}

int Dialog::getLength(const char *text) {
  int size = 0;
  while (text[size] != '\0') size++;
  return size;
}
