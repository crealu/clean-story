#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "story.cpp"
#include "dialog.cpp"
#include "world.cpp"
#include "wave.cpp"
#include "wizard.cpp"
using namespace std;

class Screen {
public:
  Screen();
  ~Screen();
  void draw(SDL_Renderer *renderer, bool near, int current);
  void prepareDialog(TTF_Font *font, SDL_Renderer *renderer);
  int setCurrent(SDL_Event &event, int current);
  void setColor(struct themeColor color);
  Wizard *wizard;

private:
  StoryScript *script;
  Dialog *dialog;
  World *world;
  Wave *wave;
};

Screen::Screen() {
  script = new StoryScript;
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
    dialog[current].draw(renderer);
  }
}

void Screen::prepareDialog(TTF_Font *font, SDL_Renderer *renderer) {
  for (int i = 0; i < 10; i++) {
    dialog[i].setDialog(font, renderer, script->getText(i));
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
