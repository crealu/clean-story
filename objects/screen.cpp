#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "world.cpp"
#include "wave.cpp"
#include "wizard.cpp"
#include "portal.cpp"
#include "../ui/script.cpp"
#include "../ui/dialog.cpp"
#include "../ui/button.cpp"
using namespace std;

class Screen {
public:
  Screen();
  ~Screen();
  void draw(SDL_Renderer *renderer, bool near, int current);
  void drawDialogBox(SDL_Renderer *renderer);
  void prepareDialog(TTF_Font *font, SDL_Renderer *renderer);
  void updateDialog(TTF_Font *font, SDL_Renderer *renderer);
  void setColor(struct themeColor color);
  int setCurrent(SDL_Event &event, int current);
  Wizard *wizard;
  Script *script;
  int dialogLimit;
  bool hatReturned;
  Portal portal;

private:
  World *world;
  Wave *wave;
  Dialog *dialog;
  SDL_Rect dialogBox;
  bool showDialog;
};

Screen::Screen() {
  SDL_Rect rect = {20, 410, 600, 50};
  dialogBox = rect;
  showDialog = false;
  script = new Script("./assets/stories/green/script1.txt");
  dialogLimit = script->length;
  dialog = new Dialog[dialogLimit + 1];
}

Screen::~Screen() {}

void Screen::draw(SDL_Renderer *renderer, bool near, int current) {
  world->draw(renderer);
  wave->draw(renderer);
  wizard->draw(renderer, near);
  if (showDialog) {
    drawDialogBox(renderer);
    dialog[current].draw(renderer);
  }
  if (hatReturned)
    portal.draw(renderer);
}

void Screen::drawDialogBox(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &dialogBox);
}

void Screen::prepareDialog(TTF_Font *font, SDL_Renderer *renderer) {
  for (int i = 0; i < this->dialogLimit; i++) {
    dialog[i].setDialog(font, renderer, script->getText(i));
  }
}

void Screen::updateDialog(TTF_Font *font, SDL_Renderer *renderer) {
  script = new Script("./assets/stories/green/script2.txt");
  dialogLimit = script->length;
  // for (int i = 0; i < dialogLimit; i++) {
  //   dialog[i].setDialog(font, renderer, script->getText(i));
  // }
  prepareDialog(font, renderer);
}

void Screen::setColor(struct themeColor color) {
  SDL_Color worldColor = color.worldColor;
  SDL_Color waveColor = color.waveColor;
  SDL_Color wizardColor = color.wizardColor;

  world = new World(worldColor);
  wave = new Wave(waveColor);
  wizard = new Wizard(wizardColor);
}

int Screen::setCurrent(SDL_Event &event, int current) {
  switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_m) {
        if (wizard->hat->collected)
          hatReturned = true;
          
        if (current != dialogLimit) {
          showDialog = true;
          current++;
        } else {
          current = 0;
          showDialog = false;
        }
      }
      break;
  }

  return current;
}
