/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"

using namespace std;

Picture::Picture() {
    this -> numberOfShapes = 0; 
    this -> shapes = new Shape*[50];
    /*
    for (int i=0; i < this->numberOfShapes; i++){
        Shape* shapeptr;
        shapeptr = new Shape();
        shapes[i] = shapeptr;
    }
    */ 
}

Picture::~Picture() {
    /******************************/
    for (int i=0; i<this->numberOfShapes; i++){
        delete shapes[i];
    }
    delete[] this -> shapes;

    
}

string Picture::toString() {
    Grid* grid;
    grid = new Grid();
    for (int i=0; i < this->numberOfShapes; i++){
        shapes[i]->draw(grid);
    }
    string s = grid->toString();
    delete grid;
    return s;

}

void Picture::print() {
    cout << this->toString() << endl;
}

void Picture::addShape(Shape* shape) {
    shapes[this->numberOfShapes] = shape;
    this->numberOfShapes ++;
}
