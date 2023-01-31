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
  Node *newNode = createNode(id, data);
  if (newNode)
  {
    head = newNode;
    head->prev = head->next = NULL;
  }
  return true;
}

bool LinkedList::addBefore(Node *current, int id, string *data)
{
  bool wasAdded = false;
  Node *newNode;
  if (current && (newNode = createNode(id, data)))
  {
    (current->prev ? current->prev->next : head) = newNode; // link the new node to the previous node; if no previous node, then the head.
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
  Node *newNode;
  if (current && (newNode = createNode(id, data)))
  {
    newNode->prev = current;
    newNode->next = NULL;
    current->next = newNode;
    wasAdded = true;
  }
  return wasAdded;
}

bool LinkedList::deleteNode(int id)
{
  bool wasDeleted = false;
  if (id > 0)
  {
    Node *current = head;
    while (current && current->next && current->data.id < id)
    {
      current = current->next;
    }
    if (current && current->data.id == id)
    {
      (current->prev ? current->prev->next : head) = current->next; // link the previous node to the next if there is a previous node; otherwise link the head to it
      if (current->next)
      {
        current->next->prev = current->prev;
      }
      delete current;
      wasDeleted = true;
    }
  }
  return wasDeleted;
}

bool LinkedList::getNode(int id, Data *data)
{
  bool wasFound = false;
  if (id > 0 && data)
  {
    Node *current = head;
    while (current && current->next && current->data.id < id)
    {
      current = current->next;
    }
    if (current && current->data.id == id)
    {
      data->id = current->data.id;
      data->data = current->data.data;
      wasFound = true;
    }
    else
    {
      data->id = -1;
      data->data = "";
    }
  }
  return wasFound;
}

Node *LinkedList::createNode(int id, string *data)
{
  Node *newNode = NULL;
  if (id > 0 && data->length() > 0)
  {
    newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
  }
  return newNode;
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
  cout << "--- Linked List ----------" << endl;
  reverse ? printListReverse(head) : printListForwards(head);
  cout << "--- End List -------------" << endl;
}

int LinkedList::getCount()
{
  int count = 0;
  if (head)
  {
    Node *current = head;
    count++;
    while (current->next)
    {
      count++;
      current = current->next;
    }
  }
  return count;
}

bool LinkedList::clearList()
{
  bool wasCleared = false;
  if (head)
  {
    Node *current = head;
    while (current->next)
    {
      current = current->next;
      delete current->prev;
    }
    delete current;
    head = NULL;
    wasCleared = true;
  }
  return wasCleared;
}

bool LinkedList::exists(int id)
{
  bool wasFound = false;
  if (id > 0)
  {
    Node *current = head;
    while (current && current->next && current->data.id < id)
    {
      current = current->next;
    }
    if (current && current->data.id == id)
    {
      wasFound = true;
    }
  }
  return wasFound;
}
