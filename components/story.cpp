#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class StoryScript {
public:
  StoryScript();
  ~StoryScript();

  void writeText();

protected:
  char *script;
};

StoryScript::StoryScript() {}
StoryScript::~StoryScript() {}

void StoryScript::writeText() {
  char text = {
    "Serene voyager unbound by perpetuated chasm, the trial of times forgotten can only one bear.",
    "So... what brings you to Midoritierra?",
    "...",
    "...",
    "Excuse my unmannerliness... for I have yet to introduce myself.",
    "I am the sourcerer of these plains,",
    "maintainer of peace and order,",
    "caster of the breeze of tranquility,"
    "wielder of the inifinte grön magic.",
    "And my friends call me G."
  }

  script = new char[text.size()];

  for (int t = 0; t < text.size(); t++)
    script[t] = text[t];
}
