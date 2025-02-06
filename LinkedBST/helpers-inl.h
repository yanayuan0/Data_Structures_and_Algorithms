/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "helpers.h"
#include <vector>
using namespace std;

template <typename T> vector<T> dynamicListToStaticVector(List<T>* list) {
  
  vector<T> vector1;
  while (!list->isEmpty()){
    vector1.push_back(list->removeFirst());
  }
  return vector1;
  
  
}


