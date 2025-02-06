/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "keywordSearcher.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include "adts/stlMaxPriorityQueue.h"

using namespace std;

KeywordSearcher::KeywordSearcher() {
    //this->subHashTable = new HashTable<int, int>();
    this->table = new HashTable<string, HashTable<int, int>*>();
}

KeywordSearcher::~KeywordSearcher() {
    vector<string> keys = this->table->getKeys();
    for (int i=0; i<this->table->getSize(); i++){
        HashTable<int, int>* subTable = this->table->get(keys[i]);
        delete subTable;
    }
    delete this->table;
}


void KeywordSearcher::loadWords(string filename) {
    /*
    1. In large dictionary (key already exist)
        a. not on this page (new subtable)
        b. on this page (update)
    2. Not in large dictionary (create new large dictionary and new subtable)
    */

    ifstream myFile;
    string word;
    int page;
    HashTable<int, int>* subTable;

    myFile.open(filename);
    if (!myFile.is_open()){
        throw runtime_error("KeywordSearcer: could not open file: " + filename);
    }
    while (!myFile.eof()){
        myFile >> word;
        if (word == "$$@@$$PAGE:"){
            myFile >> word;
            page = stoi(word);
        } else{
            if (this->table->contains(word)){ // case 1
                subTable = this->table->get(word);
                if (subTable->contains(page)){ //case 1b
                    int value = subTable->get(page);
                    subTable->update(page, value + 1);
                } else{ //case 1a
                    subTable->insert(page, 1);
                }
            } else{ //case 2
                subTable = new HashTable<int, int>();
                subTable->insert(page, 1);
                this->table->insert(word, subTable);
            } 
        }
    }
    myFile.close();
}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int, int>> vectorToReturn;
    if (!this->table->contains(word)){
        return vectorToReturn;
    } else{
        HashTable<int, int>* subTable = this->table->get(word);
        vector<pair<int, int>> items = subTable->getItems();
        //cout << items.size() << endl;
        STLMaxPriorityQueue<int, int>* priorityQueue = new STLMaxPriorityQueue<int, int>();
        for (int i=0; i<items.size(); i++){
            priorityQueue->insert(items[i].second, items[i].first);
        }
        int size = priorityQueue->getSize();
        if (size > 10){
            size = 10;
        }
        for (int i=0; i<size; i++){
            int occurrences = priorityQueue->peekPriority();
            int page = priorityQueue->remove();
            vectorToReturn.push_back(make_pair(page, occurrences));
        }
        delete priorityQueue;
    } 
    return vectorToReturn;
}
