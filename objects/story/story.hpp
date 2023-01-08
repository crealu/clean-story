#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Story {
public:
  Story();
  ~Story();
  task tasks[4];
  void updateTask(int taskNumber);
  void getTask(int taskNumber);
};
