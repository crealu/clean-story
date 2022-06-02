#include <SDL/SDL.h>

class Bag {
public:
  Bag();
  ~Bag();
  item items[10];
  void addItem();
  void removeItem();
  void updateItem();
};

Bag::Bag() {}
Bag::~Bag() {}

void Bag::addItem() {}

void Bag::removeItem() {}

void Bag::updateItem() {}
