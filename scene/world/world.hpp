#include "../background/background.cpp"
#include "../wave/wave.cpp"
#include "../../entity/wizard/wizard.cpp"
#include "../../entity/portal/portal.cpp"
#include "../../entity/shard/shard.cpp"
#include "../../ui/script/script.cpp"
#include "../../ui/dialog/dialog.cpp"

class World {
public:
  World();
  World(const char *script_file);
  ~World();
  void setup(SDL_Renderer *theRenderer, TTF_Font *theFont);
  virtual void draw(bool near, int current);
  void drawDialogBox();
  void prepareDialog();
  void updateDialog();
  void setColor(struct themeColor color);
  void addShards(Shard shards[3]);
  int setCurrent(SDL_Event &event, int current);
  int dialogLimit;
  bool hatReturned;
  Wizard *wizard;
  Script *script;
  Portal portal;
  SDL_Renderer *renderer;
  TTF_Font *font;

private:
  Background *background;
  Wave *wave;
  Dialog *dialog;
  SDL_Rect dialogBox;
  Shard worldShards[3];
  bool showDialog;
};
