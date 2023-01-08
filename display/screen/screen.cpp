#include "screen.hpp"

Screen::Screen() {
  SDL_Rect rect = {20, 410, 600, 50};
  dialogBox = rect;
  showDialog = false;
  script = new Script;
  script->update("./assets/stories/green/script1.txt");
  dialog = new Dialog[script->length];
}

Screen::~Screen() {}

void Screen::setup(SDL_Renderer *theRenderer, TTF_Font *theFont) {
  renderer = theRenderer;
  font = theFont;
  prepareDialog();
}

void Screen::draw(bool near, int current) {
  world->draw(renderer);
  wave->draw(renderer);
  wizard->draw(renderer, near);

  if (showDialog) {
    drawDialogBox();
    dialog[current].draw(renderer);
  }
  if (hatReturned)
    portal.draw(renderer);
}

void Screen::drawDialogBox() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &dialogBox);
}

void Screen::prepareDialog() {
  for (int i = 0; i < script->length; i++) {
    dialog[i].setDialog(font, renderer, script->getText(i));
  }
}

void Screen::updateDialog() {
  script->update("./assets/stories/green/script2.txt");
  prepareDialog();
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
        if (wizard->hat->collected && current == 2) {
          hatReturned = true;
        }
        if (current != script->length - 1) {
          showDialog = true;
          current++;
        } else {
          current = 0;
          showDialog = false;
        }
      }
  }

  return current;
}
