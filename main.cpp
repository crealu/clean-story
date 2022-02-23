#include <iostream>
#include <string.h>
using namespace std;

enum { world, character };

void prompt();

class World
{
public:
  World();
  ~World();
private:
  string landscape;
  int relativeTime;
  bool manyWorlds;
};

class Character
{
public:
  Character();
  ~Character();
private:
  string name;
  bool isHuman;
};

int main()
{
  int startWith;

  prompt();
  cin >> startWith;

  if (startWith == world) {
    World aWorld;
  } else if (startWith == character) {
    Character aCharacter;
  }

  return 0;
}

void prompt()
{
  cout << "Begin with: (0) World  (1) Character" << "\n";
}

World::World()
{
  cout << "You created a world.";
}

World::~World() {}

Character::Character()
{
  cout << "You created a Character.";
}

Character::~Character() {}
