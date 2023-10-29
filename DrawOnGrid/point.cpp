/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "point.h"


Point::Point(int x, int y, char s){
  this -> x = x;
  this -> y = y;
  this -> s = s;
}

void Point::draw(Grid* grid){
  grid->placeSymbol(x, y, s);
}

