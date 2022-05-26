#include <iostream>
#include <fstream>
#include <string>
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
  string text[12];
  fstream textFile;
  int count = 0;
  script = new string[12];

  textFile.open("./assets/scripts/green.txt", ios::in);
  if (textFile.is_open()) {
    string line;
    while (getline(textFile, line)) {
      script[count] = line;
      count++;
    }
    textFile.close();
  }
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
