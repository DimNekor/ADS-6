// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
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
  void pop();
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
