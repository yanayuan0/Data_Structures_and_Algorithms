/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "quickSort.h"

// TODO: you will need to write an appropriate "partition" function here
// It does not need to be in your header file because no one else will call it.

void swap(int *array, int left, int right){
  int holder = array[left];
  array[left] = array[right];
  array[right] = holder;
}

int partition(int *array, int startIndex, int endIndex){
  int pivotVal = array[endIndex];
  int left = startIndex;
  int right = endIndex - 1;
  while(left <= right){
    if (array[left] <= pivotVal){
      left++;
    } else if (array[right] >= pivotVal){
      right--;
    } else{
      swap(array, left, right);
    }
  }
  swap(array, left, endIndex);
  return left;
}

void quickSort(int *array, int startIndex, int endIndex) {
  if (startIndex < endIndex){
    int pivotPos = partition(array, startIndex, endIndex);
    quickSort(array, startIndex, pivotPos-1);
    quickSort(array, pivotPos+1, endIndex);
  }
}

// You should not need to modify this function.
// qSort is a wrapper around the main quickSort function.
void qSort(int *array, int size) {
  quickSort(array, 0, size - 1);
}