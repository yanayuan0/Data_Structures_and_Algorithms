/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T> LinkedList<T>::~LinkedList() {
    if (this->size != 0){
        LinkedListNode<T> *temp1, *temp2, *temp;
        temp1 = this->head->next;
        while (temp1 != 0){
            if (temp1->next != 0){
                temp2 = temp1->next;
                delete temp1;
                temp1 = temp2;
            }
            else{
                delete temp1;
                break;
            }
        }
        temp = this->head;
        delete temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T> void LinkedList<T>::checkInvariants() {
    LinkedListNode<T>* current = this->head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    if (count != this->size){
        throw runtime_error("LinkedList's size must match its number of nodes.");
    }

}

template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
    return (this->size == 0);
}

template <typename T> T LinkedList<T>::getFirst() {
    if (this->size == 0){
        throw runtime_error("LinkedList::getFirst list size is 0");
    }
    return this->head->value;
}

template <typename T> T LinkedList<T>::getLast() {
    if (this->size == 0){
        throw runtime_error("LinkedList::getFirst list size is 0");
    }
    return this->tail->value;
}

template <typename T> T LinkedList<T>::get(int index) {
    if(index > this->size-1 || index < 0) {
        throw runtime_error("LinkedList<T>::get Index out of bounds");
    }
    if (this->size == 0){
        throw runtime_error("LinkedList<T>::get list size is 0");
    }

    LinkedListNode<T>* current = this->head;
    int count = 0;
    while (current != nullptr) {
        if (count == index){
            return (current->value);
        }
        count++;
        current = current->next;
    }
    return current->value;
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);
    newNode->next = this->head;
    this->head = newNode;
    if(this->size == 0) {
        this->tail = newNode;
    }
    this->size++;
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);

    if(this->size == 0) {
        this->head = newNode;
    }
    else {
        this->tail->next = newNode;
    }
    this->tail = newNode;
    this->size++;
}

template <typename T> T LinkedList<T>::removeFirst() {
    if (this->size == 0) {
        throw runtime_error("LinkedList::removeFirst size must > 0");
    }
    T val = this->head->value;
    if (this->size == 1) {
        LinkedListNode<T>* temp;
        temp = this->head;
        delete temp;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        LinkedListNode<T>* temp;
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->size--;
    return val;
}

template <typename T> T LinkedList<T>::removeLast() {
    if (this->size == 0) {
        throw runtime_error("LinkedList<T>::removeLast size must >0");
    }
    
    LinkedListNode<T>* listTail = this->tail;
    T tailVal = listTail->value;

    if (this->size == 1) {
        delete listTail;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
    }
    else {
        LinkedListNode<T>* ptr;
        ptr = this->head;
        for(int i = 1; i < size-1; i++){
            ptr = ptr->next;   
        }  
        ptr->next = nullptr;
        delete listTail;
        this->tail = ptr;
        this->size--;
    }   
    return tailVal;
}
