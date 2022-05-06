#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

class TextBox {
public:
  TextBox(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText, int xPos, int yPos);
  ~TextBox();
  void draw(SDL_Renderer *renderer);

private:
  SDL_Rect textRect1;
  SDL_Rect textRect2;
  SDL_Texture *textureText1;
  SDL_Texture *textureText2;
};

TextBox::TextBox(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText, int xPos, int yPos) {
  SDL_Color fontColor = {0, 0, 0};
  int threshold = 15;

  if ((threshold * strlen(theText)) >= 300) {
    SDL_Surface *surfaceText1 = TTF_RenderText_Solid(aFont, theText, fontColor);
    textureText1 = SDL_CreateTextureFromSurface(renderer, surfaceText1);
    textRect1.x = 20;
    textRect1.y = 400;
    textRect1.w = 600;
    textRect1.h = 30;
    SDL_FreeSurface(surfaceText1);

    SDL_Surface *surfaceText2 = TTF_RenderText_Solid(aFont, theText, fontColor);
    textureText2 = SDL_CreateTextureFromSurface(renderer, surfaceText2);
    textRect2.x = 20;
    textRect2.y = 430;
    textRect2.w = threshold * strlen(theText);
    textRect2.h = 30;
    SDL_FreeSurface(surfaceText2);
  } else {
    SDL_Surface *surfaceText1 = TTF_RenderText_Solid(aFont, theText, fontColor);
    textureText1 = SDL_CreateTextureFromSurface(renderer, surfaceText1);
    textRect1.x = 200;
    textRect1.y = 200;
    textRect1.w = threshold * strlen(theText);
    textRect1.h = 30;
    SDL_FreeSurface(surfaceText1);
  }
}

TextBox::~TextBox() {}

void TextBox::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &textRect1);
  SDL_RenderCopy(renderer, textureText1, NULL, &textRect1);
  SDL_RenderFillRect(renderer, &textRect2);
  SDL_RenderCopy(renderer, textureText2, NULL, &textRect2);
}
