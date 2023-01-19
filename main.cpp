#include <SDL2/SDL_ttf.h>
#include "main.hpp"

void drawShards(Shard shards[], SDL_Renderer *renderer);


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
  Theme themes;
  Shard shards[3];
  Button buttons[3];
  World worlds[3];
  Music song("assets/audio/phased.mp3");
  // Screen screens[3];
  // Animation animation;

  SDL_Color shardColor = {75, 145, 48};

  const char *buttonText[3][2] = {
    {"M", "Talk"},
    {"G", "Take"},
    {"H", "Enter"}
  };

  for (int s = 0; s < 3; s++) {
    worlds[s].setup(renderer, font);
    worlds[s].setColor(themes.getColor(s));
    buttons[s].setup(renderer, font);
    buttons[s].setText(buttonText[s]);
    shards[s].setup(shardColor, 50 + (s*200), 50 + (s * 150));
  }

  home.setText(font, renderer);
  menu.setText(font, renderer);
  spin.setText(font, renderer);
  spin.setAngle();

  pos entityPos[3];

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.quit(window, event);
      // game.running = quitGame(game.running, window, event);
      game.current = worlds[game.active].setCurrent(event, game.current);
      game.handleInput(event);
      player.setActiveScreen(worlds[game.active]);
      player.handleInput(event);
    }

    if (game.state == "home") {
      spin.draw(renderer);
    } else if (game.state == "menu") {
      menu.draw(renderer);
    } else {
      worlds[game.active].draw(game.near[0], game.current);
      player.draw(renderer);
    }

    entityPos[0] = worlds[game.active].wizard->getPosition();
    entityPos[1] = worlds[game.active].wizard->getHatPosition();
    entityPos[2] = worlds[game.active].portal.getPosition();

    for (int e = 0; e < 3; e++) {
      if (player.getVicinity(entityPos[e])) {
        buttons[e].draw();
        game.near[e] = true;
      } else {
        game.near[e] = false;
      }
    }

    drawShards(shards, renderer);

    // animation.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(font);
  SDL_Quit();
  return 0;
}

void drawShards(Shard shards[], SDL_Renderer *renderer) {
  for (int i = 0; i < 3; i++) {
    shards[i].draw(renderer);
  }
}

