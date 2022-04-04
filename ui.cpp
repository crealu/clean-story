#include <iostream>
#include <SDL2/SDL.h>
#include "entity.cpp"
using namespace std;

class DialogBox : public Entity {
  DialogBox(int x, int y);
  ~DialogBox();
};

DialogBox::DialogBox(int x, int y) : Entity(x, y) {
  cout << "Dialog box created";
}

DialogBox::~DialogBox() {}


// class TextBox {
// public:
//   TextBox();
//   ~TextBox();
//
//   void setup();
//   void show();
//   void hide();
//   void draw();
//
// private:
//   SDL_Rect tRect;
// };
//
// TextBox::TextBox() {
//   tRect.x =
//   cout << "TextBox created";
// }
//
// TextBox::~TextBox() {}
