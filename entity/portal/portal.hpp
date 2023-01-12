#include "../../common/shapes/hexagon.cpp"

class Portal {
public:
  Portal();
  ~Portal();
  void draw(SDL_Renderer *renderer);
  pos getPosition();

private:
  Hexagon *hexagon;
};
