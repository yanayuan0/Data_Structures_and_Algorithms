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
#include <vector>
#include "adts/stlList.h"
#include "helpers.h"
#include "adts/BST.h"
#include "adts/list.h"
#include "linkedBST.h"
#include "linkedBSTNode.h"

using std::pair;
using std::vector;
using namespace std;

int main() {
  /*
  List<int>* listPointer1 = new STLList<int>();
  listPointer1->insertLast(4);
  listPointer1->insertLast(8);
  vector<int> vector1 = dynamicListToStaticVector(listPointer1);
  cout << vector1.size() << endl;
  cout << vector1[0] << endl;
  */

  LinkedBST<int, string>* bst = new LinkedBST<int, string>();
    bst->insert(6, "6");
    bst->insert(2, "2");
    bst->insert(7, "7");
    bst->insert(1, "1");
    bst->insert(4, "4");
    bst->insert(9, "9");
    bst->insert(3, "3");
    vector<int> keyslist = bst->getKeys();
    cout << keyslist[0] << endl;
    cout << keyslist[1] << endl;
    cout << keyslist[2] << endl;
  //cout << bst->getSize() << endl;
  //cout << bst->get(5) << endl;
  //bst->update(5, "4");
  //cout << bst->get(5) << endl;
  //vector<pair<int, string>> vector1 = bst->traverseLevelOrder();
  //cout << vector1[0].first << endl;


  

  return 0;
}
