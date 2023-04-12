// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

struct SYM {
  char ch;
  int prior;
};

template <typename T, int size>
class TPQueue {
 private:
  struct NODE {
    SYM data;
    NODE* next;
  };
  NODE* head;
  int members;
  NODE* create(SYM);

 public:
  TPQueue();
  int push(SYM);
  bool isFull();
  bool isEmpty();
  SYM pop();
};

template <typename T, int size>
TPQueue<T, size>::TPQueue():head(nullptr), members(0){}

template <typename T, int size>
typename TPQueue<T, size>::NODE* TPQueue<T, size>::create(SYM value) {
  NODE* temp = new NODE;
  temp->data.ch = value.ch;
  temp->data.prior = value.prior;
  temp->next = nullptr;
  return temp;
}

template <typename T, int size>
bool TPQueue<T, size>::isEmpty() {
  return head == nullptr;
}

template <typename T, int size>
bool TPQueue<T, size>::isFull() {
  return members == size;
}

template <typename T, int size>
int TPQueue<T, size>::push(SYM item) {
    if (isFull()) throw std::string("Full");
    if (isEmpty()) {
    head = create(item);
    members++;
    }
    NODE* temp = create(item);
    int counter = members;
    NODE* current = head;
    if (current->data.prior < temp->data.prior) {
      temp->next = current;
      head = temp;
      members++;
      return 1;
    }
    while (counter - 1) {
      if (current->data.prior >= temp->data.prior && current->next->data.prior < temp->data.prior) {
        temp->next = current->next;
        current->next = temp;
        members++;
        return 1;
      }
      current = current->next;
      counter -= 1;
    }
    current->next = temp;
    temp->next = head;
    members++;
    return 1;
  }

template <typename T, int size>
SYM TPQueue<T, size>::pop() {
    if (isEmpty()) throw std::string("Empty");
    SYM temp = head->data;
    head = head->next;
    return temp;
}

#endif  // INCLUDE_TPQUEUE_H_
