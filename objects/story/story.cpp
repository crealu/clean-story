#include "story.hpp"

Story::Story() {}
Story::~Story() {}

void Story::updateTask(int taskNumber) {
  tasks[0].title = "Hat du Giorno";
  tasks[0].description = "Find the green sorcerer's hat and return it.";

  tasks[1].title = "Hat do Buccarati";
  tasks[1].description = "Find the blue sorcerer's hat and return it.";

  tasks[2].title = "Hat du Raphael";
  tasks[2].description = "Find the red sorcerer's hat and return it.";

  for (int t = 0; t <= 3; t++) {
    tasks[t].completed = false;
  }
}

void Story::getTask(int taskNumber) {

}
