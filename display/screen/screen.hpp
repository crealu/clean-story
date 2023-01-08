#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../world/world.cpp"
#include "../wave/wave.cpp"
#include "../../entity/wizard/wizard.cpp"
#include "../../entity/portal/portal.cpp"
#include "../../ui/script/script.cpp"
#include "../../ui/dialog/dialog.cpp"
using namespace std;

class Screen {
public:
  Screen();
  ~Screen();
  void setup(SDL_Renderer *theRenderer, TTF_Font *theFont);
  void draw(bool near, int current);
  void drawDialogBox();
  void prepareDialog();
  void updateDialog();
  void setColor(struct themeColor color);
  int setCurrent(SDL_Event &event, int current);
  Wizard *wizard;
  Script *script;
  int dialogLimit;
  bool hatReturned;
  Portal portal;
  SDL_Renderer *renderer;
  TTF_Font *font;

private:
  World *world;
  Wave *wave;
  Dialog *dialog;
  SDL_Rect dialogBox;
  bool showDialog;
};
