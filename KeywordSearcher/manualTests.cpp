/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <string>
#include "hashTable.h"

using namespace std;

int main(int argc, char** argv) {
  /*
  Dictionary<int, string>* dictionary = new LinearDictionary<int, string>();
  dictionary->insert(3, "three");
  dictionary->insert(4, "four");
  cout << dictionary->getSize() << endl;
  if (!dictionary->isEmpty()){
    cout << "is not empty" << endl;
  }
  dictionary->update(3, "updatedthree");
  vector<int> keys = dictionary->getKeys();
  cout << keys[0] << endl;
  cout << keys[1] << endl;
  vector<pair<int, string>> items = dictionary->getItems();
  cout << items[0].first << endl;
  cout << dictionary->get(3) << endl;
  dictionary->remove(3);
  cout << dictionary->getSize() << endl;
  */

  /*
  HashTable<int, string>* table = new HashTable<int, string>();
  
  if (table->isEmpty()){
    cout << "is empty" << endl;
  }
  table->insert(3, "three");
  table->insert(4, "four");
  table->insert(5, "five");
  cout << table->getSize() << endl;
  if (!table->isEmpty()){
    cout << "is not empty" << endl;
  }
  table->update(3, "updatedthree");
  cout << table->get(3) << endl;
  table->remove(3);
  vector<int> keys = table->getKeys();
  cout << keys[0] << endl;
  cout << keys[1] << endl;
  
  for (int i = 0; i < 10; i++) {
    table->insert(i, to_string(i));
  }
  vector<int> keys = table->getKeys();
  for (int i = 0; i < 10; i++) {
    cout << keys[i] << endl;
  }
  */

  return 0;
}
