#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {
 public:
  //A node needs a student pointer and the next node it points to
  Node(Student*);
  //Destructor
  ~Node();
  //Get the node it points to 
  Node* getNext();
  //Set the node it points to 
  void setNext(Node*);
  //Get the student that it's holding
  Student* getStudent();
 private:
  Student* student;
  Node* next;
};
#endif
