#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Script {
public:
  Script();
  ~Script();
  void writeText(int current);
  const char *getText(int current);

private:
  string text[12];
};

Script::Script() {
  fstream textFile;
  int count = 0;

  textFile.open("./assets/stories/green.txt", ios::in);
  if (textFile.is_open()) {
    string line;
    while (getline(textFile, line)) {
      text[count] = line;
      count++;
    }
    textFile.close();
  }
}

Script::~Script() {}

void Script::writeText(int current) {
  const char *dialog = text[current].c_str();
  cout << dialog << "\n";
}

const char *Script::getText(int current) {
  const char *dialog = text[current].c_str();
  return dialog;
}
