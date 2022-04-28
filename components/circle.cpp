class Circle {
public:
  Circle();
  ~Circle();

  void draw(SDL_Renderer *renderer);

protected:
  int p;
  int cx;
  int cy;
  int *xPoints;
  int *yPoints;
}

Circle::Circle() {
  float pn = 6.29;
  float pInc = 0.01;
  int p, pLen;
  pLen = pn / pInc;

  xPoints = new int[pLen];
  yPoints = new int[pLen];

  float r = 0.0;
  for (r = 0.0, p = 0; r <= pn; r += pinc, p++)
    if (p < plen)
      xpoints[p] = round( 20 * (cos(r/1.0)) );

  for (r = 0.0, p = 0; r <= pn; r += pinc, p++)
    if (p < plen)
      ypoints[p] = round( 20 * (sin(r/1.0)) );
}

Circle::~Circle() {}

void Circle::draw(SDL_Renderer *renderer) {
  
}
