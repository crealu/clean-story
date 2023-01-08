#include "script.hpp"

Script::Script() {}
Script::~Script() {}

void Script::update(const char *filename) {
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

void Script::writeText(int current) {
  const char *dialog = text[current].c_str();
  cout << dialog << "\n";
}

const char *Script::getText(int current) {
  const char *dialog = text[current].c_str();
  return dialog;
}
