#include <cstdio>
#include "FixedStack.h"

FixedStack::FixedStack(int max) {
  this->head = NULL;
  this->maxLength = max;
  this->length = 0;
}

Node* FixedStack::push(int x, int y) {
  Node* node = new Node(x, y);

  if (!isEmpty()) {
    if (length < maxLength) {
      Node* temp = this->head;
      this->head = node;
      node->next = temp;
      this->length++;
      return NULL;
    }else{
      Node* temp = this->head;
      this->head = node;
      node->next = temp;

      temp = this->head;
      while (temp->next->next) {
        temp = temp->next;
      }
      Node* tr = temp->next;
      temp->next = NULL;
      return tr;
    }
  }else {
    node->next = NULL;
    this->head = node;
    this->length++;
    return NULL;
  }
}

bool FixedStack::isEmpty() {
  if (this->head)
    return false;
  return true;
}

void FixedStack::incrementMaxSize(int x, int y) {
  Node* temp = this->head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = new Node(x, y);
  this->maxLength++;
  this->length++;
}
