using namespace std;

struct themeColor {
  SDL_Color backgroundColor;
  SDL_Color waveColor;
  SDL_Color wizardColor;
};

struct pos {
  int x;
  int y;
};

struct task {
  string title;
  string description;
  bool completed;
};

struct item {
  string name;
  string description;
  int quantity;
  pos position;
  bool gathered;
};
