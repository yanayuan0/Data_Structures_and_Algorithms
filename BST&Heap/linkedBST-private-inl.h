/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::findInSubtree");
    if (current == nullptr){
        throw runtime_error("findInSubtree: key not in tree");
    } if (key == current->getKey()){
        return current->getValue();
    } else if (key < current->getKey()){
        return findInSubtree(current->getLeft(), key);
    } else{
        return findInSubtree(current->getRight(), key);
    }
}

 
template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    //throw runtime_error(
    //    "Not yet implemented: LinkedBST<K,V>::containsInSubtree");
    if (current == nullptr){
        return false;
    } else{
        if (current->getKey() == key){
            return true;
        } else if (key < current->getKey()){
            return containsInSubtree(current->getLeft(), key);
        } else{
            return containsInSubtree(current->getRight(), key);
        }
    }
}


template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key,
                                      V value) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::updateInSubtree");
    if (!containsInSubtree(current, key)){
        throw runtime_error("updateInSubtree key not found");
    } if (key == current->getKey()){
        current->setValue(value);
    } else if(key < current->getKey()){
        return updateInSubtree(current->getLeft(), key, value);
    } else{
        return updateInSubtree(current->getRight(), key, value);
    }

}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return -1;
    }    
    int leftH = getHeightInSubtree(current->getLeft());
    int rightH = getHeightInSubtree(current->getRight());

    if (leftH >= rightH) {
        return 1+leftH;
    }
    return 1+rightH;
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        throw runtime_error("getMinInSubtree: Your Binary Search Tree is empty."); // What's the standard error message for this scenario?
    }    
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return make_pair(current->getKey(), current->getValue());
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        throw runtime_error("getMaxInSubtree: Your Binary Search Tree is empty."); // What's the standard error message for this scenario?
    }    
    while (current->getRight() != nullptr) {
        current = current->getRight();
    }
    return make_pair(current->getKey(), current->getValue());
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::insertInSubtree");
    if (current == nullptr){
        LinkedBSTNode<K,V>* newnode = new LinkedBSTNode<K,V>(key, value);
        return newnode;
    } if (key == current->getKey()){
        throw runtime_error("insertInSubtree: No duplicate keys allowed");
    } if (key < current->getKey()){
        current->setLeft(insertInSubtree(current->getLeft(), key, value));
        return current;
    } else{
        current->setRight(insertInSubtree(current->getRight(), key, value));
        return current;
    }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        throw runtime_error("removeFromSubtree: key not in tree");
    } if (key < current->getKey()){
        current->setLeft(removeFromSubtree(current->getLeft(), key));
        return current;
    } else if (key > current->getKey()){
        current->setRight(removeFromSubtree(current->getRight(), key));
        return current;
    } else{
        if (current->getLeft() == nullptr && current->getRight() == nullptr){
            delete current;
            current = nullptr;
            return current;
        } if (current->getLeft() == nullptr){
            LinkedBSTNode<K, V>* temp = current->getRight();
            delete current;
            return temp;
        } if (current->getRight() == nullptr){
            LinkedBSTNode<K, V>* temp = current->getLeft();
            delete current;
            return temp;
        } else{
            LinkedBSTNode<K, V>* temp = current->getLeft();
            while (temp->getRight() != nullptr){
                temp = temp->getRight();
            }
            current->setKey(temp->getKey());
            current->setValue(temp->getValue());
            current->setLeft(removeFromSubtree(current->getLeft(), temp->getKey()));
            return current;
        }
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
    if (current != nullptr) {
        deleteSubtree(current->getLeft());
        deleteSubtree(current->getRight());
        delete current;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    pair<K, V> pair (current->getKey(), current->getValue());
    list->insertLast(pair);
    buildPreOrderTraversal(current->getLeft(), list);
    buildPreOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    buildInOrderTraversal(current->getLeft(), list);
    pair<K, V> pair (current->getKey(), current->getValue());
    list->insertLast(pair);
    buildInOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    buildPostOrderTraversal(current->getLeft(), list);
    buildPostOrderTraversal(current->getRight(), list);
    pair<K, V> pair (current->getKey(), current->getValue());
    list->insertLast(pair);
}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}