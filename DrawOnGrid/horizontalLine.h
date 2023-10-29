#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

class HorizontalLine : public Shape{
  private:
    /** the x coordinate of the starting point of the line. */
    int x;
    /** the y coordinate of the starting point of the line. */
    int y;
    /** the length of the line. */
    int length;
    /** the symbol of the line. */
    char s;

  public:
    /**
     * creates a new horizontal line.
     */
    HorizontalLine(int x, int y, int length, char s);
    /**
     * Draws this horizontal line on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    void draw(Grid* grid);
};
