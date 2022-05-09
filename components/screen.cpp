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
  void setColor(string color);

protected:
  StoryScript *script;
  Dialog *dialog;
  World *world;
  Wave *wave;
  Wizard *wizard;
};

Screen::Screen() {
  script = new StoryScript;
  dialog = new Dialog[10];
}

Screen::~Screen() {}

void Screen::setColor(string color) {
  SDL_Color worldColor;
  SDL_Color waveColor;
  SDL_Color wizardColor;

  if (color == "green") {
    worldColor = {20, 73, 0};
    waveColor = {165, 218, 145};
    wizardColor = {75, 145, 48};
  } else if (color == "red") {
    worldColor = {83, 0, 6};
    waveColor = {248, 166, 172};
    wizardColor = {166, 55, 63};
  } else if (color == "blue") {
    worldColor = {6, 19, 57};
    waveColor = {121, 134, 172};
    wizardColor = {47, 64, 115};
  }

  world = new World(worldColor);
  wave = new Wave(waveColor);
  wizard = new Wizard(wizardColor);
}

void Screen::draw(SDL_Renderer *renderer, bool near, int current) {
  world->draw(renderer);
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
      if (event.key.keysym.sym == SDLK_m && current != 10)
        current++;

      if (event.key.keysym.sym == SDLK_n && current != 0)
        current--;
      break;
  }

  return current;
}
