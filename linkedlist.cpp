/*********************
Name: Kevin Bryniak
Assignment: Linked List
A example implementation of a linked list.
**********************/
#include "linkedlist.h"

LinkedList::LinkedList()
{
  head = NULL;
  Node *newData, *position;

  for (int i = 0; i < 5; i++)
  {

    // create Data
    newData = new Node;
    newData->data = Data{i, "random data"};

    // attached it
    if (head == NULL)
    {
      // it's the first Data
      head = newData;
      position = head;
    }
    else
    {
      // not the first Data
      position->next = newData;
      position = newData;
    }
  }
}

LinkedList::~LinkedList()
{
  clearList();
}

bool LinkedList::addNode(int id, string *data)
{
  return true;
}

bool LinkedList::deleteNode(int id)
{
  return true;
}

bool LinkedList::getNode(int, Data *)
{
  return true;
}

void LinkedList::printListForwards(Node *current)
{
  if (current)
  {
    cout << current->data.id << " | " << current->data.data << endl;
    printListForwards(current->next);
  }
}

void LinkedList::printListReverse(Node *current)
{
  if (current)
  {
    printListReverse(current->next);
    cout << current->data.id << " | " << current->data.data << endl;
  }
}

void LinkedList::printList(bool reverse)
{
  cout << "Linked List ----------" << endl;
  reverse ? printListReverse(head) : printListForwards(head);
}

int LinkedList::getCount()
{
  return 0;
}

bool LinkedList::clearList()
{
  return true;
}

bool LinkedList::exists(int id)
{
  return true;
}