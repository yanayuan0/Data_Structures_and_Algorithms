/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
  //throw runtime_error("Not yet implemented: loadMovie");
  ifstream myFile;
  string data;
  int count;

  myFile.open(filename);
  if (!myFile.is_open()){
    throw runtime_error("file " + filename + "failed to open");
  }
  //getline(myFile, data);
  LinkedList<pair<int, string>>* fList = new LinkedList<pair<int, string>>();
  while (!myFile.eof()){
    // process the data in the line here
    getline(myFile, data);
    if (data == ""){
      break;
    }
    count = stoi(data);
    //count = 30; //test value, shouldn't be 30.
    string frame;
    for (int i=0; i<13; i++){
      getline(myFile, data);
      frame = frame + data + "\n";
    }
    pair<int, string> p1(1000000/15*count, frame);
    fList->insertLast(p1);
  }
  
  myFile.close();
  return fList;
}

void playMovie(List<pair<int, string>>* frames){
  int size = frames->getSize();
  for (int i=0; i < size; i++){
    pair<int, string> frame = frames->removeFirst();
    cout << frame.second << endl;
    usleep(frame.first);
    system("clear");
    frames->insertLast(frame);
  }

}



