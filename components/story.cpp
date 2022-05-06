#include <iostream>
#include <stdio.h>
// #include <SDL2/SDL.h>
using namespace std;

// class StoryScript {
// public:
//   StoryScript();
//   ~StoryScript();
//
//   void writeText();
//   void setCurrent(char c);
//
// protected:
//   char *script;
//   int currentLine;
// };
//
// StoryScript::StoryScript() {
//   const char *text[] = {
//     "Serene voyager unbound by perpetuated chasm, the trial of times forgotten can only one bear.",
//     "So... what brings you to Midoritierra?",
//     "...",
//     "...",
//     "Excuse my unmannerliness... for I have yet to introduce myself.",
//     "I am the sourcerer of these plains,",
//     "maintainer of peace and order,",
//     "caster of the breeze of tranquility,"
//     "wielder of the inifinte grön magic.",
//     "And my friends call me G."
//   };
//
//   script = new char[sizeof text];
//   currentLine = 0;
//
//   for (int t = 0; t < sizeof text; t++)
//     script[t] = text[t];
// }
// StoryScript::~StoryScript() {}
//
// void StoryScript::writeText() {
//   cout << script[currentLine] << "\n";
// }
//
// void StoryScript::setCurrent(char c) {
//   if (c == 'n' && currentLine != 9)
//     currentLine += 1;
//
//   if (c == 'b' && currentLine != 0)
//     currentLine -= 1;
// }

int main() {
  // StoryScript green;
  char c;
  int curr = 0;

  const char *text[] = {
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
  };

  while (c != 'e') {
    cout << "n/b ? ";
    cin >> c;
    if (c == 'n')
      curr += 1;

    if (c == 'b')
      curr -= 1;

    cout << "\n" << text[curr] << "\n";
    // green.writeText();
    // green.setCurrent(c);
  }

  return 0;
}
