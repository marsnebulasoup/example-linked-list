/*********************
Name: Kevin Bryniak
Assignment: Linked List
A example implementation of a linked list.
**********************/
#include "linkedlist.h"

LinkedList::LinkedList()
{
  head = NULL;
}

LinkedList::~LinkedList()
{
  clearList();
}

bool LinkedList::addNode(int id, string *data)
{
  bool wasAdded = false;
  if (id > 0 && data->length() > 0)
  {
    Node *current = head;
    while (current && current->next && current->data.id < id)
    {
      current = current->next;
    }
    if (current && id != current->data.id) // list is not empty (and id not already in list)
    {
      wasAdded = id < current->data.id ? addBefore(current, id, data) : addTail(current, id, data);
    }
    else if (!current) // list is empty
    {
      wasAdded = addHead(id, data);
    }
  }
  return wasAdded;
}

bool LinkedList::addHead(int id, string *data)
{
  Node *newNode = new Node;
  Data *newData = new Data{id, *data};
  newNode->data = *newData;
  head = newNode;
  head->prev = head->next = NULL;
  return true;
}

bool LinkedList::addBefore(Node *current, int id, string *data)
{
  bool wasAdded = false;
  if (current)
  {
    Node *newNode = new Node;
    Data *newData = new Data{id, *data};
    newNode->data = *newData;
    (current->prev ? current->prev->next : head) = newNode;
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev = newNode;
    wasAdded = true;
  }
  return wasAdded;
}

bool LinkedList::addTail(Node *current, int id, string *data)
{
  bool wasAdded = false;
  if (current)
  {
    Node *newNode = new Node;
    Data *newData = new Data{id, *data};
    newNode->data = *newData;

    newNode->prev = current;
    newNode->next = NULL;
    current->next = newNode;
    wasAdded = true;
  }
  return wasAdded;
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