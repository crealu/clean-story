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
  SDL_Rect tRect;
  SDL_Texture *textureText;
};

TextBox::TextBox(TTF_Font *aFont, SDL_Renderer *renderer, const char *theText, int xPos, int yPos) {
  SDL_Color fontColor = {0, 0, 0};
  SDL_Surface *surfaceText = TTF_RenderText_Solid(aFont, theText, fontColor);
  textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);
  tRect.x = xPos;
  tRect.y = yPos;
  tRect.w = 200;
  tRect.h = 30;
  SDL_FreeSurface(surfaceText);

  cout << "TextBox created";
}

TextBox::~TextBox() {}

void TextBox::draw(SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, textureText, NULL, &tRect);
}
