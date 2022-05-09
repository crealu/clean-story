#include <iostream>
#include <stdio.h>
using namespace std;

class StoryScript {
public:
  StoryScript();
  ~StoryScript();
  void writeText(int current);
  const char *getText(int current);

protected:
  string *script;
};

StoryScript::StoryScript() {
  string text[] = {
    "Serene voyager unbound by perpetuated chasm,",
    "the trial of times forgotten can only one bear.",
    "So... what brings you to Midoritierra?",
    "...",
    "Excuse my unmannerliness... I have yet to introduce myself.",
    "I am the sourcerer of these plains,",
    "maintainer of peace and order,",
    "caster of the breeze of tranquility,",
    "wielder of the inifinte grön magic.",
    "And my friends call me G."
  };

  int textLength = sizeof(text)/sizeof(text[0]);
  script = new string[textLength];

  for (int t = 0; t < textLength; t++)
    script[t] = text[t];
}

StoryScript::~StoryScript() {}

void StoryScript::writeText(int current) {
  const char *dialog = script[current].c_str();
  cout << dialog << "\n";
}

const char *StoryScript::getText(int current) {
  const char *dialog = script[current].c_str();
  return dialog;
}
