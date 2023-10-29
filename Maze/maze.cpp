/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
  if (width<0 || height<0){
    throw runtime_error("Maze::Maze() data members out of bounds");
  }
  this->width = width;
  this->height = height;
  this->positions= new Position**[width];
  for (int i = 0; i < width; i++) {
    this->positions[i] = new Position*[height];
    for (int j = 0; j < height; j++) {
      this->positions[i][j] = new Position(i,j);
    }
  }
}

Maze::~Maze() {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      delete positions[i][j];
    }
    delete[] positions[i];
  }
  delete[] positions;
}

int Maze::getWidth() {
  return this->width;
}

int Maze::getHeight() {
  return this->height;
}

bool Maze::isWall(int x, int y) {
  return (this->positions[x][y]->isWall());

}

void Maze::setWall(int x, int y) {
  this->positions[x][y]->setWall();
}

List<Position*>* Maze::getNeighbors(Position* position) {
  //throw runtime_error("Not yet implemented: Maze::getNeighbors");
  //Position* current-> positions[0][0];
  //List<Position*>* = solve();
  //while ()
  int x = position->getX();
  int y = position->getY();
  if (x<0 || x>this->getWidth() || y<0 || y>this->getHeight()){
    throw runtime_error("Maze::getNeighbors position out of bounds");
  }
  List<Position*>* list = new STLList<Position*>();
  if (x>0 && x<width){
    Position* left = this->positions[x-1][y];
    if (left->isWall()==false){
      list->insertFirst(left);
    }
  }
  if (y>0 && y<height){
    Position* up = this->positions[x][y-1];
    if (up->isWall()==false){
      list->insertFirst(up);
    }
  }
  if (x<width-1 && x>=0){
    Position* right = this->positions[x+1][y];
    if (right->isWall()==false){
      list->insertFirst(right);
    }
  }
  if (y<height-1 && y>=0){
    Position* down = this->positions[x][y+1];
    if (down->isWall()==false){
      list->insertFirst(down);
    }
  }
  return list;

}

List<Position*>* Maze::solveBreadthFirst() {
  //below is used to test manualtests, not for solveBreadthFirst
  //Position* pos = new Position(-1, 0);
  //List<Position*>* list = getNeighbors(pos);
  //return list;

  OrderedCollection<Position*>* queue = new LinkedQueue<Position*>();
  List<Position*>* path = solve(queue);
  delete queue;
  return path;
}

List<Position*>* Maze::solveDepthFirst() {
  OrderedCollection<Position*>* stack = new LinkedStack<Position*>();
  List<Position*>* path = solve(stack);
  delete stack;
  return path;
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  Position* startpos = positions[0][0];
  Position* goal = positions[width-1][height-1];
  List<Position*>* path = new STLList<Position*>;
  exploration->insert(startpos);
  while (exploration->isEmpty() == false){
    Position* current = exploration->remove();
    if (current->isVisited() == true){
      continue;
    }
    current->setVisited();
    if (current == goal){
      break;
    }
    List<Position*>* lst;
    lst = this->getNeighbors(current);
    int size = lst->getSize();
    for (int i=0; i<size; i++){
      Position* neighbor = lst->removeLast();
      if (neighbor->isVisited() == false){
        if (neighbor->getPrevious() == nullptr){
          neighbor->setPrevious(current);
        }
        exploration->insert(neighbor);
        //delete neighbor;
      }
    }  delete lst;
  }
  //delete lst;
  if (goal->isVisited()){
    Position* cur = goal;
    while (cur != startpos && cur->isVisited()){
      path->insertFirst(cur);
      cur = cur->getPrevious();
    }
    path->insertFirst(startpos);
    return path;
  }
  else{
    return nullptr;
  }
}
