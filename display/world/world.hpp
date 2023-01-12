class World {
public:
  World(SDL_Color worldColor);
  ~World();
  void draw(SDL_Renderer *renderer);

private:
  SDL_Color color;
};
