#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template <typename E>
class LinkedList;

template <typename E>
class Node {
public:
  Node(const E& data) : data(data), next(nullptr), prev(nullptr) {}
private:
  E data;
  Node<E>* next;
  Node<E>* prev;
  friend class LinkedList<E>;
};

template<typename E>
class LinkedList {
public:
  LinkedList(int maxEntry){
    head=nullptr;
    tail=nullptr;
    this->maxEntry=maxEntry;
  };
  ~LinkedList() {
    while (head != nullptr) {
      Node<E>* temp = head;
        head = head->next;
        delete temp;
      }
  }

  void add(const E& data) {
    Node<E>* newNode = new Node<E>(data);
      if (head == nullptr) {
        head = tail = newNode;
      } 
      else {
        Node<E>* temp = head;
        while (temp && temp->data > newNode->data) {
          temp = temp->next;
        }
        if (!temp) {
          tail->next = newNode;
          newNode->prev = tail;
          tail = newNode;
        } 
        else {
          if (temp->prev) {
            temp->prev->next = newNode;
          } 
          else {
            head = newNode;
          }
          newNode->prev = temp->prev;
          newNode->next = temp;
          temp->prev = newNode;
        }
      }
      while (length() > maxEntry) {
        Node<E>* remove = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete remove;
      }
    }

    int length() {
      Node<E>* temp = head;
      int count = 0;
      while (temp) {
        count++;
        temp = temp->next;
      }
      return count;
    }

    void print() {
      Node<E>* temp = head;
      while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }

    void printReverse() {
      Node<E>* temp = tail;
      while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
      }
      cout << endl;
    }

private:
  Node<E>* head;
  Node<E>* tail;
  int maxEntry;
};

#endif