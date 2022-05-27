#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "world.cpp"
#include "wave.cpp"
#include "wizard.cpp"
#include "../ui/story.cpp"
#include "../ui/dialog.cpp"
#include "../ui/button.cpp"
using namespace std;

class Screen {
public:
  Screen();
  ~Screen();
  void draw(SDL_Renderer *renderer, bool near, int current);
  void prepareDialog(TTF_Font *font, SDL_Renderer *renderer);
  void setColor(struct themeColor color);
  int setCurrent(SDL_Event &event, int current);
  Wizard *wizard;

private:
  SDL_Rect dRect;
  StoryScript *story;
  World *world;
  Wave *wave;
  Dialog *dialog;
};

Screen::Screen() {
  SDL_Rect rect = {20, 410, 600, 50};
  dRect = rect;
  story = new StoryScript;
  dialog = new Dialog[10];
}

Screen::~Screen() {}

void Screen::setColor(struct themeColor color) {
  SDL_Color worldColor = color.worldColor;
  SDL_Color waveColor = color.waveColor;
  SDL_Color wizardColor = color.wizardColor;

  world = new World(worldColor);
  wave = new Wave(waveColor);
  wizard = new Wizard(wizardColor);
}

void Screen::draw(SDL_Renderer *renderer, bool near, int current) {
  world->draw(renderer);
  wave->draw(renderer);
  wizard->draw(renderer);
  if (near) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &dRect);
    dialog[current].draw(renderer);
  }
}

void Screen::prepareDialog(TTF_Font *font, SDL_Renderer *renderer) {
  for (int i = 0; i < 10; i++) {
    dialog[i].setDialog(font, renderer, story->getText(i));
  }
}

int Screen::setCurrent(SDL_Event &event, int current) {
  switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_m && current != 9)
        current++;
      if (event.key.keysym.sym == SDLK_n && current != 0)
        current--;
      break;
  }

  return current;
}
