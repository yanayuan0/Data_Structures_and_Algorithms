#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

class Rectangle : public Shape{
  private:
    /** the x coordinate of the top-left point of the rectangle.*/
    int x;
    /** the y coordinate of the top-left point of the rectangle.*/
    int y;
    /** the width of the rectangle. */
    int w;
    /** the height of the rectangle. */
    int h;
    /** the symbol of the rectangle. */
    char s;

  public:
  /**
   * Creates a new rectangle.
   * @param x the x coordinate of the top-left point of the rectangle.
   * @param y the y coordinate of the top-left point of the rectangle.
   * @param w the width of the rectangle.
   * @param h the height of the rectangle.
   * @param s the symbol of the rectangle.
   */
    Rectangle(int x, int y, int w, int h, char s);
    
    /**
     * Draws the rectangle on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    void draw(Grid* grid);
    
};
