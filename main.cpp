#include <SDL2/SDL_ttf.h>
#include "main.hpp"

int main(int arc, char *argv[]) {
  initialize();

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);
  SDL_Event event;

  Game game;
  Music song("assets/audio/phased.mp3");
  Player player;
  Theme themes;
  Home home;
  Menu menu;
  Button button;
  Screen screens[3];
  // Circle circle;

  for (int s = 0; s < 3; s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes.getColor(s));
  }

  home.setText(theFont, renderer);
  menu.setText(theFont, renderer);
  button.setText(theFont, renderer);

  int wizardX = screens[game.active].wizard->getX();
  int wizardY = screens[game.active].wizard->getY();
  int playerX = player.getPosition()->x;
  int playerY = player.getPosition()->y;

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.running = quitGame(game.running, window, event);
      game.current = screens[game.active].setCurrent(event, game.current);
      game.near = player.getVicinity(wizardX, wizardY, event, game.near);
      game.handleKeyDown(event);
      player.move(event);
    }

    if (game.state == "home") {
      home.draw(renderer);
    } else if (game.state == "menu") {
      menu.draw(renderer);
    } else {
      screens[game.active].draw(renderer, game.near, game.current);
    }

    if (game.near)
      button.draw(renderer);

    // circle.draw(renderer);
    player.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
