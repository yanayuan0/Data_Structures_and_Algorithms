/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <vector>

#include "keywordSearcher.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc != 2){
    throw runtime_error("usage: ./keywordSearch <filename>");
  }
  string fileName = argv[1];
  vector<pair<int, int>> ten;
  KeywordSearcher ks;
  try{
    ks.loadWords(fileName);
  } catch (runtime_error e){
    cout << "unable to open file " << fileName << endl;
    return 1;
  } 
  string word;
  cout << "File loaded.\n" << endl;
  cout << "Please enter a search word or '!' to quit: ";
  cin >> word;
  while (word != "!"){
    ten = ks.search(word);
    if (ten.size() == 0){
      cout << "The word " << word << " does not appear in the file." << endl;
    } else{
      cout << "The word " << word << " appears in the file..." << endl;
      for (int i=0; i<ten.size(); i++){
      cout << "    on page " << ten[i].first << " (" << ten[i].second << " occurences)" << endl;
      }
    }
    cout << "\nPlease enter a search word or '!' to quit: ";
    cin >> word;
  }
  cout << "\nGoodbye!\n" << endl;
  return 0;
}
