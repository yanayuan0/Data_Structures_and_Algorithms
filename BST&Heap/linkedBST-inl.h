/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>
#include <vector>

#include "adts/list.h"
#include "adts/queue.h"
#include "adts/stlList.h"
#include "adts/stlQueue.h"

#include "linkedBSTNode.h"
#include "helpers.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinkedBST<K, V>::LinkedBST() {
  this->size = 0;
  this->root = nullptr; //CHECK
}

template <typename K, typename V> LinkedBST<K, V>::~LinkedBST() {
  deleteSubtree(this->root); //CHECK because of constructor 
}

template <typename K, typename V> int LinkedBST<K, V>::getSize() {
  return countNodes(this->root);
}

template <typename K, typename V> bool LinkedBST<K, V>::isEmpty() {
  return (countNodes(this->root) == 0);
}

template <typename K, typename V> void LinkedBST<K, V>::insert(K key, V value) {
  // Use the helper insertInSubtree
  this->root = insertInSubtree(this->root, key, value);
  this->size ++;
}

template <typename K, typename V> void LinkedBST<K, V>::update(K key, V value) {
  // Use the helper updateInSubtree
  updateInSubtree(this->root, key, value);
}

template <typename K, typename V> V LinkedBST<K, V>::get(K key) {
  // Use the helper findInSubtree
  return findInSubtree(this->root, key);
}

template <typename K, typename V> bool LinkedBST<K, V>::contains(K key) {
  // Use the helper containsInSubtree
  return containsInSubtree(this->root, key);
}

template <typename K, typename V> void LinkedBST<K, V>::remove(K key) {
  // Use the helper removeFromSubtree
  this->root = removeFromSubtree(this->root, key);
  this->size --;

}

template <typename K, typename V> vector<K> LinkedBST<K, V>::getKeys() {
  // Use one of the traversals
  if (this->root == nullptr) {
    vector<K> emptyvector;
    return emptyvector;
  }
  List<pair<K, V>>* list = new STLList<pair<K, V>>();
  buildPreOrderTraversal(this->root, list); 

  vector<K> finalList;
  int listsize = list->getSize();
  for (int i = 0; i < listsize; i++) { 
    finalList.push_back(list->removeFirst().first);
  }
  delete list;
  return finalList;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
  // Use one of the traversals
  if (this->root == nullptr) {
    vector<pair<K, V>> emptyvector;
    return emptyvector;
  }
  List<pair<K, V>>* list = new STLList<pair<K, V>>();
  buildPreOrderTraversal(this->root, list);
  vector<pair<K, V>> finalList = dynamicListToStaticVector(list);
  delete list;
  return finalList;
}

template <typename K, typename V> int LinkedBST<K, V>::getHeight() {
  // Use the helper getHeightInSubtree
  return getHeightInSubtree(this->root);
}

template <typename K, typename V> K LinkedBST<K, V>::getMaxKey() {
  // Use the helper getMaxInSubtree
  pair<K, V> myPair = getMaxInSubtree(this->root);
  return myPair.first;
}

template <typename K, typename V> K LinkedBST<K, V>::getMinKey() {
  // Use the helper getMinInSubtree
  pair<K, V> myPair = getMinInSubtree(this->root);
  return myPair.first;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
  // Use the helper buildPreOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* list = new STLList<pair<K,V>>();
  buildPreOrderTraversal(this->root, list);
  vector<pair<K, V>> vectors = dynamicListToStaticVector(list);
  delete list;
  return vectors;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
  // Use the helper buildInOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* list = new STLList<pair<K,V>>();
  buildInOrderTraversal(this->root, list);
  vector<pair<K, V>> vectors = dynamicListToStaticVector(list);
  delete list;
  return vectors;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
  // Use the helper buildPostOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K, V>>* list = new STLList<pair<K,V>>();
  buildPostOrderTraversal(this->root, list);
  vector<pair<K, V>> vectors = dynamicListToStaticVector(list);
  delete list;
  return vectors;
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
  // Do a breadth-first search (no need to mark visited or generate path)
  vector<pair<K, V>> result;
  if (this->root == nullptr) {
    return result;
  }
  queue<LinkedBSTNode<K, V>*> q;
  q.push(this->root);
  while (!q.empty()) {
    LinkedBSTNode<K, V>* current = q.front();
    q.pop();
    result.push_back(make_pair(current->getKey(), current->getValue()));
    if (current->getLeft() != nullptr) {
      q.push(current->getLeft());
    }
    if (current->getRight() != nullptr) {
      q.push(current->getRight());
    }
  }
  return result;
}

template <typename K, typename V> void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
      throw runtime_error(
        "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
      // The bounds provided here are arbitrary because the false
      // arguments indicate that they do not apply.  But we need a
      // value of type K to fill this parameter since we don't have
      // globally min/max K values generically.
      this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                false, this->root->getKey());
    }
}
