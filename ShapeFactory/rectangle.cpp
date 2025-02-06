/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "rectangle.h"
#include "horizontalLine.h"

Rectangle::Rectangle(int x, int y, int w, int h, char s){
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->s = s;
}

void Rectangle::draw(Grid* grid){
  for (int i=0; i<h; i++){
    HorizontalLine(x, y+i, w, s).draw(grid);
  }
}

