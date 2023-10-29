/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedStack<T>::LinkedStack() {
}

template <typename T> void LinkedStack<T>::push(T element) {
  //throw runtime_error("Not yet implemented: LinkedStack::push");
  actualList.insertFirst(element);
}

template <typename T> T LinkedStack<T>::pop() {
  //throw runtime_error("Not yet implemented: LinkedStack::pop");
  return actualList.removeFirst();
}

template <typename T> void LinkedStack<T>::insert(T element) {
  // To "insert" into a stack is to push onto it.  So when we are told to
  // insert, we will push.
  this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
  //throw runtime_error("Not yet implemented: LinkedStack::remove");
  return this->pop();
}

template <typename T> int LinkedStack<T>::getSize() {
  //throw runtime_error("Not yet implemented: LinkedStack::getSize");
  return actualList.getSize();
}

template <typename T> bool LinkedStack<T>::isEmpty() {
  //throw runtime_error("Not yet implemented: LinkedStack::isEmpty");
  return actualList.isEmpty();
}

template <typename T> T LinkedStack<T>::peek() {
  //throw runtime_error("Not yet implemented: LinkedStack::peek");
  return actualList.getFirst();
}
