/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "maze.h"
#include "adts/stlList.h"
#include "mazeUtils.h"

using namespace std;

int main() {
  /*
  Maze maze(3, 3);
  cout << maze.getWidth() << endl;
  if (!maze.isWall(2, 2)){
    cout << "no" << endl;
  }

  List<Position*>* list = new STLList<Position*>;
  list = maze.solveBreadthFirst();
  cout << list->getFirst()->getX() << endl;
  cout << list->getFirst()->getY() << endl;
  cout << list->getLast()->getX() << endl;
  cout << list->getLast()->getY() << endl;
  */
  Maze* maze = loadMap("test_data/example1.map");
  List<Position*>* path = maze->solveBreadthFirst();
  //cout << path->getFirst()->getX();
  //cout << path->getFirst()->getY();
  if (path == nullptr){
    cout << "nullptr" << endl;
  }
  cout << renderAnswer(maze, path) << endl;




  return 0;
}
