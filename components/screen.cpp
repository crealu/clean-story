#include <iostream>
#include <string>
#include "components/world.cpp"
#include "components/script.cpp"
#include "components/wizard.cpp"
using namespace std;

class Screen {
public:
  Screen();
  ~Screen();

protected:
  World world;
  Wizard wizard;
  StoryScript script;
};

Screen::Screen() {

}

Screen::~Screen() {}
