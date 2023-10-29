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

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {
  bool reversed = false;
  

  string fileName;
  if (argc == 2){
    fileName = string(argv[1]);
  }
  else if(argc == 3){
    if (string(argv[1]) != "--reverse"){
      cout << "Invalid command-line arguments" << endl;
      throw runtime_error("Usage: ./asciimation --reverse <fileName>");
      return 1;
    }
    fileName = string(argv[2]);
    reversed = true;
  }
  else {
    cout << "Invalid command-line arguments" << endl;
    throw runtime_error("Usage: ./asciimation (--reverse) <fileName>");
    return 1;
  }


  List<pair<int, string>>* frames = loadMovie(fileName);
  
  if (frames->getSize() == 0) {
    cout << "No frames available to load or play." << endl;
    return 1;
  }

  if (reversed) {
    List<pair<int, string>>* reversedFrames = new LinkedList<pair<int, string>>(); 
    int size = frames->getSize();
    for (int i=0; i < size; i++){
      reversedFrames->insertFirst(frames->removeFirst());
    }

    playMovie(reversedFrames);
    delete reversedFrames;
  }
  else {
    playMovie(frames);
  }
  
  delete frames;
  return 0;

}


    
