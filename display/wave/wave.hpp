class Wave {
public:
  Wave(SDL_Color color);
  ~Wave();
  void draw(SDL_Renderer *renderer);

private:
  int *xPoints;
  int *yPoints;
  int pLen;
  int xp;
  int yo;
  SDL_Color color;
};
