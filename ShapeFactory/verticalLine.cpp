/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "verticalLine.h"

VerticalLine::VerticalLine(int x, int y, int length, char s){
  this->x =x;
  this->y =y;
  this->length =length;
  this->s = s;
}

void VerticalLine::draw(Grid* grid){
  for (int i=0; i<length; i++){
    grid->placeSymbol(x, y+i, s);
  }
}

