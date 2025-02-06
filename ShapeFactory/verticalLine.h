#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

class VerticalLine : public Shape{
  private:
    /** the x coordinate of the starting point of the vertical line. */
    int x;
    /** the y coordinate of the starting point of the vertical line. */
    int y;
    /** the length of the vertical line. */
    int length;
    /** the symbol of the vertical line. */
    char s;

  public:
    /**
     * creates a new vertical line.
     */
    VerticalLine(int x, int y, int length, char s);
    /**
     * Draws this vertical line on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    void draw(Grid* grid);

};
