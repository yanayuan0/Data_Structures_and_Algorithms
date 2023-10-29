/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main() {
  /*
  LinkedList<int>* newList = new LinkedList<int>();
  newList->insertFirst(5);
  cout << "first is: " << newList->getFirst() << endl;

  newList->insertFirst(10);
  cout << "first is: " << newList->getFirst() << endl;
  newList->insertFirst(20);
  cout << "first is: " << newList->getFirst() << endl;
  newList->insertLast(30);
  cout << "last is: " << newList->getLast() << endl;
  cout << "size is: " << newList->getSize() << endl;
  newList->removeFirst();
  newList->removeLast();
  cout << "first and last removed." << endl;
  cout << "first is: " << newList->getFirst() << endl;
  cout << "last is: " << newList->getLast() << endl;
  cout << "size is: " << newList->getSize() << endl;
  cout << "second number is: " << newList->get(1) << endl;

  newList->checkInvariants();

  delete newList;
  */

  /*
  LinkedList<int> list;
  list.insertLast(2); // [2]
  list.insertLast(6); // [2,6]
  list.insertLast(3); // [2,6,3]
  if (!list.isEmpty()){
    cout << "is not empty" << endl;
  }
  list.removeFirst(); // [6,3]
  list.removeFirst(); // [3]
  cout << list.getFirst() << endl; // 3
  list.removeFirst(); // []
  if (list.isEmpty()){
    cout << "is empty" << endl;
  }
  cout << list.getSize() << endl;

  list.insertLast(3); // [3]
  if (!list.isEmpty()){
    cout << "is not empty" << endl;
  }
  cout << list.getSize() << endl; //1
  cout << list.getFirst() << endl; //3
  cout << list.removeLast() << endl; // 3 []
  if (list.isEmpty()){
    cout << "is empty" << endl;
  }
  cout << list.getSize() << endl; //0
  //CHECK_THROW(list.get(0), std::runtime_error);
  list.insertFirst(5); // [5]
  if (!list.isEmpty()){
    cout << "is not empty" << endl;
  }
  cout << list.getSize() << endl; //1
  cout << list.get(0) << endl;//5
  list.checkInvariants();
  */
  
  
  List<pair<int, string>>* lst = loadMovie("test_data/smiley.asciimation");
  cout << lst->getFirst().second << endl;
  cout << lst->getLast().second << endl;
  playMovie(lst);
  delete lst;
  /*
  LinkedList<pair<int, string>>* rlst = new LinkedList<pair<int, string>>();
  LinkedListNode<pair<int, string>>* current = rlst->head;
  while (current != nullptr) {
    rlst->insertFirst(current->value);
    current = current->next;
  }
  cout << rlst->getFirst().second << endl;

  delete lst;
  delete rlst;
  */


  /*
  LinkedList<pair<int, string>>* rlst = loadMovie("test_data/smiley.asciimation");
  //LinkedListNode<pair<int, string>>* current = new LinkedListNode<pair<int, string>>(lst->getFirst(), nullptr);
  
  LinkedListNode<pair<int, string>>* current;
  current = lst->head;

  while(current != nullptr) {
    rlst->insertFirst(current->value);
    current = current->next;
  }

  cout << rlst->getFirst().second << endl;
  cout << rlst->getLast().second << endl;

  //playMovie(rlst);
  delete lst;
  delete current;
  delete rlst;
  */


  /*
  LinkedListNode<T>* current = this->head;
  int count = 0;
  while (current != nullptr) {
      if (count == index){
          return (current->value);
      }
      count++;
      current = current->next;
  }
  return current->value;
  */
  

  return 0;
}
