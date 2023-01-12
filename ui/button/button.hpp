class Button {
public:
  Button();
  ~Button();
  void setup(SDL_Renderer *theRenderer, TTF_Font *theFont);
  void setText(const char *text[]);
  SDL_Rect setRect(int x, int y, int height, int width);
  void draw();
  void drawContainer();
  void drawCircle();
  void drawText();

private:
  SDL_Renderer *renderer;
  TTF_Font *font;
  int x;
  int y;
  int radius;
  SDL_Rect containerRect;
  SDL_Rect circleRect;
  SDL_Rect textRect;
  SDL_Texture *circleTexture;
  SDL_Texture *textTexture;
  SDL_Surface *circleSurface;
  SDL_Surface *textSurface;
};
