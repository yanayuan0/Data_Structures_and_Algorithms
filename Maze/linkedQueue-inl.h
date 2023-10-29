/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
}

template <typename T> int LinkedQueue<T>::getSize() {
  //return this->getSize();
  return actualList.getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
  return actualList.isEmpty();
}

template <typename T> T LinkedQueue<T>::peek() {
  return actualList.getFirst();
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
  actualList.insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
  return actualList.removeFirst();
}

template <typename T> void LinkedQueue<T>::insert(T element) {
  // NOTE: for a hint on how to implement this, see LinkedStack<T>::insert
  this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
  return this->dequeue();
}
