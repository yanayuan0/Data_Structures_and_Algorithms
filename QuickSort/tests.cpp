/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "quickSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  quickSort(array, 0, 2);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size-1; i++) {
    CHECK(array[i] < array[i+1]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

TEST(duplicates) {
  // Create a static array with repeated numbers
  int array[6] = {1, 3, 2, 3, 4, 1};
  quickSort(array, 0, 5);
  CHECK_EQUAL(1, array[0]);
  CHECK_EQUAL(1, array[1]);
  CHECK_EQUAL(2, array[2]);
  CHECK_EQUAL(3, array[3]);
  CHECK_EQUAL(3, array[4]);
  CHECK_EQUAL(4, array[5]);
}

TEST(singleElement) {
  // Create a static array with only one number
  int array[1] = {3};
  quickSort(array,0,0);
  CHECK_EQUAL(3,array[0]);
}

TEST(sortedArray){
  // Create a static array that is already sorted
  int array[3] = {1,2,3};
  quickSort(array, 0, 2);
  CHECK_EQUAL(1, array[0]);
  CHECK_EQUAL(2, array[1]);
  CHECK_EQUAL(3, array[2]);
}

TEST(reverseunsorted) {
  // Create a dynamically allocated array of this order:
  // 0, 999, 1, 998...
  int size = 1000;
  int *array = new int[size];
  for (int i=0; i<size; i=i+2){
    array[i] = i/2;
    array[i+1] = 1000 - array[i];
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i<size-1; i++){
    CHECK(array[i]<array[i+1]);
  }
  delete[] array;
  array = nullptr;
}

/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
