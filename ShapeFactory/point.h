#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

class Point : public Shape{
  private:
    /** the x coordinate of the point. */
    int x;
    /** the y coordinate of the point. */
    int y;
    /** the symbol of the point. */
    char s;

  public:
  /**
   * Creates a new point.
   * @param x the x coordinate of the point.
   * @param y the y coordinate of the point.
   * @param s the symbol of the point.
   */
    Point(int x, int y, char s);

    /**
     * Draws the point on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    void draw(Grid* grid);


};
