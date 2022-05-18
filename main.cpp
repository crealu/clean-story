#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "main.hpp"
using namespace std;

int main(int arc, char *argv[]) {
  initialize();

  int flags = MIX_INIT_MP3;
  int initted = Mix_Init(flags);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *music;
  Mix_AllocateChannels(16);
  Mix_Volume(1, MIX_MAX_VOLUME/2);
  music = Mix_LoadMUS("assets/audio/phased.mp3");
  Mix_PlayMusic(music, -1);

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("fonts/Comfortaa[wght].ttf", 24);
  SDL_Event event;

  Game game;
  Circle circle;
  Player player;
  Screen screens[3];
  string themes[] = {"green", "red", "blue"};
  for (int s = 0; s < sizeof(themes)/sizeof(themes[0]); s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes[s]);
  }

  Home home;
  Menu menu;
  Button button;

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
      player.move(event);
      game.near = player.getVicinity(wizardX, wizardY, event, game.near);
      game.current = screens[game.active].setCurrent(event, game.current);

      switch (event.type) {
        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_y && game.active != 2)
            game.active++;
          if (event.key.keysym.sym == SDLK_t && game.active != 0)
            game.active--;
          if (event.key.keysym.sym == SDLK_SPACE)
            game.state = "play";
          if (event.key.keysym.sym == SDLK_RETURN) {
            if (game.state == "menu")
              game.state = "play";
            else
              game.state = "menu";
          }
          break;
      }
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

    circle.draw(renderer);
    player.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  Mix_FreeMusic(music);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
