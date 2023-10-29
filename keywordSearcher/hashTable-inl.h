/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->size = 0;
    this->capacity = 10;
    this->maxLoadFactor = 0.75;
    this->table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->size = 0;
    this->capacity = 10;
    this->maxLoadFactor = maxLoadFactor;
    this->table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->table;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return (this->size == 0);
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key, this->capacity);
    if (this->table[index].contains(key)){
        throw runtime_error("HashTable insert(): no duplicates allowed");
    }
    table[index].insert(key, value);
    this->size ++;
    float load = float(this->size)/this->capacity;
    if (load > this->maxLoadFactor){
        this->expandCapacity();
    }
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key, this->capacity);
    if (!this->table[index].contains(key)){
        throw runtime_error("HashTable update(): key not found");
    }
    table[index].update(key, value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key, this->capacity);
    return table[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int index = hash(key, this->capacity);
    vector<K> keys = this->table[index].getKeys();
    for (int i=0; i < this->table[index].getSize(); i++){
        if (keys[i] == key){
            return true;
        }
    }
    return false;

}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int index = hash(key, this->capacity);
    table[index].remove(key);
    this->size --;
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> result;
    for (int i=0; i < this->capacity; i++){
        vector<K> keys = this->table[i].getKeys();
        for (int j=0; j < keys.size(); j++){
            result.push_back(keys[j]);
        }
    }
    return result;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K, V>> result;
    for (int i=0; i < this->capacity; i++){
        vector<pair<K, V>> items = this->table[i].getItems();
        for (int j=0; j < items.size(); j++){
            result.push_back(items[j]);
        }
    }
    return result;
}

template <typename K, typename V> void HashTable<K, V>::expandCapacity(){
    /*
    int cap = this->capacity;
    LinearDictionary<K, V>* table = this->table;
    this->capacity = 2*cap;
    LinearDictionary<K, V>* newTable = new LinearDictionary<K, V>[this->capacity];
    //vector<pair<K, V>> items = getItems(); ///
    for (int i = 0; i < this->capacity; i++){
        vector<pair<K, V>> dictitems = table[i].getItems();
        int dictsize = table[i].getSize();
        for (int j = 0; j < dictsize; j++){
            int hashindex = hash(dictitems[j].first, this->capacity);
            newTable[hashindex].insert(dictitems[j].first, dictitems[j].second);
        }
    }
    delete[] table;
    this->table = newTable;
    */
    vector<pair<K, V>> items = this->getItems();
    delete[] this->table;
    
    int cap = this->capacity;
    this->capacity = 2*cap;
    this->size = 0;
    this->table = new LinearDictionary<K, V>[this->capacity];
    for (int i=0; i < items.size(); i++){
        this->insert(items[i].first, items[i].second);
    }


}