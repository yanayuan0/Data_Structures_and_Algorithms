/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "grid.h"
#include "shape.h"
#include "point.h"
#include "horizontalLine.h"
#include "verticalLine.h"
#include "rectangle.h"
#include "picture.h"
#include <iostream>

using namespace std;

int main() {
    // You can put anything you like here.  This file exists so that
    // you can experiment with your code.  For instance, the following
    // might be a useful test after you've written your Point class.

    /*
    Shape* s = new Point(0,0,'x');
    */
    Shape* myShape1 = new HorizontalLine(2, 5, 3, '$');
    /*
    Shape* myShape2 = new VerticalLine(5, 0, 4, '@');
    Shape* myShape3 = new Rectangle(3, 0, 5, 3, 'X');
    */
    Grid* grid = new Grid();
    Picture* pic1 = new Picture();
    pic1->addShape(myShape1);
    cout << pic1->toString() << endl;
    /*
    grid->placeSymbol(19,9,'$');
    grid->placeSymbol(0,0,'%');
  
    s->draw(grid);
    myShape1->draw(grid);
    myShape2->draw(grid);
    myShape3->draw(grid);
    */
    cout << grid->toString() << endl;
    delete grid;
    /*
    delete s;
    delete myShape1;
    delete myShape2;
    delete myShape3;
    */
    delete pic1;



    return 0;
}
