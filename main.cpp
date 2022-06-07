#include <SDL2/SDL_ttf.h>
#include "main.hpp"

int main(int arc, char *argv[]) {
  initialize();

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("assets/fonts/Comfortaa[wght].ttf", 20);
  SDL_Event event;

  Story story;
  Game game;
  Player player;
  Home home;
  Menu menu;
  Button buttons[3];
  Theme themes;
  Screen screens[3];
  Animation animation;
  // Music song("assets/audio/phased.mp3");

  for (int s = 0; s < 3; s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes.getColor(s));
  }

  home.setText(theFont, renderer);
  menu.setText(theFont, renderer);

  const char *button1Text[] = {"M", "Talk"};
  const char *button2Text[] = {"G", "Take"};
  const char *button3Text[] = {"H", "Enter"};
  buttons[0].setText(theFont, button1Text, renderer);
  buttons[1].setText(theFont, button2Text, renderer);
  buttons[2].setText(theFont, button3Text, renderer);

  pos entityPos[3];

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.running = quitGame(game.running, window, event);
      game.current = screens[game.active].setCurrent(event, game.current);
      game.handleKeyDown(event);
      player.move(event);
      player.pickupItem(event, screens[game.active], renderer, theFont);
    }

    entityPos[0] = screens[game.active].wizard->getPosition();
    entityPos[1] = screens[game.active].wizard->getHatPosition();
    entityPos[2] = screens[game.active].portal.getPosition();

    for (int e = 0; e < 3; e++) {
      game.near[e] = player.getVicinity(entityPos[e]);
    }

    if (game.state == "home") {
      home.draw(renderer);
    } else if (game.state == "menu") {
      menu.draw(renderer);
    } else {
      screens[game.active].draw(renderer, game.near[0], game.current);
      player.draw(renderer);
    }

    for (int b = 0; b < 3; b++) {
      if (game.near[b]) {
        buttons[b].draw(renderer);
      }
    }

    // if (story.tasks[0].completed)
    //   portal.draw(renderer);

    // animation.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
