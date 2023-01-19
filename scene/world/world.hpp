#include "../background/background.cpp"
#include "../wave/wave.cpp"
#include "../../entity/wizard/wizard.cpp"
#include "../../entity/portal/portal.cpp"
#include "../../ui/script/script.cpp"
#include "../../ui/dialog/dialog.cpp"

class World {
public:
  World();
  ~World();
  void setup(SDL_Renderer *theRenderer, TTF_Font *theFont);
  virtual void draw(bool near, int current);
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
  Background *background;
  Wave *wave;
  Dialog *dialog;
  SDL_Rect dialogBox;
  bool showDialog;
};
