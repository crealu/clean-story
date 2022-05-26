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
  void setColor(SDL_Color colors[]);
  Wizard *wizard;

protected:
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

void Screen::setColor(SDL_Color colors[]) {
  SDL_Color worldColor = {colors[0].r, colors[0].g, colors[0].b};
  SDL_Color waveColor = {colors[1].r, colors[1].g, colors[1].b};
  SDL_Color wizardColor = {colors[2].r, colors[2].g, colors[2].b};

  // if (color == "green") {
  //   worldColor.r = 20;
  //   worldColor.g = 73;
  //   worldColor.b = 0;
  //   waveColor.r = 165;
  //   waveColor.g = 218;
  //   waveColor.b = 145;
  //   wizardColor.r = 75;
  //   wizardColor.g = 145;
  //   wizardColor.b = 48;
  // } else if (color == "red") {
  //   worldColor.r = 83;
  //   worldColor.g = 0;
  //   worldColor.b = 6;
  //   waveColor.r = 248;
  //   waveColor.g = 166;
  //   waveColor.b = 172;
  //   wizardColor.r = 166;
  //   wizardColor.g = 55;
  //   wizardColor.b = 63;
  // } else if (color == "blue") {
  //   worldColor.r = 6;
  //   worldColor.g = 19;
  //   worldColor.b = 57;
  //   waveColor.r = 121;
  //   waveColor.g = 134;
  //   waveColor.b = 172;
  //   wizardColor.r = 47;
  //   wizardColor.g = 64;
  //   wizardColor.b = 115;
  // }

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
