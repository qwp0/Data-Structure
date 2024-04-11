#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
  head = nullptr;
}

LinkedList::~LinkedList() {
  while (head != nullptr) {
      Node* temp = head;
      head = temp->next;
      delete temp;
  }
}

void LinkedList::append(int data){
  Node* newNode = new Node();
  newNode->data = data;
  Node* temp = new Node();
  temp = head;
  if(head == nullptr){
    head = newNode;
    return;
  }
  while(temp->next != nullptr){
    temp = temp->next;
  }
  temp-> next = newNode;
}

int LinkedList::length(){
  int count = 0;
  Node* temp = new Node();
  temp = head;
  while(temp != nullptr){
    count++;
    temp = temp->next;
  }
  return count;
}

void LinkedList::print(){
  Node* temp = new Node();
  temp = head;
  while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
  
}