// linkedList.cpp
// storing each user provided integer in an object of the Data class
// the InternalNode derived class object holds the data
#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame};

class Data {
public:
  Data(int newValue): value(newValue) { }
  ~Data() { }
  int compare(const Data&);
  void show() { std::cout << value << ", "; }
private:
  int value;
};

int Data::compare(const Data &otherData) {
  if (value < otherData.value) {
      return kIsSmaller;
  } else if (value > otherData.value) {
      return kIsLarger;
  } else {
      return kIsSame;
  }
}

// forward class declarations
class Node;
class HeadNode;
class TailNode;
class InternalNode;

class Node {
public:
  Node() { }
  virtual ~Node() { }
  virtual Node* insert(Data *data) = 0;
  virtual void show() = 0;
private:
};

class InternalNode : public Node {
public:
  InternalNode(Data* data, Node* next);
  virtual ~InternalNode() { delete data; delete next; }
  virtual Node* insert(Data* data);
  virtual void show() { data -> show(); next -> show(); } // delegation
private:
  Data* data;
  Node* next;
};

// simple constructor
InternalNode::InternalNode(Data* newData, Node* newNext):
data(newData), next(newNext) { }

//
Node* InternalNode::insert(Data* otherData) {
  // test incoming data with node behind head
  int result = data -> compare(*otherData); // what would happen if you just used (otherData) ?

  switch (result) {

    // if incoming data is the same or larger, pass it on to the next node to test
    case kIsSame:
    case kIsLarger:
      {
        InternalNode* dataNode = new InternalNode(otherData, this);
        return dataNode;
      }

    // if incoming data is smaller, insert it behind the one tested against?
    case kIsSmaller:
      next = next -> insert(otherData);
      return this;
  }
  return this;
}

class TailNode : public Node {
public:
  TailNode() { }
  virtual ~TailNode() { }
  virtual Node* insert(Data* data);
  virtual void show() { }
private:
};

// always insert data before the TailNode if data comes to TailNode
Node* TailNode::insert(Data* data) {
  InternalNode* dataNode = new InternalNode(data, this);
  return dataNode;
}


class HeadNode : public Node {
public:
  HeadNode();
  virtual ~HeadNode() { delete next; }
  virtual Node* insert(Data* data);
  virtual void show() { next -> show(); }
private:
  Node* next;
};

// starting to see that in order to create a doubly linked list, there needs
// to be a previous node test as well I think to test backward too

HeadNode::HeadNode() {
  next = new TailNode;
}

Node* HeadNode::insert(Data* data) {
  next = next -> insert(data);
  return this;
}

class LinkedList {
public:
  LinkedList();
  ~LinkedList() { delete head; }
  void insert(Data* data);
  void showAll() { head -> show(); }
private:
  HeadNode* head;
};

LinkedList::LinkedList() {
  head = new HeadNode;
}

void LinkedList::insert(Data* pData) {
  head -> insert(pData);
}

int main() {
  Data* pData;
  LinkedList ll;
  int val;

  while (true) {
    std::cout << "What value (0 - stop)? ";
    std::cin >> val;

    if (!val) {
      break;
    }

    pData = new Data(val);
    ll.insert(pData);
  }

  ll.showAll();
  return 0;
}

// whats going on here?
// 3 base classes: Data, Node, LinkedList
// Node is an abstract data type that delegates functionality to its derived
// classes: HeadNode, TailNode, and InternalNode
// HeadNode knows to always knows to place a node behind it and point to it
// TailNode knows to always knows to always place a node in front of it
// InternalNode does the work at comparing its data to the data in the node that
// it gets passed forward to (or back from HeadNode)

// questions
// why does the case kIsLarger statement need to be wrapped in curly braces?

// try wrapping this in a sort function as if you were to build a JS sort method
