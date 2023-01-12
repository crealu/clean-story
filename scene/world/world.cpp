#include "world.hpp"

World::World() {
  SDL_Rect rect = {20, 410, 600, 50};
  dialogBox = rect;
  showDialog = false;
  script = new Script;
  script->update("./assets/stories/green/script1.txt");
  dialog = new Dialog[script->length];
}

World::~World() {}

void World::setup(SDL_Renderer *theRenderer, TTF_Font *theFont) {
  renderer = theRenderer;
  font = theFont;
  prepareDialog();
}

void World::draw(bool near, int current) {
  background->draw(renderer);
  wave->draw(renderer);
  wizard->draw(renderer, near);

  if (showDialog) {
    drawDialogBox();
    dialog[current].draw(renderer);
  }

  if (hatReturned)
    portal.draw(renderer);
}

void World::drawDialogBox() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &dialogBox);
}

void World::prepareDialog() {
  for (int i = 0; i < script->length; i++) {
    dialog[i].setDialog(font, renderer, script->getText(i));
  }
}

void World::updateDialog() {
  script->update("./assets/stories/green/script2.txt");
  prepareDialog();
}

void World::setColor(struct themeColor color) {
  SDL_Color backgroundColor = color.backgroundColor;
  SDL_Color waveColor = color.waveColor;
  SDL_Color wizardColor = color.wizardColor;

  background = new Background(backgroundColor);
  wave = new Wave(waveColor);
  wizard = new Wizard(wizardColor);
}

int World::setCurrent(SDL_Event &event, int current) {
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
