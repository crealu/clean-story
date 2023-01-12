class Menu {
public:
  Menu();
  ~Menu();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);

protected:
  SDL_Rect rect[10];
  SDL_Surface *surface[10];
  SDL_Texture *texture[10];
};
