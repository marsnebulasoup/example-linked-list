/*********************
Name: Kevin Bryniak
Assignment: Linked List
A example implementation of a linked list.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class LinkedList
{
private:
  Node *head;

  void printListForwards(Node *);
  void printListReverse(Node *);

public:
  LinkedList();
  ~LinkedList();

  bool addNode(int, string *);
  bool deleteNode(int);
  bool getNode(int, Data *);
  void printList(bool = false);
  int getCount();
  bool clearList();
  bool exists(int);
};

#endif