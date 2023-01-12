class Background {
public:
  Background(SDL_Color BackgroundColor);
  ~Background();
  void draw(SDL_Renderer *renderer);

private:
  SDL_Color color;
};
