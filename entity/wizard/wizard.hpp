#include "../../common/shapes/triangle.cpp"

class Hat {
public:
  Hat(SDL_Color wizardColor);
  ~Hat();
  bool collected;
  FilledTriangle *shape;
  void updateStatus();
};

class Wizard {
public:
  Wizard(SDL_Color wizardColor);
  ~Wizard();
  void draw(SDL_Renderer *renderer, bool near);
  void move();
  pos getHatPosition();
  pos getPosition();
  Hat *hat;

private:
  SDL_Rect pRect;
  SDL_Color color;
  int speed;
  bool pause;
  int t0;
  int t1;
};
