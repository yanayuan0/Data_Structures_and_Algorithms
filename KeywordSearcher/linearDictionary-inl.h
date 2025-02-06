/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    this->chain = vector<pair<K,V>>();
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    vector<pair<K,V>> vec = this->chain;
    vec.erase(vec.begin(), vec.begin() + vec.size());
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->chain.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    return this->chain.size() == 0;
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    for (int i=0; i<this->chain.size(); i++){
        if (this->chain[i].first == key){
            throw runtime_error("LinearDictionary insert(): can't duplicate keys");
        }
    }
    pair<K,V> pair = std::make_pair(key, value); ///////////
    this->chain.push_back(pair);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    for (int i=0; i<this->chain.size(); i++){
        if (this->chain[i].first == key){
            this->chain[i].second = value;
            return;
        }
    }
    throw runtime_error("LinearDictionary update(): key not found");

}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for (int i=0; i<this->chain.size(); i++){
        if (this->chain[i].first == key){
            return this->chain[i].second;
        }
    }
    throw runtime_error("LinearDictionary get(): key not found");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for (int i=0; i<this->chain.size(); i++){
        if (this->chain[i].first == key){
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    for (int i=0; i<this->chain.size(); i++){
        if (this->chain[i].first == key){
            this->chain.erase(this->chain.begin() + i, this->chain.begin() + i + 1);
            return;
        }
    }
    throw runtime_error("LinearDictionary remove(): key not found");
}


template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> keysvec;
    for (int i=0; i<this->chain.size(); i++){
        keysvec.push_back(this->chain[i].first);
    }
    return keysvec;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    vector<pair<K, V>> copiedvec = this->chain;
    return copiedvec;
}
