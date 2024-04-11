#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
  head=nullptr;
  tail=nullptr;
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
  if(head == nullptr){
    head = newNode;
    tail = newNode;
  }
  else{
    newNode->prev = tail;
    tail->next = newNode;
    tail=newNode;
  }
}

void LinkedList::prepend(int data){
  Node* newNode = new Node();
  newNode->data = data;
  if(head == nullptr){
    head = newNode;
    tail = newNode;
  }
  else{
    newNode->next=head;
    head->prev = newNode;
    head= newNode;
  }
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

void LinkedList::printReverse(){
  Node* temp = new Node();
  temp=tail;
  while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->prev;
  }
  cout<<endl;
}