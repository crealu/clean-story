#include <iostream>
#include <string.h>
using namespace std;

enum { theWorld, theCharacter };

int initialPrompt();

class World
{
public:
  World();
  ~World();
  void setLandscape();
  void setWorldAreas();
  void getLandscape();
  void getWorldAreas();
  void summarize();
private:
  string landscape;
  int worldAreas;
};

class Character
{
public:
  Character();
  ~Character();
  void setName();
  void set_isHuman();
  void getName();
  void get_isHuman();
  void summarize();
private:
  string name;
  bool isHuman;
};

int main()
{
  int startWith = initialPrompt();

  if (startWith == theWorld) {
    World world;
    Character character;

    world.summarize();
    character.summarize();
  } else if (startWith == theCharacter) {
    Character character;
    World world;

    character.summarize();
    world.summarize();
  }

  return 0;
}

int initialPrompt()
{
  int start;
  cout << "Begin with: (0) World  (1) Character" << "\n";
  cin >> start;
  return start;
}

World::World()
{
  setLandscape();
  setWorldAreas();
}

World::~World() {}

void World::setLandscape()
{
  int aLandscape;
  int size = 4;
  string landscapes[] = {
    "Flat",
    "Hilly",
    "Mountainous",
    "Platforms"
  };

  cout << "Landscape is ____" << "\n";
  for (int i = 0; i < size; i++)
    cout << i << " " << landscapes[i] << "\n";

  cin >> aLandscape;
  landscape = landscapes[aLandscape];
}

void World::setWorldAreas()
{
  int numAreas;
  cout << "How many areas exist in the world? ";
  cin >> numAreas;
  worldAreas = numAreas;
}

void World::getLandscape()
{
  cout << "Landscape type: " << landscape << "\n";
}

void World::getWorldAreas()
{
  cout << "Number of areas: " << worldAreas << "\n";
}

void World::summarize()
{
  cout << "World: " << "\n";
  getLandscape();
  getWorldAreas();
  cout << "\n";
}

Character::Character()
{
  setName();
  set_isHuman();
}

Character::~Character() {}

void Character::setName()
{
  string aName;
  cout << "What is the character's name? ";
  cin >> aName;
  name = aName;
}

void Character::set_isHuman()
{
  char characterIsHuman;
  cout << "Is the character human? (y/n) ";
  cin >> characterIsHuman;
  isHuman = characterIsHuman == 'y' ? true : false;
  cout << "\n";
}

void Character::getName()
{
  cout << "Name of character: " << name << "\n";
}

void Character::get_isHuman()
{
  string output = isHuman ? "true" : "false";
  cout << "Human character: " << output << "\n";
}

void Character::summarize()
{
  cout << "Character: " << "\n";
  getName();
  get_isHuman();
  cout << "\n";
}
