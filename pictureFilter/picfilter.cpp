/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO: write your main program here
    // Remember:
    //   * The first command-line argument in argv is always the name of the
    //     program.
    //   * You can convert from char* to string just by assignment:
    //         string infile = argv[1];
    //   * You should have code that deals with the case that your
    //     user gave you too few or too many command-line arguments.
    // Good luck!  Remember to ask for help!

    if (argc != 4){
      cout << "Invalid command-line arguments" << endl;
      cout << "Usage: ./commandline <old_fileName> <transformation> <new_fileName>" << endl;
      return 1;
    }
    
    string ofileName = argv[1];
    string transf = argv[2];
    string nfileName = argv[3];

    int* ppm = read_ppm(ofileName);
    int width = ppm_width(ofileName);
    int height = ppm_height(ofileName);
    
    if (transf == "noRed"){
      noRed(width, height, ppm);
    }
    if (transf == "noGreen"){
      noGreen(width, height, ppm);
    }
    if (transf == "noBlue"){
      noBlue(width, height, ppm);
    }
    if (transf == "invert"){
      invert(width, height, ppm);
    }
    if (transf == "grayscale"){
      grayscale(width, height, ppm);
    }
    if (transf == "flipHorizontally"){
      flipHorizontally(width, height, ppm);
    }
    if (transf == "flipVertically"){
      flipVertically(width, height, ppm);
    }
    write_ppm(nfileName, width, height, ppm);


    return 0;
}
