#ifndef LIST_H
#define LIST_H

class Node{
private:
  int data;
  Node* next;
  friend class LinkedList;
};

class LinkedList{
public:
  LinkedList();
  ~LinkedList();
  void append(int data);
  int length();
  void print();
private:
  Node* head;
};

#endif