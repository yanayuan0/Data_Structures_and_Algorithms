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
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc != 3){
    cout << "The program takes two command-line arguments." << endl;
    return 1;
  }
  string filename = string(argv[1]);
  string search = string(argv[2]);
  Maze* maze;
  try{
    maze = loadMap(filename);
  } catch(runtime_error e){
    cout << "The program cannot load the map." << endl;
    delete maze;
    return 1;
  }
  List<Position*>* path = nullptr;
  if (search == "depth"){
    List<Position*>* path = maze->solveDepthFirst();
    cout << renderAnswer(maze, path) << endl;
    delete path;
  }
  else if (search == "breadth"){
    List<Position*>* path = maze->solveBreadthFirst();
    cout << renderAnswer(maze, path) << endl;
    delete path;
  }
  else{
    cout << "The program can only provide search type of 'depth' or 'breadth'." << endl;
    delete maze;
    return 1;
  }
  delete maze;
  return 0;
}
