// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
#include <iostream>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
  T* mas;
  int head, tail, count;

 public:
  TPQueue();
  bool isEmpty();
  bool isFull();
  int push(T);
  T pop();
  ~TPQueue();
};


template<typename T, int size>
TPQueue<T, size>::TPQueue() {
  mas = new T[size];
  head = 0;
  tail = 0;
  count = 0;
}

template<typename T, int size>
bool TPQueue<T, size>::isEmpty() {
  return count == 0;
}

template<typename T, int size>
bool TPQueue<T, size>::isFull() {
  return count == size;
}

template<typename T, int size>
int TPQueue<T, size>::push(T data) {
  if (isFull())
    throw std::string("Full!");
  else if (isEmpty()) {
    count++;
    mas[head % size] = data;
  } else {
    int current = head;
    int counter = count;
    if (mas[current % size].prior < data.prior) {
      int currT = tail;
      while (counter) {
        mas[(currT + 1) % size] = mas[(currT) % size];
        counter--;
        currT--;
      }
      count++;
      tail++;
      mas[head % size] = data;
      return 1;
    }
    while (counter - 1) {
      if (mas[current % size].prior >= data.prior &&
          mas[(current + 1) % size].prior < data.prior) {
        int flag = current + 1;
        int currT = tail;
        while (counter - 1) {
          mas[(currT + 1) % size] = mas[(currT) % size];
          counter--;
          currT--;
        }
        mas[flag % size] = data;
        count++;
        tail++;
        return 1;
      }
      counter--;
      current++;
    }
    mas[(tail + 1) % size] = data;
    tail++;
    count++;
    return 1;
  }
}

template<typename T, int size>
T TPQueue<T, size>::pop() {
  T temp = mas[head];
  head++;
  count--;
  return temp;
}

template<typename T, int size>
TPQueue<T, size>::~TPQueue() {
  delete[] mas;
}

#endif  // INCLUDE_TPQUEUE_H_
