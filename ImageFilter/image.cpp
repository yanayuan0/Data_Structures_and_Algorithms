/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
  return (width * 3 * y + x * 3); 
}

void noRed(int width, int height, int* ppm) {
  int n = width * height * 3 ;
  for (int i=0; i<n; i=i+3){
    ppm[i] = 0;
  }
}

void noGreen(int width, int height, int* ppm) {
  int n = width * height * 3 ;
  for (int i=1; i<n; i=i+3){
    ppm[i] = 0;
  }
}

void noBlue(int width, int height, int* ppm) {
  int n = width * height * 3 ;
  for (int i=2; i<n; i=i+3){
    ppm[i] = 0;
  }
}

void invert(int width, int height, int* ppm) {
  int n = width * height * 3 ;
  for (int i=0; i<n; i++){
    ppm[i] = 255 - ppm[i];
  }
}

void grayscale(int width, int height, int* ppm){
  int n = width * height * 3;
  for (int i=0; i<n; i=i+3){
    float avg = (ppm[i] + ppm[i+1] + ppm[i+2]) / 3;
    ppm[i] = avg;
    ppm[i+1] = avg;
    ppm[i+2] = avg;
  }
}

void flipHorizontally(int width, int height, int* ppm){
  int n = width * height * 3;  
  int nppm[n];
  for (int i=0; i<n; i++){
    nppm[i] = ppm[i];
  }
  
  for (int y=0; y<height; y++){
    for (int x=0; x<width; x++){
      int index = pixelToIndex(width, x, y);
      int flipi = pixelToIndex(width, width-x-1, y);
      ppm[index] = nppm[flipi];
      ppm[index + 1] = nppm[flipi + 1];
      ppm[index + 2] = nppm[flipi + 2];
    }
  }                                                                                                                            
}


void flipVertically(int width, int height, int* ppm){
  int n = width * height * 3;  
  int nppm[n];
  for (int i=0; i<n; i++){
    nppm[i] = ppm[i];
  }
  
  for (int x=0; x<width; x++){
    for (int y=0; y<height; y++){
      int index = pixelToIndex(width, x, y);
      int flipi = pixelToIndex(width, x, height-y-1);
      ppm[index] = nppm[flipi];
      ppm[index + 1] = nppm[flipi + 1];
      ppm[index + 2] = nppm[flipi + 2];
    }
  }                                                                                                                            
}
