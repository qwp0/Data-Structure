#ifndef LIST_H
#define LIST_H

class Node{
private:
  int data;
  Node* next;
  Node* prev;
  friend class LinkedList;
};

class LinkedList{
public:
  LinkedList();
  ~LinkedList();
  void append(int data);
  void prepend(int data);
  int length();
  void print();
  void printReverse();
private:
  Node* head;
  Node* tail;
};

#endif