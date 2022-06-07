#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Script {
public:
  Script(const char *filename);
  ~Script();
  void writeText(int current);
  const char *getText(int current);
  int length;

private:
  string text[12];
};

Script::Script(const char *filename) {
  fstream textFile;
  int count = 0;
  length = 0;

  textFile.open(filename, ios::in);
  if (textFile.is_open()) {
    string line;
    while (getline(textFile, line)) {
      text[count] = line;
      count++;
    }
    length = count;
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
