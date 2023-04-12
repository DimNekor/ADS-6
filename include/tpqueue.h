// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

#pragma once
#include <iostream>

struct SYM {
  char ch;
  int prior;
  SYM* next;
};

template <typename T, int size>
class TPQueue {
 private:
  struct T {
    char ch;
    int prior;
    T* next;
  };
  T *head;
  static int members;
  int size;
  TPQueue::T* create(const char&, const int&);

 public:
  TPQueue();
  int countMembers() {
    members++;
    return members;
  };
  int countMembers1() {
    members--;
    return members;
  }
  int push(SYM);
  int getCurSize();
  bool isFull();
  bool isEmpty();
  SYM pop();
  void display();
  
};
template<typename T, int size>
int TPQueue<T, size>::members = 0;

template <typename T, int size>
TPQueue<T, size>::TPQueue() {
  head = nullptr;
}
template <typename T, int size>
int TPQueue<T, size>::getCurSize() {
  return members;
}

template <typename T, int size>
typename TPQueue<T, size>::T* TPQueue<T, size>::create(const char& ch,
                                                       const int& prior) {
  T* temp = new T;
  temp->ch = ch;
  temp->prior = prior;
  temp->next = nullptr;
  return temp;
}

template <typename T, int size>
bool TPQueue<T, size>::isEmpty() {
  if (head == nullptr) return true;
  return false;
}
template <typename T, int size>
bool TPQueue<T, size>::isFull() {
  if (getCurSize() == size)
    return true;
  else
    return false;
}

template <typename T, int size>
int TPQueue<T, size>::push(SYM item) {
  if (isEmpty()) {
    head = create(item.ch, item.prior);
    countMembers();
  }
  else if (!isFull()) {
    T* temp = create(item.ch, item.prior);
    int counter = members;
    T* current = head;
    if (current->prior < temp->prior) {
      temp->next = current;
      head = temp;
      countMembers();
      return 1;
    }
    while (counter - 1) {
      if (current->prior >= temp->prior && current->next->prior < temp->prior) {
        temp->next = current->next;
        current->next = temp;
        countMembers();
        return 1;
      }
      current = current->next;
      counter -= 1;
    }
    current->next = temp;
    temp->next = head;
    countMembers();
    return 1;
    }
  }
template <typename T, int size>
SYM TPQueue<T, size>::pop() {
  if (!isEmpty()) {
    T temp;
    temp.ch = head->ch;
    temp.prior = head->prior;
    temp.next = nullptr;
    head = head->next;
    return *temp;
  }
}

#endif  // INCLUDE_TPQUEUE_H_
