#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

struct Task {
  string name;
  bool completed;
  int number;
};

class Story {
public:
  Story();
  ~Story();
  Task tasks[4];
  void updateTask(int taskNumber);
  void getTask(int taskNumber);
};

Story::Story() {}
Story::~Story() {}

void Story::updateTask(int taskNumber) {

}

void Story::getTask(int taskNumber) {

}
