#include <SDL2/SDL_ttf.h>
#include "main.hpp"

int main(int arc, char *argv[]) {
  initialize();

  TTF_Font *font = TTF_OpenFont("assets/fonts/Comfortaa[wght].ttf", 20);
  SDL_Window *window = initWindow("Storyline", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  SDL_Event event;

  Home home;
  Spin spin;
  Menu menu;
  Game game;
  Story story;
  Player player;
  Button buttons[3];
  Theme themes;
  // Screen screens[3];
  World worlds[3];
  // Animation animation;
  Music song("assets/audio/phased.mp3");

  for (int s = 0; s < 3; s++) {
    worlds[s].setup(renderer, font);
    worlds[s].setColor(themes.getColor(s));
  }

  home.setText(font, renderer);
  menu.setText(font, renderer);
  spin.setText(font, renderer);

  pos entityPos[3];
  const char *buttonText[3][2] = {
    {"M", "Talk"},
    {"G", "Take"},
    {"H", "Enter"}
  };

  for (int t = 0; t < 3; t++) {
    buttons[t].setup(renderer, font);
    buttons[t].setText(buttonText[t]);
  }

  spin.setAngle();

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.quit(window, event);
      // game.running = quitGame(game.running, window, event);
      game.current = worlds[game.active].setCurrent(event, game.current);
      game.handleInput(event);
      player.setActiveScreen(worlds[game.active]);
      player.handleInput(event);
    }

    entityPos[0] = worlds[game.active].wizard->getPosition();
    entityPos[1] = worlds[game.active].wizard->getHatPosition();
    entityPos[2] = worlds[game.active].portal.getPosition();

    if (game.state == "home") {
      spin.draw(renderer);
    } else if (game.state == "menu") {
      menu.draw(renderer);
    } else {
      worlds[game.active].draw(game.near[0], game.current);
      player.draw(renderer);
    }

    for (int e = 0; e < 3; e++) {
      if (player.getVicinity(entityPos[e])) {
        buttons[e].draw();
        game.near[e] = true;
      } else {
        game.near[e] = false;
      }
    }

    // animation.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(font);
  SDL_Quit();
  return 0;
}
