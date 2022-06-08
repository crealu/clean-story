#include <SDL2/SDL_ttf.h>
#include "main.hpp"

int main(int arc, char *argv[]) {
  initialize();

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("assets/fonts/Comfortaa[wght].ttf", 20);
  SDL_Event event;

  Game game;
  Story story;
  Player player;
  Home home;
  Menu menu;
  Button buttons[3];
  Theme themes;
  Screen screens[3];
  Animation animation;
  // Music song("assets/audio/phased.mp3");

  for (int s = 0; s < 3; s++) {
    screens[s].update(renderer, theFont);
    screens[s].setColor(themes.getColor(s));
  }

  home.setText(theFont, renderer);
  menu.setText(theFont, renderer);

  pos entityPos[3];
  const char *buttonText[3][2] = {
    {"M", "Talk"},
    {"G", "Take"},
    {"H", "Enter"}
  };

  for (int t = 0; t < 3; t++) {
    buttons[t].setText(theFont, buttonText[t], renderer);
  }

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.running = quitGame(game.running, window, event);
      game.current = screens[game.active].setCurrent(event, game.current);
      game.changeState(event);
      game.changeWorld(event);
      player.move(event);
      player.pickupItem(event, screens[game.active]);
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
      screens[game.active].draw(game.near[0], game.current);
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
